#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define color system("COLOR B")
#include <time.h>



/**– Escribir un programa que permita crear una lista con números enteros y luego buscar y eliminar todos los nodos que coincidan con la búsqueda de uno de ellos.
Tener en cuenta que al buscar un determinado número, el mismo puede aparecer mas de una vez.
Por lo cual se deben eliminar todas sus ocurrencias y luego informar cuantos nodos fueron eliminados.
*/



typedef struct _lista
{
    int num;
    struct _lista *siguiente;

} lista;

///PROTOTIPADO
lista *agregar__principio(lista *list, lista *nuevo);
lista *iniclista();
lista * agregar__final(lista *list, lista*nuevo);
lista *buscar_ultimo(lista *list);
lista *buscar_nodo(lista *list,int dato);
lista *crear_nodo(int numero);
lista *borrar(lista *list,int dato,int *cont);
void mostrar(lista *list);


int main()
{
    color;
    lista *list =iniclista();
    lista *nuevo=iniclista();
    nuevo=crear_nodo(4);
    list= agregar__final(list,nuevo);
    nuevo=crear_nodo(6);
    list= agregar__final(list,nuevo);
srand(time(NULL));
    for (int i=50; i>0; i-- )
    {
        int num=rand()%100+1;
        nuevo=crear_nodo(num);
        list= agregar__final(list,nuevo);

    }
    mostrar(list);
    /// system("cls");
    system("pause");
    int  cont=0;
    int dato;
    printf("Ingrese dato a buscar \n ");
    scanf("%d",&dato);
    printf("\n\n");
    list =borrar(list,dato, &cont);
    mostrar(list);
    printf("EL CONTADOR ES: %d",  cont);

    return 0;
}

lista *iniclista()
{
    return NULL;
}

lista *crear_nodo(int numero)
{

    lista *nuevo = (lista*)malloc(sizeof(lista));
    nuevo->siguiente =NULL;
    nuevo->num=numero;
    printf("ENTRE CREAR NODO \n");

    return nuevo;
}

lista *agregar__principio(lista *list, lista *nuevo)
{

    if(list ==NULL)
    {

        list=nuevo;

    }
    else
    {
        nuevo->siguiente= list;
        list =nuevo;


    }
    return list;
}

lista *buscar_ultimo(lista *list)
{
    lista *seg=list;

    if(seg)
    {

        while(seg ->siguiente !=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return  seg;
}

lista * agregar__final(lista *list, lista*nuevo)
{

    lista *ultimo =buscar_ultimo(list);

    if(list==NULL)
    {
        list=nuevo;
    }
    else
    {
        ultimo->siguiente=nuevo;
    }
    return list;
}

lista *buscar_nodo(lista *list,int dato)
{

    lista *seg=list ;

    if(seg)
    {
        while(seg->siguiente!=NULL && dato!= seg->num)
        {
            seg=seg->siguiente;
        }


    }
    return seg;
}


void mostrar(lista *list)
{

    lista *seg=list ;

    while(seg !=NULL)
    {
        printf("%d \n",seg->num);
        seg=seg->siguiente;
    }
}

lista *borrar(lista *list,int dato,int *cont)
{

    lista *seg=list;
    lista *ante=list;
    int i=0;
    lista *aux=list ;
    if(list  && dato== seg->num)
    {
        i++;
        aux=list;
        list=list->siguiente;
        free(aux);
    }
    seg = list;
    while(seg!=NULL)
    {
        lista *seg2=list;

        while((seg2 != NULL) &&  dato != seg2->num)
        {
            ante = seg2;
            seg2 = seg2->siguiente;
        }

        if(seg2!=NULL)
        {
            ante->siguiente = seg2->siguiente;
            free(seg2);
            i++;


        }
        seg=seg->siguiente;


    }
    if(list==NULL)
    {
        printf("NO HAY DATOS EN LA LISTA \n");
    }
    *cont= i;
    return list ;
}

