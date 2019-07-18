#include <iostream>
#include "Task.h"
#include "FaultToleranceTask.h"
#include "SingleTask.h"
#include "Queue.h"
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    auto Cola = new Queue();

    Task* ft1 = new FaultToleranceTask("T1",5);
    Task* ft2 = new FaultToleranceTask("T2",4);
    Task* ft3 = new FaultToleranceTask("T3",8);
    Task* ft4 = new FaultToleranceTask("T4",6);
    Task* ft5 = new FaultToleranceTask("T5",3);

    Task* st1 = new SingleTask("S1");
    Task* st2 = new SingleTask("S2");
    Task* st3 = new SingleTask("S3");
    Task* st4 = new SingleTask("S4");
    Task* st5 = new SingleTask("S5");

    Cola->enqueue(ft1);
    Cola->enqueue(st1);
    Cola->enqueue(ft2);
    Cola->enqueue(st2);
    Cola->enqueue(ft3);
    Cola->enqueue(st3);
    Cola->enqueue(ft4);
    Cola->enqueue(st4);
    Cola->enqueue(ft5);
    Cola->enqueue(st5);

    for (int i = 0; i < 10; i++) {
        Cola->dequeue()->execute();//Por que deque puede entrar a execute?
    }

    delete Cola;
    return 0;
}