#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define color system("COLOR B")
#define ESC 27
#include "Firma.h"
#define DIM 10


/**
Escribir un programa que lea edades de un arreglo dinámico de 10 posiciones para combinarlas con 10 nombres leídos de otro arreglo estático
de 10 posiciones. Una vez leídos ambos datos, debe generar un registro con esa info,
el cual será agregado a una lista ordenada que finalmente mostrará por pantalla.
Luego, guardar esa lista en un archivo de texto o binario y eliminar la lista.
 Finalmente mostrar el archivo resultante. Modularizar.  
*/

typedef struct
{

    char nombre[30];
    int num;
} Persona;

typedef struct _listadePersonas
{
    Persona perso;
    struct _listadePersonas *siguiente;
} ListadePersonas;

///PROTOTIPADO
ListadePersonas * iniclista ();
ListadePersonas *crear_nodo(Persona pers);
ListadePersonas *agregar_principio(ListadePersonas *lista, ListadePersonas *nuevo);
ListadePersonas *integrar_lista(ListadePersonas *lista,int *a_edad, Persona arreglo[DIM]);
ListadePersonas *borrar_lista(ListadePersonas*lista);
ListadePersonas *borrar_lista(ListadePersonas*lista);
Persona cargar_arreglo_nombres(Persona arreglo[DIM]);
void cargar_arreglo_edad(int *a_edad);
void mostrar_lista(ListadePersonas* lista);
void cargar_archivo(FILE *archi,ListadePersonas *lista);
void mostrar_archivo (FILE *archi);

int main()
{

    color;

    FILE *archi=fopen("ARCH","a+b");

    if(archi)
    {
        Persona arreglo[DIM];
        int *a_edad;
        ListadePersonas *lista=iniclista();

///Inicializo arreglo edades con malloc a 10 datos
        a_edad=(int*)malloc(10*sizeof(int));
///Carga de arreglos
        cargar_arreglo_edad(a_edad);
        cargar_arreglo_nombres(arreglo);
///Carga listas

        lista= integrar_lista(lista,a_edad,arreglo);

        mostrar_lista(lista);
        cargar_archivo(archi,lista);
        printf("MUESTRA ARCHIVO \n");
        mostrar_archivo(archi);
        lista= borrar_lista(lista);
        printf("MUESTRA LISTA BORRADA \n");
        mostrar_lista(lista);

        firma();
    }
    else
    {
        printf("ERROR EN EL ARCHIVO \n");
    }
    fclose(archi);
    return 0;
}

void cargar_arreglo_edad(int *a_edad )
{
    int numero;
    int i=0;
    while(  i<10)
    {

        printf("Ingrese edad \n");
        scanf("%d",&numero);
        a_edad[i]=numero;
        i++;


    }

}

Persona cargar_arreglo_nombres(Persona arreglo[DIM])
{
    int i=0;
    Persona pers;
    while(i<10)
    {
        printf("INGRESE NOMBRE \n");
        fflush(stdin);
        gets(pers.nombre);
        pers.num=0;
        arreglo[i]=pers;
        i++;
    }
    return arreglo[DIM];
}

ListadePersonas * iniclista ()
{
    return NULL;
}



ListadePersonas *crear_nodo( Persona pers)
{
    ListadePersonas *nuevo= (ListadePersonas*)malloc(sizeof(ListadePersonas));
    nuevo->perso= pers;
    nuevo ->siguiente=NULL;
    return nuevo;
}

ListadePersonas *agregar_principio(ListadePersonas *lista, ListadePersonas *nuevo)
{
    if(lista==NULL)
    {

        lista =nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}



ListadePersonas *integrar_lista(ListadePersonas *lista,int *a_edad, Persona arreglo[DIM])
{
    int i=0;
    Persona pers;

    while(i<10)
    {
        strcpy(pers.nombre,arreglo[i].nombre);
        pers.num=a_edad[i];
        lista=agregar_principio(lista,crear_nodo( pers));

        i++;
    }
    return lista;
}

void  mostrar_lista(ListadePersonas* lista)
{
    ListadePersonas *seg=lista;
    if(seg==NULL)
    {
        printf(" LA LISTA NO TIENE DATOS\n");
    }
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            printf(" nombre %s y edad %d \n",seg->perso.nombre,seg->perso.num);
            seg=seg->siguiente;
        }
    }
}

void cargar_archivo(FILE *archi,ListadePersonas *lista)
{
    archi=fopen("ARCH","a+b");
    ListadePersonas *seg=lista;
    if (archi)
    {
        while(seg!=NULL)
        {
            fwrite(&seg->perso,sizeof(Persona),1,archi);
            seg=seg->siguiente;
        }
    }
    else
    {
        printf("ERROR AL ABRIR ARCHIVO \n");
    }
    fclose(archi);
}

void mostrar_archivo (FILE *archi)
{
    archi=fopen("ARCH","r+b");
    Persona pers;
    if (archi)
    {

        while(fread(&pers,sizeof(Persona),1,archi)>0)
        {
            printf(" Nombre: %s \n Edad: %d \n",pers.nombre,pers.num);
        }
    }
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO");
    }
    fclose(archi);
}

ListadePersonas *borrar_lista(ListadePersonas*lista)
{

    ListadePersonas *seg=lista;
    ListadePersonas *proximo=lista;

    if(seg== NULL)
    {

        free(seg);
    }
    else
    {

        while(seg!=NULL)
        {
            proximo = seg->siguiente;
            free(seg);
            seg = proximo;

        }
    }
    return seg;
}


