#include <iostream>
#include <functional>
#include "LinkedList.h"

/* Callable1: puntero a funcion
int suma(int a, int b){return a+b;}
int resta(int a, int b){return a-b;}
int prod(int a, int b){return a*b;}
*/

int* sort(int* arr, int n, bool(*pcomp)(int, int)){
    for (int i = 0; i < n ; i++) {
        for (int j = i+1; j < n; ++j) {
            if(pcomp(arr[i],arr[j])==true){
                std::swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}

void sort2(int* arr, int n, const std::function<bool(int, int)>& pcomp){ // cambio la sintaxis de la funcion
    for (int i = 0; i < n ; i++) {
        for (int j = i+1; j < n; ++j) {
            if(pcomp(arr[i],arr[j])==true){
                std::swap(arr[i],arr[j]);
            }
        }
    }
}

bool desc(int a, int b){return a < b;}
bool asc(int a, int b){return a > b;}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[5]={5,1,3,4,2};
    int n = 5;
    //sort(arr,5,desc);
    //sort(arr,5,asc);
    //sort2(arr,5,desc);
    sort2(arr,n,[](int a, int b){return a < b;});
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }


    /* Callable1: puntero a funcion
    int (*pf)(int, int);
    pf = resta;
    std::cout << pf(10,20);
    */
     /*
    LinkedList ll;

    for (int i = 0; i < 4; ++i) {
        ll.push_back(i);
    }

    for(auto item: ll){
        std::cout << item << " ";
    }
    */


    return 0;
}