#include "graphToList.h"
#include <iostream>
#include <vector>
#include <fstream>

int main(){
    std::ifstream input("/Users/milana/Desktop/input.txt");
    std::ofstream output("/Users/milana/Desktop/output.txt");
    graphToList result(input);
    std::vector<std::vector <int > > check;
    check = result.list();
    result.printer(output, check);
    return 0;
}