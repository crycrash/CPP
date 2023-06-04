#include "array.h"
#include <iostream>

ArrayList::ArrayList() {
    size = 0;
    growFactor = 2;
    capacity = 4;
    pData = new int[capacity];
}
ArrayList::~ArrayList() {
    delete[] pData;
}
void ArrayList::Resize() {
    capacity *= growFactor;
    int* pTemp = new int [capacity];
    Copy(pTemp);
    delete[] pData;
    pData = pTemp;
}
void ArrayList::Copy(int *pTemp) {
    for (int i=0;i<size;i++)//O(N)
        pTemp[i] = pData[i];
}
int ArrayList::operator[](int index) {
    return Get(index);
}
int ArrayList::Get(int index) const {
    if(index < 0 || index >= size)
        return -1;
    return pData[index];
}
void ArrayList::Append(int element) {
    if (size==capacity)
        Resize();
    pData[size++] = element;
}
bool ArrayList::InsertAt(int element, int index) {
    if (index < 0 or index >= size)
        return false;
    if (size==capacity)
        Resize();
    for (int i = size; i>index ;i--){
        pData[i] = pData[i-1];
    }
    ++size;
    pData[index] = element;
    return true;
}
bool ArrayList::DeleteAt(int index){//Сложность O(N)
    if (index < 0 or index >= size)
        return false;
    if (size==capacity)
        Resize();
    for (int i = index; i< size - 1 ;++i){
        pData[i] = pData[i+1];
    }
    --size;
    return true;
}
void ArrayList::Print() const{
    for (int i=0;i<size;i++){
        std::cout<<pData[i]<<" ";
    }
    std::cout<<"\n";
}