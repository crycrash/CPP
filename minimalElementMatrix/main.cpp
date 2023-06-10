#include "matrix.h"
#include <fstream>

int main() {
    std::ifstream input("/Users/milana/Desktop/input.txt");
    std::ofstream out("/Users/milana/Desktop/output.txt");
    ListMatrix check(input);
    check.findMinimal(out);
    return 0;
}
