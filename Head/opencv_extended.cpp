#include "./opencv_extended.h"
#include<array>
#include<list>

namespace cvex
{

	using cv::Mat;
	using cv::MatND;
	using cv::Rect;
	using cv::RotatedRect;
	using cv::Vec4i;
	using cv::Scalar;
	using cv::Point;

	using cv::imshow;
	using cv::waitKey;

	using std::vector;
	void showHist(const Mat img)
	{
		Mat hist;
		int histSize = 256;
		cv::calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, 0);//calculate histogram

		Mat histImage = Mat::ones(200, 320, CV_8U) * 255;

		normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);//normalize histogram

		histImage = Scalar::all(255);
		int binW = cvRound((double)histImage.cols / histSize);//bin width

		for (int i = 0; i < histSize; i++)//draw histogram chart
			rectangle(histImage, Point(i * binW, histImage.rows),
				Point((i + 1) * binW, histImage.rows - cvRound(hist.at<float>(i))),
				Scalar::all(0), -1, 8, 0);
		imshow("histogram", histImage);
		waitKey();
	}

	
	void rotatedRectangle(Mat& img, const RotatedRect& rec, const Scalar& color)
	{
		if (&rec == nullptr) return;
		cv::Point2f rect_points[4];//4 points of the rectangle
		rec.points(rect_points);
		for (int j = 0; j < 4; j++)
		{
			line(img, rect_points[j], rect_points[(j + 1) % 4], color);//draw 4 edges of the rectangle
		}
	}

}
