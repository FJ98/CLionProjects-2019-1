#include <iostream>
#include <random>
#include "Queue.h"
#include "Process.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 12;

    auto q = new Queue<Process*>();

    Process* s1 = new SynProcess("Sincrono 1");
    Process* s2 = new SynProcess("Sincrono 2");
    Process* s3 = new SynProcess("Sincrono 3");
    Process* s4 = new SynProcess("Sincrono 4");
    Process* s5 = new SynProcess("Sincrono 5");

    Process* as1 = new ASynProcess("Asincrono 1", "SDFASDF");
    Process* as2 = new ASynProcess("Asincrono 2", "ASDF");
    Process* as3 = new ASynProcess("Asincrono 3", "ASD");
    Process* as4 = new ASynProcess("sincrono 4", "WEFQWE");
    Process* as5 = new ASynProcess("Asincrono 5", "QWEF");
    Process* as6 = new ASynProcess("Asincrono 6", "QW");
    Process* as7 = new ASynProcess("Asincrono 5", "Q22435");

    q->enqueue(&s1);
    q->enqueue(&s2);
    q->enqueue(&s3);
    q->enqueue(&s4);
    q->enqueue(&s5);

    q->enqueue(&as1);
    q->enqueue(&as2);
    q->enqueue(&as3);
    q->enqueue(&as4);
    q->enqueue(&as5);
    q->enqueue(&as6);
    q->enqueue(&as7);

    for (int i = 0; i < 5; ++i) {
        q->dequeue()->run();
    }std::cout << std::endl;
    for (int i = 5; i < n; ++i) {
        q->dequeue()->run();
    }

    return 0;
}