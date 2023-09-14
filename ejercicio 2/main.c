#include <stdio.h>
#include <stdlib.h>
#define color system("COLOR B");
#include <conio.h>
#include <string.h>
#define ESC 27

/**Modificar el programa del Ejercicio 1 para permitir que el usuario ingrese mas elementos al arreglo
(usar realloc con punteros para redimensionar el arreglo dinámico) agregando más elementos al final.
El proceso de redimensionamiento debe ser transparente para el usuario, es decir que el mismo,
no debe ingresar el nuevo tamaño para el arreglo, sino que solo se le pedirá que ingrese los nuevos valores hasta el momento en que decida dejar
de hacerlo. Finalmente mostrar el arreglo (modularizar)
*/

///PROTOTIPADO
int cargar(int  *a , int *validos);
void mostrar_array(int *a,int  *validos);

int main()
{
    color;

    int  *validos;
    int *a=NULL;
    *a = cargar(  a, validos);
    printf("LOS VALIDOS DEL MAIN %d \n",*validos);

    mostrar_array(a,*&validos);
    return 0;
}

int cargar(int *a,int *validos )
{
    int cant=0;
    char o=0;
    int num=0;
    int i=0;
    printf("Ingrese cantidad a cargar \n");
    scanf("%d",&cant);
    a=(int *)malloc(cant*sizeof(int));

    while(o!=27 )
    {

        printf("Ingrese numero \n");
        scanf("%d",&num);
        a[i]=num;
        i++;
        if(i==cant)
        {
            fflush(stdin);
            o=27;
        }
        else
        {
            printf("PRESS ESC PARA SALIR SINO ANY KEY TO CONTINUE \n");
            fflush(stdin);
            o=getch();
        }

    }
    printf(" Validos %d",i);
    *validos=i;
    printf("%d",*validos);
    return *a;
}


void mostrar_array(int *a,int  *validos)
{
    printf("ENTRE ");
    printf("VALIDOS EN MOSTRAR %d \n",*validos);
    int j=0;
    printf("%d",a[0]);
    int  i = *validos;
    while(j<i)
    {
        printf("%d \n", a[j]);
        j++;
    }
}
