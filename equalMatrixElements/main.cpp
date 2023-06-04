#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    vector<vector<int> > matrixName;
    equalMatrixElements check("/Users/milana/Desktop/input.txt", "/Users/milana/Desktop/output.txt", matrixName);
    check.input();
    check.writer();
}