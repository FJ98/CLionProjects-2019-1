//#include <iostream> #include "Progression.h"
#define  CATCH_CONFIG_MAIN
#include "catch.hpp"


#ifndef CATCH_CONFIG_MAIN
int main() {
    std::cout << "Hello, World!" << std::endl;
    //Progression p1;
    Progression* p = new ArithProgression();

    std::vector<long>v2 = get_series(p,4);
    for(auto item: v2){
        std::cout<<v2[item]<<" - ";
    }std::cout<<std::endl;
    auto total = calculate_total(&p, 4);
    std::cout<<"La suma es: "<<total<<std::endl;
    return 0;
}
#endif