#include <iostream>
#include "LinkedList.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    LinkedList l;
    //l.add_head(10);
    //l.remove_head();


    l.add_tail(10);
    l.add_tail(20);

    //l.remove_tail();

    l.print();




    return 0;
}