#include "fromAdjacencyMatrixToList.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    std::ifstream input("/Users/milana/Desktop/input.txt");
    std::ofstream output("/Users/milana/Desktop/output.txt");
    adjacencyToList result(input);
    result.out();
    vector<vector <int> > check;
    check = result.list();
    result.printer(output, check);
    return 0;
}