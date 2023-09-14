#include <stdio.h>
#include <stdlib.h>
#define color system("COLOR B")
#define ESC 27

#include <conio.h>
#include <string.h>
/**

Crear un arreglo dinámico con punteros: Escribir un programa que permita al usuario ingresar un número entero n,
 luego usando malloc crear un arreglo dinámico de n elementos utilizando punteros y permitir al usuario ingresar valores para completar el arreglo.
 Luego, muestra los valores ingresados utilizando punteros.

*/







int main()
{
    color;

    int  *a  ;
    char  o=0;
    int num;
    int val=0;
    int i=0;
    int cant;
    printf("ingrese cantidad de datos a cargar \n");
    scanf("%d",&cant);
    a = (int *) malloc (cant * sizeof(int));
    while( o!=27)
    {
        printf("Ingrese un numero \n");
        scanf("%d",&num);
        a[val] =num;
        val++;
        if(val == cant){
            fflush(stdin);
        o=27;
        }
        else
{
     printf("PRESIONE CUALQUIER TECLA PARA CONTINUAR O ESC PARA SALIR DE LA CARGA \n");
        fflush(stdin);
        o=getch();
}
    }
    while(i<val)
    {
        printf("%d \n",a[i]);
        i++;
    }
    if(val == cant){
 a= (int *)realloc( a,(cant*sizeof(int)));
    cant =cant*sizeof(int);
    printf("cant %d",cant);
    }
    o=0;
      while( o!=27)
    {
        printf("Ingrese un numero \n");
        scanf("%d",&num);
        a[val] =num;
        val++;
        if(val == cant){
            fflush(stdin);
        o=27;
        }
        else
{
     printf("PRESIONE CUALQUIER TECLA PARA CONTINUAR O ESC PARA SALIR DE LA CARGA \n");
        fflush(stdin);
        o=getch();
}
    }
    while(i<val)
    {
        printf("%d \n",a[i]);
        i++;
    }

    return 0;
}




