#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Chemistry{
private:
    string fileNameInput;
    string fileNameOutput;
    int conductivity;
public:
    Chemistry(const string& fileInput, const string& fileOutput, int number);
    void finder();
};