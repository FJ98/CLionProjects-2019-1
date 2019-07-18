#include <iostream>
//Ubicar cualquier numero en cualquier posicion de un arreglo de cualquier tamano.
int main() {
    std::cout<<"Tamano del Array: ";
    int length{0};
    std::cin>>length;

    int* A1 = new int[length];

    for (int i = 0; i < length; ++i) {
        A1[i]=i+1;
        //std::cout<<A1[i]<<" ";
    }
    for (int h = length-1; h >= 0; --h) {
        std::cout<<A1[h]<<" ";
    }

    std::cout<<std::endl;

    int* A2 = new int[length+1];

    std::cout<<"Numero para ingresar dentro del array: ";
    int u{0};
    std::cin>>u;

    std::cout<<"Ubicacion del "<< u <<" dentro del array de tamano "<< length << ": ";
    int n{0};
    std::cin>>n;

    for (int j = 0; j <= n; ++j) {
        A2[j]=A1[j]; //Entender este for en su totalidad es clave!
        A2[n]=u;
        //std::cout<<A2[j]<<" ";
    }

    //std::cout<<std::endl;

    for (int k = n+1; k <= length; ++k) {
        A2[k]=A1[k-1]; //Entender este for en su totalidad es clave!
        //std::cout<<A2[k]<<" ";
    }

    std::cout<<"\nArray con el numero "<< u << " insertado en la posicion "<< n <<": "<<std::endl;
    for (int m = length; m >= 0 ; --m) {
        std::cout<<A2[m]<<" ";
    }
    delete[] A1;
    delete[] A2;

    return 0;
}