
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<assert.h>
#include<sys/time.h>

#define NUM_HILOS 2
unsigned long long int **matriz1;
unsigned long long int **matriz2;
unsigned long long int **matriz3;

struct datos
{
    long thread_id;
    int num_filas;
    int num_columnas;
    int intervalos;
};

struct datos datos_pasar[NUM_HILOS];

void allocar_memoria(int filas,int columnas);
void imprimir_matrix(int filas,int columnas);
void llenar_numeros(int filas,int columnas);

void *calcular (void *parametros)
{
    int i,j,k,filas,columnas,lim_inf,lim_sup,intervalo,suma;
    long t;
    struct datos *mis_datos;
    mis_datos=(struct datos *) parametros;

    t= mis_datos->thread_id;
    filas= mis_datos->num_filas;
    columnas=mis_datos->num_columnas;
    intervalo=mis_datos->intervalos;

    lim_inf=t*(intervalo);
    lim_sup=(t+1)*(intervalo);

    if(lim_sup>filas)
    {
        lim_sup=filas;
        if(lim_inf>lim_sup)
        {
            lim_inf=filas;
        }
    }


    printf("Hilo %ld, LIM inf %d LIM sup %d, intervalos %d \n",t,lim_inf,lim_sup,intervalo);
    if(lim_sup!=lim_inf){
        for (i=lim_inf;i<lim_sup;i++)
        {
            for (j=0;j<columnas;j++)
            {
                matriz3[i][j]=0;
                for(k=0;k<columnas;k++)
                {
                    matriz3[i][j]+=matriz1[i][k]*matriz2[k][j];
                }
            }
        }
    }

    pthread_exit(NULL);
}



void allocar_memoria(int filas,int columnas)
{
    int i,j,k;
    matriz1=(unsigned long long int**)malloc(filas*sizeof(unsigned long long int*));
    for (i=0;i<filas;i++)
    {
        matriz1[i]=(unsigned long long int*)malloc(columnas*sizeof(unsigned long long int));
    }

    matriz2=(unsigned long long int**)malloc(filas*sizeof(unsigned long long int*));
    for (i=0;i<filas;i++)
    {
        matriz2[i]=(unsigned long long int*)malloc(columnas*sizeof(unsigned long long int));
    }

    matriz3=(unsigned long long int**)malloc(filas*sizeof(unsigned long long int*));
    for (i=0;i<filas;i++)
    {
        matriz3[i]=(unsigned long long int*)malloc(columnas*sizeof(unsigned long long int));
    }

} //Fin de Allocar Memoria

void imprimir_matrix(int filas,int columnas)
{
    int i,j,k;
    printf("MATRIX 1\n");
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            printf("%d \t",(int)matriz1[i][j]);
        }
        printf("\n");
    }
    printf("MATRIX 2\n");
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            printf("%d \t",(int)matriz2[i][j]);
        }
        printf("\n");
    }
    printf("MATRIX 3\n");
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            printf("%d \t",(int)matriz3[i][j]);
        }
        printf("\n");
    }
}//Fin de Imprimir Arreglos



void llenar_numeros(int filas, int columnas)
{
    int i,j,k;
    unsigned long long int numero;
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            numero = rand()%15;
            matriz1[i][j]=numero;
            matriz2[i][j]=numero;

        }

    }

}//Fin de llenar_numeros





