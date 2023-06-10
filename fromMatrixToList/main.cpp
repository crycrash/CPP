#include "fromMatrixToList.h"
#include <iostream>
#include <vector>
#include <fstream>

int main(){
    std::ifstream input("/Users/milana/Desktop/input.txt");
    std::ofstream output("/Users/milana/Desktop/output.txt");
    toList result(input);
    result.out();
    result.list(output);
    return 0;
}