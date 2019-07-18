// Created by felix on 5/22/2019.
#ifndef SESION1_FUNCIONES_H
#define SESION1_FUNCIONES_H

#include <iostream>
#include <stack>

template <typename T>
auto alternar(T s1, T s2, T s3){
    while (!s1.empty() || !s2.empty()) {
        s3.push(s1.top());
        s3.push(s2.top());
        s1.pop();
        s2.pop();
    }
    return s3;
}

template <typename T>
void alternateStacks () {

}

template <typename T, typename... Params>
void alternateStacks(){

}


#endif //SESION1_FUNCIONES_H
