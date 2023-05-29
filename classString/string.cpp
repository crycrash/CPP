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

char String::front() { //ready
    if (lengthString == 0)
        return ' ';
    else
        return dataString[0];
}

char String::back() { //ready
    if (lengthString == 0)
        return ' ';
    else
        return dataString[lengthString - 1];
}

int String::size() const { //ready
    return lengthString;
}

void String::clear() { //ready
    for(int i = 0;i < lengthString;i++)
        dataString[i] = '\0';
    lengthString = 0;
}

bool String::empty() const { //ready
    if (lengthString == 0)
        return true;
    else
        return false;
}

String String::insert(String need, int position) { //ready
    String tempString;
    for(int i = position, j = 0;i < lengthString;i++, j++)
        tempString.dataString[j] = dataString[i];
    lengthString += need.lengthString;
    for(int x = position, y = 0;x < position + need.lengthString;x++, y++)
        dataString[x] = need.dataString[y];
    for(int h = position + need.lengthString, n = 0;h < lengthString;h++, n++)
        dataString[h] = tempString.dataString[n];
    return dataString;
}

String String::push_back(char symbol) { //ready
    lengthString++;
    dataString[lengthString - 1] = symbol;
    return dataString;
}

String String::pop_back() { //ready
    dataString[lengthString - 1] = '\0';
    lengthString--;
    return dataString;
}

int String::find_first_of(String subString) { //ready
    int i = 0;
    while(i < lengthString){
        int count = 0;
        int j = 0;
        while (j < subString.lengthString){
            if (dataString[i + j] == subString[j])
                count++;
            j++;
        }
        if (count == subString.lengthString)
            return i;
        i++;
    }
    return -1;
}

String String::substr(int startPosition, int endPosition) { // ready
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
