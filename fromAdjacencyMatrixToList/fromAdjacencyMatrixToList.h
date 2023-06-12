#pragma once
#include <vector>

class adjacencyToList{
private:
    int vertices;
    int edge;
    int **matrix;
public:
    adjacencyToList(std::ifstream& file);
    void out();
    std::vector<std::vector <int> > list();
    void printer(std::ofstream &file, std::vector<std::vector <int> > adjList) const;
};