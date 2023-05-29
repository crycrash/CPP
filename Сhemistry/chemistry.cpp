#include <iostream>
#include <string>
#include "chemistry.h"
#include <map>

using namespace std;

Chemistry::Chemistry(const string& fileInput, const string& fileOutput, int number) {
    fileNameInput = fileInput;
    fileNameOutput = fileOutput;
    conductivity = number;
}

void Chemistry::finder() {
    ifstream file;
    file.open(fileNameInput);
    string line;
    map<string, float> myMap;
    while (getline(file, line)){
        if (stoi(line.substr(line.length() - 1)) == conductivity){
            string tempString;
            int j = 0;
            while(line[j] != ' ') {
                tempString += line[j];
                j++;
            }
            float number = stof(line.substr(j + 2, line.length() - 2 - tempString.length()));
            myMap[tempString] = number;
        }
    }
    ofstream outFile(fileNameOutput);
    for (const auto& p : myMap) {
        outFile << p.first << endl;
        cout << p.first << endl;
    }
    file.close();
}