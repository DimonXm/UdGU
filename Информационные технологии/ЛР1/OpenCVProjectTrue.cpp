//#include <oistream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

int main()
{
    setlocale(LC_ALL, "");
    Mat img = imread("cats.png", IMREAD_COLOR);

    // Считываем координаты
    Rect cordImageForFace1(66, 142, 154, 100);
    Rect cordImageForFace2(270, 218, 120,75);
    Rect cordImageForFace3(435, 174, 120, 90);

    // Создаем изображения
    Mat face1 = img(cordImageForFace1);
    Mat face2 = img(cordImageForFace2);
    Mat face3 = img(cordImageForFace3);
    Mat faceGray, faceGray2, biLevel;

    // Преобразовываем изображения
    cvtColor(face2, faceGray, COLOR_BGR2GRAY);
    cvtColor(face3, faceGray2, COLOR_BGR2GRAY);
    threshold(faceGray2, biLevel, 220, 255, THRESH_OTSU);

    // Масштаб для увеличения
    double scale = 2.00;
    Mat resized_face1, resized_face2, resized_face3;

    // Увеличиваем картинки
    resize(face1, resized_face1, Size(), scale, scale, INTER_LINEAR);
    resize(faceGray, resized_face2, Size(), scale, scale, INTER_LINEAR);
    resize(biLevel, resized_face3, Size(), scale, scale, INTER_LINEAR);

    // Создаем окна для увеличения
    namedWindow("ЦветноеЛицо", WINDOW_NORMAL);
    namedWindow("СероеЛицо", WINDOW_NORMAL);
    namedWindow("ЧерноБелоеЛицо", WINDOW_NORMAL);

    // Увеличиваем окна
    resizeWindow("ЦветноеЛицо", resized_face1.cols, resized_face1.rows);
    resizeWindow("СероеЛицо", resized_face2.cols, resized_face2.rows);
    resizeWindow("ЧерноБелоеЛицо", resized_face3.cols, resized_face3.rows);

    // Отображаем результат
    imshow("ЦветноеЛицо", resized_face1);
    imshow("СероеЛицо", resized_face2);
    imshow("ЧерноБелоеЛицо", resized_face3);

    // Сохраняем файлы
    imwrite("Цветное лицо.jpeg", resized_face1);
    imwrite("Серое лицо.jpeg", resized_face2);
    imwrite("Черно-белое лицо.jpeg", resized_face3);

    waitKey();
    destroyAllWindows();
}