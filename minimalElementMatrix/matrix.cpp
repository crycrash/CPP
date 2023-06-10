#include "matrix.h"
#include <iostream>
#include <map>

using namespace std;

ListMatrix::ListMatrix(ifstream& file) {
    Matrix* ptr = new Matrix;

    file >> ptr->height >> ptr->width;
    ptr->matrix = new int* [ptr->height];
    for (int i = 0; i < ptr->height; i++) {
        ptr->matrix[i] = new int[ptr->width];
    }

    for (int i = 0; i < ptr->height; i++) {
        for (int j = 0; j < ptr->width; j++) {
            file >> ptr->matrix[i][j];
        }
    }

    begin = ptr;

    while (!file.eof()) {
        Matrix* th = new Matrix;

        file >> th->height >> th->width;
        th->matrix = new int* [th->height];
        for (int i = 0; i < th->height; i++) {
            th->matrix[i] = new int[th->width];
        }

        for (int i = 0; i < th->height; i++) {
            for (int j = 0; j < th->width; j++) {
                file >> th->matrix[i][j];
            }
        }

        ptr->next = th;
        ptr = th;
    }
}
void ListMatrix::out() const{
    if (begin){
        int i = 1;
        for (Matrix* ptr = begin;ptr;ptr = ptr->next){
            cout << i << ": " << endl;
            for (int j = 0;j < ptr->width;j++){
                for(int l = 0;l < ptr->height;l++){
                    cout << ptr->matrix[j][l] << " ";
                }
                cout << endl;
            }
            i++;
        }
    }
}

void ListMatrix::findMinimal(std::ofstream &file) const {
    for(Matrix* ptr = begin; ptr != nullptr; ptr = ptr->next) {
        int minHeight = INT_MIN;
        int maxHeightIndex = -1;
        int maxWidthIndex = -1;

        for(int i = 0; i < ptr->height; i++) {
            int minHeightRowIndex = -1;
            int minHeightValue = INT_MAX;

            for(int j = 0; j < ptr->width; j++) {
                if(ptr->matrix[i][j] < minHeightValue) {
                    minHeightRowIndex = j;
                    minHeightValue = ptr->matrix[i][j];
                }
            }

            if(minHeightValue > minHeight) {
                minHeight = minHeightValue;
                maxHeightIndex = i;
                maxWidthIndex = minHeightRowIndex;
            }
        }

        if(maxHeightIndex >= 0) {
            file << "index:" << maxHeightIndex << " " << maxWidthIndex << " value: " << minHeight << std::endl;
        }
    }

}