#include "array.h"

int main(){
    ArrayList List;
    List.Append(1);
    List.Append(2);
    List.Append(3);
    List.Append(4);
    List.Append(5);
    List.DeleteAt(3);
    List.InsertAt(8, 2);
    List.Print();
}