#include <iostream>
#include <string>
#include "chemistry.h"

using namespace std;

int main(){
    Chemistry first("/Users/milana/Desktop/input.txt", "/Users/milana/Desktop/output.txt", 2);
    first.finder();
}