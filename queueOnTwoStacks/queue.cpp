#include "queue.h"
#include <iostream>

using namespace std;

void QueueOnTwoStacks::enqueue(int element) {
    input.push(element);
    cout << input.top() << endl;
}
void QueueOnTwoStacks::dequeue() {
    if (output.empty()) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    cout << output.top() << endl;
    output.pop();
}