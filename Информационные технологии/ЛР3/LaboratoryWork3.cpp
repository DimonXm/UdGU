#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main()
{
    Mat HSVImage, outIsRangeImage, img;
    img = imread("image3.jpg"); // Считываем изображени
    int hMin = 9, hMax = 26; // Получаем из кода мамрыкина данные об HSV на картинке
    int sMin = 158, sMax = 255;
    int vMin = 226, vMax = 255;

    cvtColor(img, HSVImage, COLOR_BGR2HSV); // Переводим изображение в hsv формат 
    inRange(HSVImage, Scalar(hMin, sMin, vMin), Scalar(hMax, sMax, vMax), outIsRangeImage); // Применяем фильтр черно белого диапозона чтобы осталось видно только желтый цвет на светофоре

    Moments m = moments(outIsRangeImage, true); // Определяем координаты центра отфильтрованного обьекта
    double centerX = m.m10 / m.m00, centerY = m.m01 / m.m00;
    circle(img, Point(centerX, centerY), 10, Scalar(0, 0, 255), -1); // Рисуем по центру оркужность радиусом 10
 
    string textImg = "X: " + to_string((int)centerX) + " Y: " + to_string((int)centerY); // Строка для вывода 
    putText(img, textImg, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 0), 2);

    imshow("Окно", outIsRangeImage); // Отображаем окно
    waitKey();
}
