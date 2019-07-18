#include <iostream>
#include "Funciones.h"
int main() {
    /*
    std::cout << "print: ";
    print("Los valores", "(", 1,",", 2.0, ")") ;
    std::cout << std::endl;

    auto total = suma(1,2,4,5, 1.5);
    std::cout<<std::endl;
    std::cout << "Suma total: " << total << std::endl;

    auto comp = comparar(1,1,2,2);
    std::cout << std::endl;
    std::cout << "Comparacion: " << std::boolalpha << comp << std::endl;

    auto sumProd = sum_product(1,1,2,2);
    std::cout << std::endl;
    std::cout << "Sum_product: " << sumProd << std::endl;

    std::cout << std::endl;
    std::cout << "Factorial: " << factorial<5>::value << std::endl << std::endl;

    // PROBAR QUICKSORT TEMPLATE
    const int TAMANO = 10;
    int array[TAMANO] = {10, 4, 7, 5, 8, 1, 6, 9, 3, 2};

    for (int item : array){
        std::cout << item << " ";
    }std::cout << std::endl;

    quickSort(array, 0, TAMANO-1);

    for (int item : array){
        std::cout << item << " ";
    } std::cout<<std::endl;


    std::stack<int> s1, s2, s3;
    for(auto& item : {3,4,5,6}){
        s1.push(item);
    }
    for(auto& i : {1,2,7,8}){
        s2.push(i);
    }

    s3 = alternar(s1,s2,s3);

    while(!s3.empty()){
        std::cout << s3.top() << std::endl;
        s3.pop();
    }std::cout << std::endl;
     */

    std::map<int, int> map;
    for (int i = 0; i < 10; ++i) {
        map[i] = rand() % 5;
    }
    for (auto & it : map) {
        std::cout << it.first << " => " << it.second << std::endl;
    }
    for (auto & iter : map) {
        if (map[0]==(iter.second)) {

        }
    }
    return 0;
}