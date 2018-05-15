#include <opencv2\opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>
#include <iostream>

int main(int argc, char argv[]) {
	double time_count = (double)cv::getTickCount();
	std::string input_path = "E:/Test_data/Blancetest.jpg";
	std::string output_path = "E:/Test_data";
	std::vector<cv::Mat> RGB;
	std::vector<cv::Mat> HSV;
	cv::Mat Src_img = cv::imread(input_path);
	cv::Mat Gray_img, Lab_img, Hsv_img;
	cv::Mat R, G, B;
	cv::Mat H, S, V;
	cv::Mat newRGB, newHSV;
	cv::namedWindow("SRC");
	cv::imshow("SRC", Src_img);

	cv::cvtColor(Src_img, Gray_img, CV_RGB2GRAY);
	cv::namedWindow("GRAY");
	cv::imshow("GRAY", Gray_img);

	cv::cvtColor(Src_img, Lab_img, CV_BGR2Lab);
	cv::namedWindow("LAB");
	cv::imshow("LAB", Lab_img);

	cv::cvtColor(Src_img, Hsv_img, CV_BGR2HSV);
	cv::namedWindow("HSV");
	cv::imshow("HSV", Hsv_img);

	cv::split(Src_img, RGB);
	B = RGB.at(0);
	G = RGB.at(1);
	R = RGB.at(2);
	cv::imshow("r", R);
	cv::imshow("g", G);
	cv::imshow("b", B);

	cv::split(Hsv_img, HSV);
	H = HSV.at(0);
	S = HSV.at(1);
	V = HSV.at(2);
	cv::imshow("h", H);
	cv::imshow("s", S);
	cv::imshow("v", V);

	cv::merge(RGB, newRGB);
	cv::imshow("newrgb", newRGB);
	cv::merge(HSV, newHSV);
	cv::imshow("newhsv", newHSV);

	//cv::imwrite("E:/Test_data/out.jpg", Src_img);//write will compress
	double alltime = ((double)cv::getTickCount() - time_count) / cv::getTickFrequency();
	std::cout << "ÏûºÄÊ±¼ä£º" << alltime << std::endl;
	cv::waitKey(0);
	return 0;
}