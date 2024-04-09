#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("C:/Users/User/Desktop/test1.jpeg");

    if (image.empty())
    {
        cout << "Error" << endl;
        return -1;
    }

    imshow("Original Image", image);
    waitKey(0);
    
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    imshow("Grey Image", grayImage);
    waitKey(0);

    Mat gaussImage;
    GaussianBlur(grayImage, gaussImage, Size(5, 5), 0);
    imshow("Gauss Image", gaussImage);
    waitKey(0);

    Mat contourImage;
    Canny(grayImage, contourImage, 50, 200);
    imshow("Contour Image", contourImage);
    waitKey(0);

    vector<Vec4i> lines;
    HoughLinesP(contourImage, lines, 1, CV_PI / 180, 150, 10, 250);

    for (size_t i = 0; i < lines.size(); i++)
    {
        line(image, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 255, 0), 1, LINE_AA);
    }

    vector<Vec3f> circles;
    HoughCircles(contourImage, circles, HOUGH_GRADIENT, 1, 750, 200, 10, 10, 100);

    for (size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(image, center, radius, Scalar(255, 255, 255), 2, 8, 0);
    }

    imshow("Final Image", image);
    waitKey(0);

    return 0;
}



