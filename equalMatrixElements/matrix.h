#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class equalMatrixElements{
private:
    string fileNameInput;
    string fileNameOutput;
    vector<vector<int> > matrix;
public:
    equalMatrixElements(string fileInput, string fileOutput, vector<vector<int> > matrix);
    void input();
    void writer();
    void counter();
};