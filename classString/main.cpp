#include <iostream>
#include "string.h"

using namespace std;

int main(){
    String firstString("Milana");
    String secondString("Zinovieva");
    String emptyString;
    String cloneString(firstString);
    String result = firstString + secondString;
    cout << result;
    cout << result.front() << endl;
    cout << result.back() << endl;
    cout << result.size() << endl;
    bool check = result.empty();
    bool check1 = emptyString.empty();
    cout << check << check1 << endl;
    firstString.clear();
    cout << firstString.size() << endl;
    secondString.push_back('r');
    cout << secondString;
    secondString.pop_back();
    cout << secondString;
    int h = secondString.find_first_of("no");
    cout << h;
}