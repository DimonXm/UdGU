
#include <iostream>
using namespace std;

class MyList
{
    int* array = nullptr;
    int count = 0;
    int size;

    void Enlarge()
    {
        throw runtime_error("Method was not implemented.");
    }

public:
    MyList() : array(new int[100]), count(0), size(100) {} // Конструктор инициализации

    MyList(const MyList &other) : count(other.count), size(other.size) { // Конструктор копирования
        array = new int[size]; // Создаем новый массив и заполняем его, таким образом получается что для каждого обьекта есть свой собственный массив
        for (int i = 0; i < count; i++) {
            array[i] = other.array[i];
        }
    }

    virtual ~MyList()
    {
        delete[] array;
        array = nullptr;
    }

    void Add(int value)
    {
        if (count == size)
            Enlarge();
        array[count++] = value;
    }

    int& operator[] (int index)
    {
        if (index < 0 || index >= count)
            throw out_of_range("Index out of range.");
        return array[index];
    }

    int Length() const { return count; }
};

int main()
{
    MyList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list[1] = 100;
    MyList list1 = list;
    list1[1] = 200;

    for (int i = 0; i < list.Length(); i++)
        cout << list[i] << "\n";
    cout << "----\n";

    for (int i = 0; i < list1.Length(); i++)
        cout << list1[i] << "\n";
}

