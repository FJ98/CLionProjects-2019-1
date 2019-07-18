#include <iostream>
#include "Lista.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Lista l1;
    l1.add_tail(10);
    l1.add_tail(20);
    std::cout<<l1.size()<<std::endl<<std::endl;
    l1.remove_tail();

    return 0;
}