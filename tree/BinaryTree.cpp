#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    pRoot = nullptr;
}
BinaryTree::~BinaryTree() {
    deleteTree(pRoot);
}
void BinaryTree::deleteTree(Node* pNode) {
    if (pNode != nullptr) {
        deleteTree(pNode->pLeft);
        deleteTree(pNode->pRight);
        delete pNode;
    }
}
void BinaryTree::Add(int value) {
    Node* pCurrent = pRoot; //создаем указатель на корень
    Node* pParent = nullptr;//пустой указатель
    while (pCurrent != nullptr) {//пока мы не дошли до листов
        if (pCurrent->Value == value)//если это тот самый узел
            return; // узел уже существует
        pParent = pCurrent;//узел до нужного листа
        if (value < pCurrent->Value) {//если меньше
            pCurrent = pCurrent->pLeft;//суем влево
        } else {// если больше
            pCurrent = pCurrent->pRight;// суем вправо
        }
    }
    Node* pNode = new Node(value);// создаем новый указатель на узел с нужным значением
    if (pRoot == nullptr)// если дерево пусто
        pRoot = pNode;// то корень станет этой нодой
    else if (value < pParent->Value)
        pParent->pLeft = pNode;
    else
        pParent->pRight = pNode;
}
bool BinaryTree::Find(int value) {//просто идем по дереву и если нашли нужное, то выводим
    Node* pCurrent = pRoot;
    while (pCurrent != nullptr){
        if (pCurrent->Value == value)
            return true;
        if (pCurrent->Value < value)
            pCurrent = pCurrent->pRight;
        else
            pCurrent = pCurrent->pLeft;
    }
    return false;
}
void BinaryTree::Remove(int value) {
    Node* pParent = nullptr; //пока пустой родитель
    Node* pCurrent = pRoot; //указатель на корень

    while (pCurrent != nullptr && pCurrent->Value != value) { //пока не в конце и значение ни с кем не совпало
        pParent = pCurrent; //родитель становится нынешним
        pCurrent = (value < pCurrent->Value ? pCurrent->pLeft : pCurrent->pRight); //а текущий изменяется на левый или правый по отношению порядка
    }

    if (pCurrent == nullptr) //если мы дошли до конца и так и не нашли нужный
        return; //выходим нахуй

    if (pCurrent->pLeft == nullptr && pCurrent->pRight == nullptr) { //если все таки нашли и этот найденный это лист
        if (pCurrent == pRoot) //и если это дерево из одного только корня
            pRoot = nullptr; //то обнуляем и сказочке конец
        else if (pParent->pLeft == pCurrent) //если мы слева от родителя
            pParent->pLeft = nullptr; //то у родителя больше нет левого
        else
            pParent->pRight = nullptr; // иначе нет правого
        delete pCurrent; //и удаляем временную штуку
    } else if (pCurrent->pLeft == nullptr || pCurrent->pRight == nullptr) { //если же у текущего есть дети
        Node* pChild;
        if (pCurrent->pLeft != nullptr) {
            pChild = pCurrent->pLeft;
        } else {
            pChild = pCurrent->pRight;
        }
        //находим как раз таки этого ребенка
        if (pCurrent == pRoot) { //если мы в начале
            pRoot = pChild; //то корень становится ребенком
        } else if (pParent->pLeft == pCurrent) { //если мы левый
            pParent->pLeft = pChild; //то левым станет дитя
        } else {
            pParent->pRight = pChild; //правым станет дитя
        }
        pCurrent->pLeft = pCurrent->pRight = nullptr; //занулили
        delete pCurrent; //удалили
    } else { //если оба не нули
        Node* pSuccessor = pCurrent->pRight; //указатель на правое дитя
        pParent = pCurrent; //родитель становится им же самым

        while (pSuccessor->pLeft != nullptr) { //пока левый у дитя не ноль
            pParent = pSuccessor; //родитель становится дитем
            pSuccessor = pSuccessor->pLeft; //а дите идет еще ниже
        }//короче мы идем все ниже и ниже по левой ветке(ищем минимальный)

        std::swap(pSuccessor->Value, pCurrent->Value); //меняемся

        if (pParent->pLeft == pSuccessor) //короче весь алгоритм
            pParent->pLeft = pSuccessor->pRight; //сходится к тому
        else
            pParent->pRight = pSuccessor->pRight; //что мы ищем самый дальний левый у правого

        pSuccessor->pRight = nullptr; //
        delete pSuccessor; //
    }
}
