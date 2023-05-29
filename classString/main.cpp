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
    secondString.insert("jj", 3);
    cout << secondString;
    String checkString("milashkakakashka");
    int m = checkString.find_first_of("sa");
    cout << m << endl;
    String haha = checkString.substr(4, 8);
    cout << haha << endl;

}