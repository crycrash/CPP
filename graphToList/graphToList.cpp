#include "graphToList.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

graphToList::graphToList(std::ifstream &file) : height(), width() {
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
void graphToList::out() {
    cout << height << " " << width << endl;
    for (int i = 0;i < height;i++){
        for (int j = 0;j < width;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector <int> > graphToList::list()
{
    vector<vector <int> > adjacentList;
    adjacentList.resize(height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < height; k++) {
                    if (k != i && matrix[k][j] == 1) {
                        adjacentList[i].push_back(k + 1);
                        break;
                    }
                }
            }
        }
    }
    return adjacentList;
}

void graphToList::printer(std::ofstream& out, std::vector<std::vector <int> > adjList) const
{
    for (int i = 0;i < height;i++){
        out << i + 1<< ": ";
        for(int j : adjList[i]){
            if (j != 0)
                out << j << " ";
        }
        out << "0" << endl;
    }
}
