#include <iostream>
#include "string.h"

using namespace std;

int main(){
    String firstString("Milana");
    String secondString("Zinovieva");
    String emptyString;
    String cloneString(firstString);
    cout << cloneString;
    String result = firstString + secondString;
    cout << result;
    bool check = firstString == result;
    cout << check << endl;
}