#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main()
{
    setlocale(LC_ALL, "");
    Mat img,img2, medianImg, gaussImg, bilat, box;
    //img = imread("image.jpg");
    img = imread("12.jpg");
    if (!img.empty())
    {
        imshow("Оригинал", img); // 3,4,5,9
        GaussianBlur(img, gaussImg, Size(9, 9), 0);
        medianBlur(img, medianImg, 7); // 2,6 (medianBlur(img, medianImg, 11)), 7, 11 (medianBlur(img, medianImg, 25)), 12
        bilateralFilter(img, bilat, 3, 150, 150);
        //imwrite("medianImg.jpg", bilat); // сохраняем измененное изображение
        //img2 = imread("medianImg.jpg"); // считываем его в переменную
        boxFilter(img2, box,0, Size(3, 3)); // 8, 12
        imshow("Двусторонний фильтр", bilat);
        imshow("Медианный фильтр", medianImg);
        imshow("Фильтр гаусса", gaussImg); // 10
        imshow("Фильтр Box", box); 
        waitKey();
    }
    else
        cout << "Файл изображения не найден!!!";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
