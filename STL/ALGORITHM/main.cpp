#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <functional>
#include <vector>

using namespace std;

using iterador = std::vector<int>::iterator;
// void ejecuta(int a){// si quiero defino la funcion}
// void (*ptejecuta)(int a) equivalente function<void(int)> funcion; <--- funciona para lamba, functor y puntero a funcion

void para_cada(iterador inicio, iterador fin, function<void(int)>funcion){
    for (auto it = inicio; it != fin ; it++) {
        funcion(*it);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    /*
    vector<int> x =  {1, 2, 3, 4, 5};
    // auto f = [](int a){cout << a << " ";};
    para_cada(begin(x), end(x), [](int a){
        cout << a << " ";
    }); cout << endl;

    vector<int> y;
    copy_if(begin(x), end(x), back_inserter(y), [](int a){ return a % 2 == false;});
    for(auto item: y){cout << item << " ";}
    cout << endl;
    */
    /*
    vector<int> z =  {3, 3, 1, 4, 4};
    auto it = adjacent_find(begin(z),end(z));
    if (it != end(z)){
        cout << "El adyacente es: " << *it << endl;
    }
    else{
        cout << "No encontrado\n";
    }
    //--------------
    it++;
    it = adjacent_find(it,end(z));
    if (it != end(z)){
        cout << "El adyacente es: " << *it << endl;
    }
    else{
        cout << "No encontrado\n";
    }
    //-------------------
    auto it2 = adjacent_find(begin(z), end(z), [](int a, int b){
        return b == (a + 1);
    });
    if (it != end(z)){
        cout << "El adyacente es: " << *it2 << endl;
    }
    else{
        cout << "No encontrado\n";
    }
    */
/*
    vector<int> z2= {1,7,0,7,10,7,8};
    auto it = begin(z2);
    z2.erase(it+1);
    z2.erase(it+2);
    z2.erase(it+3);

    for(auto item: z2){
        std::cout << item << " ";
    }cout<<endl;
*/
/*
    // Fuente GeekForGeeks
    std::vector<int> vec{ 10, 20, 30, 30, 20, 10, 10, 20 };
    // Print original vector
    std::cout << "Original vector :";
    for (int i : vec)
        std::cout << " " << i;
    std::cout << "\n";
    // Iterator that store the position of last element
    auto pend = std::remove(vec.begin(), vec.end(), 20);
    // Print the vector after std :: remove
    std::cout << "Range contains:";
    for (auto p = begin(vec); p != pend; ++p)
        std::cout << ' ' << *p;
    std::cout << '\n';
*/
    // Mi trabajo en clase viernes 31 de mayo de 2019
    vector<int> z3 = {1,7,0,7,10,7,8};
    vector<int> z4 = {1,7,0,7,10,7,8};
    // imprimir vector original z3
    cout << "Vector original: ";
    for(auto i: z3){
        cout << i << " ";
    } cout << endl;
    //con remove
    auto pend2 = remove(begin(z3), end(z3), 7);
    cout << "Eliminar 7 con remove: ";
    for (auto iterador = begin(z3); iterador != pend2 ; ++iterador) {
        cout << *iterador << " ";
    } cout << endl;
    // con erase
    for (auto j = begin(z4); j != end(z4) ; ++j) {
        if (*j==7) {z4.erase(j);}
    }
    cout << "Eliminar 7 con erase: ";
    for (auto i: z4) {
        cout << i << " ";
    } cout << endl;
    // Output: z={1,0,10,8}

    return 0;
}