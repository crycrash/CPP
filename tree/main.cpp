#include "BinaryTree.h"
#include <iostream>

int main(){
    BinaryTree tree;
    tree.Add(50);
    tree.Add(75);
    tree.Add(74);
    tree.Add(100);
    tree.Add(16);
    tree.Add(13);
    tree.Add(20);
    tree.Add(36);
    tree.Add(40);
    tree.Add(99);
    tree.Add(120);
    tree.Add(101);
    tree.Add(130);
    bool i = tree.Find(11);
    bool j = tree.Find(40);
    std::cout << i << " " << j;
    tree.Remove(75);
}