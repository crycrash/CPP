#include <iostream>

using namespace std;

class String{
private:
    char* dataString;
    int lengthString;
    const char* c_str() const;
public:
    String();
    String(const char* string);
    String(const String& otherString);
    ~String();
    friend ostream& operator<< (ostream &out, const String &string);
    String operator +(const String& secondString);
    bool operator ==(const String& other);
    char operator [](int number);
    char front();
    char back();
    int size() const;
    void clear();
    bool empty() const;
    String insert(String need, int position);
    String push_back(char symbol);
    String pop_back();
    String append(const String& secondString);
    String replace(int position, int count, const String& newString);
    String substr(int startPosition, int endPosition);
    int find_first_of(String subString);
};