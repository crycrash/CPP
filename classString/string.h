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
    String operator +(String secondString);
    bool operator ==(String other);
};