#include "queue.h"

int main(){
    QueueOnTwoStacks queue;
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(2);
    queue.dequeue();
    queue.dequeue();
}