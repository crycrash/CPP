#include <iostream>
#include "string.h"

using namespace std;

String::String(){
    lengthString = 0;
    dataString = new char[1];
    dataString[0] = '\0';
}

String::String(const char *string) {
    lengthString = 0;
    while(string[lengthString] != '\0'){
        lengthString++;
    }
    dataString = new char[lengthString + 1];
    for(int i = 0;i < lengthString;i++)
        dataString[i] = string[i];
    dataString[lengthString + 1] = '\0';
}

String::String(const String &otherString) {
    lengthString = otherString.lengthString;
    dataString = new char[lengthString + 1];
    for (int i = 0;i < lengthString;i++)
        dataString[i] = otherString.dataString[i];
    dataString[lengthString + 1] = '\0';
}

String::~String() {
    delete[] dataString;
}

const char* String::c_str() const {
    return dataString;
}

ostream& operator<< (ostream &out, const String &string)
{
    out << string.c_str() << endl;
    return out;
}

String String::operator+(String secondString) {
    String result;
    result.lengthString = secondString.lengthString + lengthString;
    result.dataString = new char[result.lengthString + 1];
    for (int i = 0;i < lengthString;i++)
        result.dataString[i] = dataString[i];
    for (int u = lengthString, t = 0;u < result.lengthString;u++, t++) {
        result.dataString[u] = secondString.dataString[t];
    }
    result.dataString[result.lengthString + 1] = '\0';
    return result;
}

bool String::operator==(String other) {
    int count = 0;
    if (other.lengthString != lengthString){
        return false;
    }else{
        for(int i = 0;i < lengthString;i++){
            if (other.dataString[i] == dataString[i])
                count++;
        }
    }
    if (count == lengthString)
        return true;
    else
        return false;
}
