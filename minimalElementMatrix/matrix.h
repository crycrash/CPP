#include <iostream>
#include <fstream>

class ListMatrix {
private:
    struct Matrix {
        int height;
        int width;
        int** matrix;
        Matrix* next = nullptr;
    };
public:
    Matrix* begin;

    explicit ListMatrix(std::ifstream& file);
    void findMinimal(std::ofstream& file) const;
    void out() const;
};