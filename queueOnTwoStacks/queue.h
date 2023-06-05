#pragma once
#include <stack>

class QueueOnTwoStacks{
private:
    std::stack <int> input;
    std::stack <int> output;
public:
    void enqueue(int element);
    void dequeue();
};