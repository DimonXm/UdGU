#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;

int main()
{
    Mat HSVImage, outIsRangeImage, img;
    img = imread("variant9.jpg"); // Считываем изображени
    int hMin = 9, hMax = 26; // Получаем из кода мамрыкина данные об HSV на картинке
    int sMin = 158, sMax = 255;
    int vMin = 226, vMax = 255;

    cvtColor(img, HSVImage, COLOR_BGR2HSV);
    inRange(HSVImage, Scalar(hMin, sMin, vMin), Scalar(hMax, sMax, vMax), outIsRangeImage);

    Moments m = moments(outIsRangeImage, true);

    double centerX = m.m10 / m.m00, centerY = m.m01 / m.m00;
    circle(img, Point(centerX, centerY), 10, Scalar(0, 0, 255), -1);

    imshow("Окно", img);
    waitKey();
}
