#pragma once
#include <iostream>

class ArrayList{
public:
    ArrayList();
    ~ArrayList();
    void Print() const;
    void Append(int element);//Добавление элемента в массив
    int Get(int index) const;
    bool InsertAt(int element, int index);//Добавление элемента в определенный индекс
    bool DeleteAt(int index);//Удаление элемента по индексу
    int operator[](int index);
private:
    int* pData;
    int size;//Размер текущий
    int capacity;//Вместимость общая
    int growFactor;//Во сколько раз увеличивается вместимость
    void Resize();//Функция увелечения вместимости массива
    void Copy(int* pTemp);//Если мы увеличиваем массив, то мы должны данные с прошлого
    // массива скопировать в новый
};