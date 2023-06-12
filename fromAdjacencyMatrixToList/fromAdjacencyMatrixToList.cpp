#include "fromAdjacencyMatrixToList.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

adjacencyToList::adjacencyToList(std::ifstream &file) {
    file >> vertices >> edge;
    matrix = new int* [vertices];
    for (int j = 0;j < vertices;j++){
        matrix[j] = new int [vertices];
        for (int l = 0;l < vertices;l++){
            file >> matrix[j][l];
        }
    }
}
void adjacencyToList::out() {
    cout << vertices << " " << edge << endl;
    for (int i = 0;i < vertices;i++){
        for (int j = 0;j < vertices;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<std::vector <int> > adjacencyToList::list() {
    vector<vector <int> > adjacentList;
    adjacentList.resize(vertices);
    for (int i = 0;i < vertices;i++){
        for (int j = 0;j < vertices;j++){
            if (matrix[j][i] == 1){
                adjacentList[i].push_back(j + 1);
            }
        }
    }
    return adjacentList;
}
void adjacencyToList::printer(std::ofstream &file, std::vector<std::vector<int> > adjList) const {
    for (int i = 0;i < vertices;i++){
        file << i + 1<< ": ";
        for(int j : adjList[i]){
            if (j != 0)
                file << j << " ";
        }
        file << "0" << endl;
    }
}