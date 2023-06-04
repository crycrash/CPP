#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void equalMatrixElements::input() {
    ifstream inputFile(fileNameInput);
    string line;
    int rows = 0, cols = 0;
    while(getline(inputFile, line)){
        std::vector<int> row;
        int x;
        std::istringstream ss(line);
        while (ss >> x) {
            row.push_back(x);
        }
        if (cols == 0) {
            cols = row.size();
        }
        matrix.push_back(row);
        rows++;
    }
    inputFile.close();
}

equalMatrixElements::equalMatrixElements(string fileInput, string fileOutput, vector<vector<int> > matrixName) {
    fileNameInput = fileInput;
    fileNameOutput = fileOutput;
    matrix = matrixName;
}

void equalMatrixElements::counter() {
    int count = 0;
    for(int i = 0;i < matrix.size();i++){
        int j = 0;
        while(j < matrix[0].size()){
            if (j < i)
                j++;
            else if(i == j){
                j++;
                count++;
            }else{
                if(matrix[i][j] == matrix[j][i]){
                    count += 2;
                }
                j++;
            }
        }
    }
    cout << count;
}

void equalMatrixElements::writer() {
    ofstream outFile(fileNameOutput);
    for(int i = 0;i < matrix.size();i++){
        int j = 0;
        while(j < matrix[0].size()){
            if (j < i)
                j++;
            else if(i == j){
                j++;
                outFile << "[" << i << "," << j - 1 << "]" << endl;
            }else{
                if(matrix[i][j] == matrix[j][i]){
                    outFile << "[" << i << "," << j << "]" << endl;
                    outFile << "[" << j << "," << i << "]" << endl;
                }
                j++;
            }
        }
    }
}