#include <iostream>
#include <vector>
#include <random>
#include "SmartPoint.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::random_device rd;
    std::vector<int> v(10);
    for (auto it = begin(v); it < end(v); it++) {
        *it = rd()%20+1;
    }
    for(auto item: v){
        std::cout << item << "  ";
    }std::cout << std::endl;

    //-Introduccion a Smart Pointers-----------------
    /*
    punteroInteligente<int> ptr3;
    punteroInteligente<int> ptr4(20);
    std::cout << "Puntero 3: " << *ptr3 << std::endl;
    std::cout << "Puntero 4: " << *ptr4 << std::endl;
    *ptr3 = 40;
    std::cout << "Puntero 3: " << *ptr3 << std::endl;
    std::cout << "Puntero 4: " << *ptr4 << std::endl;
    */
     //-----------------------------------------------
    //A a;
    //B b = new B[100];
    //A a(5);


    return 0;
}