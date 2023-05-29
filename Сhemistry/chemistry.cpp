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
    map<float, string> myMap;
    bool flag = 0;
    while (getline(file, line)){
        if (stoi(line.substr(line.length() - 1)) == conductivity){
            flag = 1;
            string tempString;
            int j = 0;
            while(line[j] != ' ') {
                tempString += line[j];
                j++;
            }
            float number = stof(line.substr(j + 1, line.length() - 3 - tempString.length()));
            myMap[number] = tempString;
        }
    }
    ofstream outFile(fileNameOutput);
    if (flag == 0)
        cout << "no one";
    for (const auto& p : myMap) {
        outFile << p.second << endl;
        cout << p.second << endl;
    }
    file.close();
}