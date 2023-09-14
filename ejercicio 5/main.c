#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define color system("COLOR B")
#include <time.h>



/** Escribir un programa que permita generar una lista con números aleatorios entre 1 y 100 de por lo menos 50 elementos.
Una vez generada la lista, recorrerla para guardar en un arreglo dinámico de 10 elementos (inicialmente), todos los números pares de la lista
y en un archivo binario, todos los números impares. Finalmente mostrar el archivo, el arreglo dinámico y eliminar la lista. Modularizar.
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
lista *borrar_lista(lista *list);
void mostrar(lista *list);
void mostrar_archivo(FILE *archi);
int *cargar_arreglo(int *a,lista *list,int *dim,int *h,FILE *archi );
int main()
{
    color;
    FILE *archi=fopen("ARCH","a+b");
    if(archi)
    {
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
        int *a=NULL;
        int i=0;
        printf("\n");
        int dim=0;
        int k=0;
        a=cargar_arreglo(a,list,&dim,&i,archi);
        while(k<i)
        {
            printf(" %d  ",a[k]);
            k++;
        }
        mostrar_archivo(archi);
        list=borrar_lista(list);
        mostrar(list);
    }
    else
    {
        printf("ERROR AL ABRIR ARCHIVO \n");
    }
    fclose(archi);
    return 0;
}


lista *iniclista()
{
    return NULL;
}

int *cargar_arreglo(int *a,lista *list,int *dim,int *h,FILE *archi )
{
    archi=fopen("ARCH","a+b");
    int numero=0;
    lista *seg=list ;
    int i=0;
    a=(int *)malloc(10*sizeof(int));
    *dim=10 ;
    if(archi)
    {
        if(seg)
        {
            while(seg!=NULL)
            {
                if(seg->num%2==0)
                {
                    if( i>=  *dim)
                    {
                        a=(int*)realloc(a,( *dim+10)*sizeof(int));
                        *dim+=10;
                    }

                    a[i]=seg->num;
                    i++;


                }
                else
                {
                    if(seg->num %2 !=0){
                    numero=seg->num;
                    fwrite(&numero,sizeof(int),1,archi);
                }
                }
                seg=seg->siguiente;
            }
        }
        *h=i;
    }
    else
    {
        printf("ERROR AL ABRIR ARCHIVO \n");
    }
    fclose(archi);
    return a;
}


void mostrar_archivo(FILE *archi)
{
int numero;
    archi=fopen("ARCH","r+b");
    if(archi){
            printf(" \nNUMEROS IMPARES \n");
while(fread(&numero,sizeof(int),1,archi)>0){

    printf("%d ",numero);
}

    }
    else{
        printf("ERROR EN EL ARCHIVO \n");
    }
}



lista *crear_nodo(int numero)
{

    lista *nuevo = (lista*)malloc(sizeof(lista));
    nuevo->siguiente =NULL;
    nuevo->num=numero;


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
lista *borrar_lista(lista *list)
{




    lista *aux=list;
    if(list)
    {
while(list!=NULL){
        aux=list;
        list=list->siguiente;
        free(aux);

}

    }
    if(list==NULL){
        printf("\nLista eliminada\n");
    }


    return list ;
}
