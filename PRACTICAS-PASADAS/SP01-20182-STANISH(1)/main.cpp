#include <iostream>
#include "Queue.h"
#include <random>
int main() {
    srand(time(0));
    auto cola1=new Queue();
    Task* st1 = new SingleTask("tarea 1");
    Task* ft1 = new FaultToleranceTask("Tolerante 1",4);
    cola1->enqueue(st1);
    cola1->enqueue(ft1);
    for (int i = 0; i < 2; ++i) {
        cola1->dequeue()->execute();
    }
    delete cola1;
    return 0;
}