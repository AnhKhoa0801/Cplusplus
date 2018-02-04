//// ImageAndVideoProcessing.cpp : Defines the entry point for the console application.
////
//
//#include <SDKDDKVer.h>
//#include <stdio.h>
//#include <tchar.h>
//#include <iostream>
//#include <string>
//#include "opencv2\core\core.hpp"
//#include "opencv2\highgui\highgui.hpp"
//using namespace cv;
//using namespace std;
//
//void loadAndShowImage(const char* fname)
//{
//	Mat img;
//	img = imread(fname, IMREAD_COLOR); ///// Read the file
//	if (img.empty() == true)
//	{
//		std::cout << "Cannot load image" << std::endl;
//		return;
//	}
//	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display window", img);                // Show our image inside it.
//
//	waitKey(0); // Wait for a keystroke in the window
//}
//void splitChannelsInImage(const char*fname)
//{
//	Mat img;
//	img = imread(fname, IMREAD_COLOR); ///// Read the file
//	if (img.empty() == true)
//	{
//		std::cout << "Cannot load image" << std::endl;
//		return;
//	}
//	std::vector < Mat> channel;
//	split(img, channel);
//	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display window", img);                // Show our image inside it.
//	namedWindow("Display Red", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display Red", channel[2]);
//	namedWindow("Display Green", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display Green", channel[1]);
//	namedWindow("Display Blue", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display Blue", channel[0]);
//	waitKey(0); // Wait for a keystroke in the window
//}
//void splitChannelsInColorImage(const char*fname)
//{
//	Mat img;
//	img = imread(fname, IMREAD_COLOR); ///// Read the file
//	if (img.empty() == true)
//	{
//		std::cout << "Cannot load image" << std::endl;
//		return;
//	}
//	Mat redChannel = Mat::zeros(img.rows, img.cols, CV_8UC3);
//	Mat greenChannel = Mat::zeros(img.rows, img.cols, CV_8UC3);
//	Mat blueChannel = Mat::zeros(img.rows, img.cols, CV_8UC3);
//	for (int i = 0; i < img.rows; i++)
//	{
//		for (int j = 0; j < img.cols; j++)
//		{
//			redChannel.at<Vec3b>(i, j)[2] = img.at<Vec3b>(i, j)[2];
//			greenChannel.at<Vec3b>(i, j)[1] = img.at<Vec3b>(i, j)[1];
//			blueChannel.at<Vec3b>(i, j)[0] = img.at<Vec3b>(i, j)[0];
//		}
//	}
//	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display window", img);                // Show our image inside it.
//	namedWindow("Display Red", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display Red", redChannel);
//	namedWindow("Display Green", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display Green", greenChannel);
//	namedWindow("Display Blue", WINDOW_AUTOSIZE); // Create a window for display.
//	imshow("Display Blue", blueChannel);
//	waitKey(0); // Wait for a keystroke in the window
//}
//
//
//
//int main()
//{
//	loadAndShowImage("C:\\Users\\Admin\\Desktop\\1.jpeg");
//	//splitChannelsInImage("C:\\Users\\VietVo\\Documents\\DIP-PIIT\\lena.jpg");
//	//splitChannelsInColorImage("C:\\Users\\VietVo\\Documents\\DIP-PIIT\\lena.jpg");
//	system("pause");
//	return 0;
//}
//