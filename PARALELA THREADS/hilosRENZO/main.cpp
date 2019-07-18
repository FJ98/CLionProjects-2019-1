/*Multiplication de Matrices*/
#include "EjMatrizRivas.h"
#include "ArMatriz.h"
#include "RenzoMatriz.h"
#include "SMatriz.h"

int main(){
//--------ARMatriz-------------------------------------------------
    Matriz<int> a;
    Matriz<int> b;
    Matriz<int> c;
    a.RellanrMatriz(2,2);
    b.RellanrMatriz(2,2);
    a.PrintMatriz();
    b.PrintMatriz();
    c=a*b;
    c.PrintMatriz(); cout << endl;
    //CONCURRENTE
    struct timeval start{};
    struct timeval finish{};
    long compTime; double Time_2;
    //--Concurrente
    Matriz_Concurrente _m1(5, 3);
    Matriz_Concurrente _m2(3, 2);
    _m1.fill_matriz();
    _m2.fill_matriz();
    _m1.printMatries(); cout<<endl;
    _m2.printMatries(); cout<<endl;
    gettimeofday(&start, nullptr);
    Matriz_Concurrente _m3 = _m1*_m2;
    gettimeofday(&finish, nullptr);
    compTime=(finish.tv_sec - start.tv_sec)*1000000;
    compTime=compTime+(finish.tv_usec - start.tv_usec);
    Time_2=(double)compTime;
    std::cout << "El tiempo que se demoro usando hilos fue "<< (double)Time_2/1000000.0 <<" Secs \n";
    std::cout << std::endl;
    _m3.printMatries();
//----------RIVAS------------------------------------------------------
    /*const size_t size = 3;
    MatrizR<int, size> mat1;
    MatrizR<int, size> mat2;

    mat1.generar_matriz();
    mat2.generar_matriz();
    mat1.mostrar_matriz();cout << "\n";
    mat2.mostrar_matriz();cout << "\n";

    mat1.ejecuta_threads(mat2);
    mat1.ejecuta_async(mat2);*/
//--------SMatriz NO FUNCIONA FALTA SOBRECARGAR OPERADOR =---------------------
    /*MatrizAsincrona<int> matrizAsincrona1(2,2);
    MatrizAsincrona<int> matrizAsincrona2(2,2);
    MatrizAsincrona<int> matrizAsincrona3 (2, 2);
    matrizAsincrona3 = matrizAsincrona1*matrizAsincrona2;
    matrizAsincrona3.print();*/
//----------RENZO------------------------------------------------------
/*
    int i,j,k,inter;
    int m,n,rc;
    long t;
    double var1,var2;
    void *status;

    struct timeval start;
    struct timeval finish;
    long compTime;
    double Time;

    pthread_t hilos[NUM_HILOS]; //declaro mi arreglo de hilos
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

    printf("Multiplicacion de Matrices\n");
    printf("Cuantas filas tiene la matriz 1 ?\n");
    scanf("%d",&m);
    printf("Cuantas columnas tiene la matriz 1 ?\n");
    scanf("%d",&n);
    printf("La Matriz 1 es %d x %d \n",m,n);
    printf("La Matriz 2 es %d x %d \n",m,n);
    printf("La Mtraiz 3 es %d x %d \n",m,n);

    allocar_memoria(m,n);
    llenar_numeros(m,n);
    imprimir_matrix(n,n);

    inter = ((int)(m/NUM_HILOS)+1);

    gettimeofday(&start,0);

    for (t=0;t<NUM_HILOS;t++)
    {

        datos_pasar[t].thread_id=t;
        datos_pasar[t].num_filas=m;
        datos_pasar[t].num_columnas=n;
        datos_pasar[t].intervalos=inter;
        printf("Creando el hilo %ld \n",t);
        rc=pthread_create(&hilos[t],&attr,calcular,(void*)&datos_pasar[t]);
        if (rc){printf("ERROR codigo %d \n",rc);
            exit(-1);}
    }
    pthread_attr_destroy(&attr);
    for(t=0;t<NUM_HILOS;t++)
    {
        rc=pthread_join(hilos[t],&status);
        if(rc){printf("ERROR,codigo %d \n",rc);
            exit(-1);}
        printf("En la funcion main, ya acabo el hilo %ld con status %ld \n",t,(long)status);
    }

    gettimeofday(&finish,0);
    compTime=(finish.tv_sec - start.tv_sec)*1000000;
    compTime=compTime+(finish.tv_usec - start.tv_usec);
    Time=(double)compTime;

    imprimir_matrix(m,n);
    printf("Despues de multiplicar \n");
    printf("El tiempo que se demoro fue de %f secs \n",(double)Time/1000000.0);

    printf("Fin del programa \n");
    pthread_exit(NULL);
*/

    return 0;
}//fin funcion principal



