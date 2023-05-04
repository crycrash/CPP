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

String String::operator+(const String& secondString) {
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

bool String::operator==(const String& other) {
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

char String::operator[](int number) {
    return dataString[number];
}

char String::front() {
    if (lengthString == 0)
        return ' ';
    else
        return dataString[0];
}

char String::back() {
    if (lengthString == 0)
        return ' ';
    else
        return dataString[lengthString - 1];
}

int String::size() const {
    return lengthString;
}

void String::clear() {
    for(int i = 0;i < lengthString;i++)
        dataString[i] = '\0';
    lengthString = 0;
}

bool String::empty() const {
    if (lengthString == 0)
        return true;
    else
        return false;
}

String String::insert(String need, int position) {
    String tempString;
    tempString.lengthString = lengthString - position;
    for(int i = 0, b = position;i < tempString.lengthString;i++, b++)
        tempString.dataString[i] = dataString[b];
    for(int j = position, a = 0;a < need.lengthString;j++, a++)
        dataString[j] = need.dataString[a];
    String result;
    result.lengthString = position + need.lengthString;
    for(int y = 0; y < result.lengthString;y++)
        result.dataString[y] = dataString[y];
    return result;
}

String String::push_back(char symbol) {
    lengthString++;
    dataString[lengthString - 1] = symbol;
    return dataString;
}

String String::pop_back() {
    dataString[lengthString - 1] = '\0';
    lengthString--;
    return dataString;
}

int String::find_first_of(String subString) {
    for(int i = 0;i < lengthString;i++){
        int count = 0;
        for(int j = 0;j < subString.lengthString;j++){
            if (dataString[i] == subString[j])
                count++;
        }
        if (count == subString.lengthString)
            return i;
    }
    return -1;
}

String String::substr(int startPosition, int endPosition) {
    String newString;
    for(int i = startPosition, j = 0;i < endPosition;i++, j++)
        newString.dataString[j] = dataString[i];
    return newString;
}

String String::replace(int position, int count, const String& newString) {
    for(int i = position;i < position + count;i++)
        dataString[i] = '\0';
    lengthString = lengthString - count + newString.lengthString;
    for(int j = position;j < lengthString;j++){
        dataString[j] = newString.dataString[j];
    }
    return dataString;
}

String String::append(const String& secondString) {
    int tempLength = lengthString;
    lengthString = lengthString + secondString.lengthString;
    for (int i = tempLength, j = 0;i < lengthString;i++, j++){
        dataString[i] = secondString.dataString[j];
    }
    return dataString;
}
