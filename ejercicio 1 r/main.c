#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define color system("COLOR B")
#define ESC 27

typedef struct
{
    char nombre[30];
    int edad;
} Persona;

typedef struct _list
{
    Persona pers;
    struct _list *siguiente;

} list;

///PROTOTIPADO
void cargar_archivo(FILE *archi,Persona per);
void mostrar_lista(list *lista);
list *crear_nodo(Persona per );
list * cargar_lista(FILE *archi,list *lista);
list *agregar_alPpio(list*lista,list*nuevo);
list *iniclista();
list * ordenar(list *lista);
int buscar(list*lista,char nombre[30]);

int main()
{
    color;
    Persona per ;
    FILE* archi =fopen("ARCH","a+b");
    list* lista=iniclista();

    if(archi)
    {
      ///  cargar_archivo(archi,per );
        lista=cargar_lista(archi,lista);
        mostrar_lista(lista);
       /// lista=ordenar(lista);
        system("cls");
        mostrar_lista(lista);
        char nombre[30]="Gasty";
        int num= buscar(lista,nombre);
        printf(" EL RESULTADO ES %d",num );

    }
    else
    {
        printf("ERROR EN ARCHIVO \n");
    }
    fclose(archi);
    return 0;
}


void cargar_archivo(FILE *archi,Persona per )
{
    char o=0;
    archi=fopen("ARCH","a+b");

    if(archi)
    {
        while(o!=27)
        {
            printf("Ingrese nombre \n");
            fflush(stdin);
            gets(per.nombre);
            printf("Ingrese edad \n");
            scanf("%d",&per.edad);

            printf("PRESIONE ESC PARA SALIR O ANY KEY TO CONTINUE \n");
            fflush(stdin);
            o=getch();
            fwrite(&per,sizeof(Persona),1,archi);
        }
    }
    else
    {
        printf("ERROR \n");
    }
    fclose(archi);
}

list *iniclista()
{
    return NULL;
}

list *crear_nodo(Persona per )
{
    list *nuevo=(list*)malloc(sizeof(list));

    nuevo->siguiente=NULL;
    nuevo->pers=per ;
    return nuevo;
}

list *agregar_alPpio(list*lista,list*nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;

    }
    else
    {

        nuevo ->siguiente = lista;
        lista = nuevo ;

    }


    return lista;

}

list * cargar_lista(FILE *archi,list *lista)
{

    Persona per;
    archi=fopen("ARCH","r+b");
    while(fread(&per,sizeof(Persona),1,archi)>0)
    {
        lista= agregar_alPpio(lista,crear_nodo(per));

    }


    fclose(archi);
    return lista;
}

void mostrar_lista(list *lista)
{

    list *seg=lista;


    while(seg !=NULL)
    {

        printf("NOMBRE: %s \n",seg->pers.nombre);
        printf("EDAD: %d \n",seg->pers.edad);

        seg=seg->siguiente;
    }
}



list * ordenar(list *lista){

 list *seg=lista;
 list*ante=lista;
    list *aux=iniclista();

if(lista==NULL){
    printf("LISTA VACIA \n");
}
else{
    while(seg!= NULL && ante->pers.edad > seg->pers.edad ){
        aux=seg;
        seg=ante;
        ante=aux;
        seg=seg->siguiente;
        ante->siguiente=seg;
        aux=aux->siguiente;
    }
}

return aux;
}


int buscar(list*lista,char nombre[30]){
list *seg=lista;
int flag=0;
while( seg  !=NULL)
{
    if(strcmpi(seg->pers.nombre,nombre)==0){
            printf("ENTRE IF");
    flag=1;
    }

    seg=seg->siguiente;


}

return flag;
}

