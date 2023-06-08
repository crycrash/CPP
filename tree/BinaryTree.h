#pragma once
#include <iostream>

class BinaryTree{
public:
    BinaryTree();//получили набор данных и перебираем циклом данные и вызываем метод add
    ~BinaryTree();//рекурсивно идем по уровням
    bool Find(int value);
    void Add(int value);
    void Remove(int value);
private:
    struct Node{
        int Value;
        Node* pLeft;
        Node* pRight;
        Node(int value): Value(value), pLeft(nullptr), pRight(nullptr) {};
        Node(): pLeft(nullptr), pRight(nullptr) {};
    };
    Node* pRoot;
    void deleteTree(Node* pNode);
};