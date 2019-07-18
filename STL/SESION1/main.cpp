//#include "Funciones.h"
/* Elaborar un método o función
 * genérica donde dada 2 pilas genere
 * la suma de las 2 pilas con valores
 * intercalados.
 */

#include <stack>
#include <iostream>

template <typename T>
auto alternar(T s1, T s2, T s3){
    T s4;
    while (!s1.empty() || !s2.empty()) {
        s3.push(s1.top());
        s3.push(s2.top());
        s1.pop();
        s2.pop();
    }
    while( !s3.empty() ){
        // Bucle necesario para poner el stack 3 en revesa
        // que es justamente como lo queremos imprimir
        s4.push( s3.top() );
        s3.pop();
    }
    return s4;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::stack<int> s1, s2, s3, s4;
    for(auto& item : {3,4,5,6}){ s1.push(item); }
    for(auto& i : {1,2,7,8}){ s2.push(i); }

    s3 = alternar(s1,s2,s3);

    std::cout << "Stack1: ";
    while(!s1.empty()) {
        std::cout << s1.top() << " ";
        s1.pop();
    }std::cout << std::endl;

    std::cout << "Stack2: ";
    while(!s2.empty()) {
        std::cout << s2.top() << " ";
        s2.pop();
    } std::cout << std::endl;

    std::cout << "Stack3: ";
    while(!s3.empty()) {
        std::cout << s3.top() << " ";
        s3.pop();
    } std::cout << std::endl;

    return 0;
}