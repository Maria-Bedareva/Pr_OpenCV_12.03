#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("C:/Users/User/Desktop/home.jpg");

    if (image.empty())
    {
        cout << "Error" << endl;
        return -1;
    }

    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    waitKey(0);

    Mat hsvImage, labImage, yuvImage, xyzImage, grayImage;

    cvtColor(image, hsvImage, COLOR_BGR2HSV);
    namedWindow("HSV Image", WINDOW_AUTOSIZE);
    imshow("HSV Image", hsvImage);
    waitKey(0);

    cvtColor(image, labImage, COLOR_BGR2Lab);
    namedWindow("Lab Image", WINDOW_AUTOSIZE);
    imshow("Lab Image", labImage);
    waitKey(0);

    cvtColor(image, yuvImage, COLOR_BGR2YUV);
    namedWindow("YUV Image", WINDOW_AUTOSIZE);
    imshow("YUV Image", yuvImage);
    waitKey(0);

    cvtColor(image, xyzImage, COLOR_BGR2XYZ);
    namedWindow("XYZ Image", WINDOW_AUTOSIZE);
    imshow("XYZ Image", xyzImage);
    waitKey(0);

    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    namedWindow("GRAY Image", WINDOW_AUTOSIZE);
    imshow("GRAY Image", grayImage);

    waitKey(0);

    return 0;
}