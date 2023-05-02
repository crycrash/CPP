#include <iostream>
#include "string.h"

using namespace std;

int main(){
    String firstString("Milana");
    String secondString("Zinovieva");
    String emptyString;
    String cloneString(firstString);
    String result = firstString + secondString;
    cout << result[4];
}