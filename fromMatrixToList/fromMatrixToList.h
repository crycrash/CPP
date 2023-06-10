#pragma once
#include <vector>

class toList{
private:
    int height;
    int width;
    std::vector<char> names;
    int **matrix;
public:
    explicit toList(std::ifstream& file);
    void out();
    void list(std::ofstream& file);
};