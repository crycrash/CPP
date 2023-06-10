#include "fromMatrixToList.h"
#include <iostream>
#include <vector>
#include <fstream>//Не ври, Она используется

using namespace std;

toList::toList(std::ifstream &file) : height(), width() {
    file >> height >> width;
    char c;
    int i = 0;
    while (file.get(c) && i < width) {
        if (!::isspace(c)) {
            names.push_back(c);
            i++;
        }
    }
    matrix = new int* [height];
    for (int j = 0;j < height;j++){
        matrix[j] = new int [width];
        for (int l = 0;l < width;l++){
            file >> matrix[j][l];
        }
    }
}
void toList::out() {
    cout << height << " " << width << endl;
    for (int i = 0;i < height;i++){
        for (int j = 0;j < width;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void toList::list(std::ofstream &file) {
    for (int i = 0;i < width;i++){
        file << names[i] << ": ";
        for(int j = 0;j < height;j++){
            if (matrix[j][i] != 0){
                file << j + 1 << " ";
            }
        }
        file << endl;
    }
}