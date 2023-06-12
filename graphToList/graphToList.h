#pragma once
#include <vector>

class graphToList{
private:
    int height;
    int width;
    std::vector<char> names;
    int **matrix;
public:
    explicit graphToList(std::ifstream& file);
    void out();
    std::vector<std::vector <int> > list();
    void printer(std::ofstream &file, std::vector<std::vector <int> > adjList) const;
};
