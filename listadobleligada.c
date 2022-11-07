#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int val;
    struct nodo *siguiente;
    struct nodo *atras;
};
//Ya quedaron
void inicializarLista(struct nodo *inicio);
struct nodo* insertarNodo(struct nodo *inicio, int num, int pos);
int longitudLista(struct nodo *inicio);
void recorrerLista(struct nodo *inicio);
void recorrerAlrevez(struct nodo *inicio);
int listaVacia(struct nodo *elemento);
struct nodo* eliminarLista(struct nodo *inicio);
struct nodo * borrarNodosVal(struct nodo *inicio, int val);
void buscarElementos(struct nodo *inicio, int val);
struct nodo * conversionLista(int val[], int lon);
//TODO:
struct nodo * borrarMultiplesNodos(struct nodo *inicio, int val);
struct nodo * anadirMultiplesNodos(struct nodo *inicio, int val[], int pos, int lon);



void main(void)
{
    struct nodo *inicio = NULL;
    struct nodo *prueba;
    int a[] = {1,2,3} ;

    inicio = insertarNodo(inicio, 2, 0);
    inicio = insertarNodo(inicio, 1, 0);
    inicio = insertarNodo(inicio,3, 2);
    inicio = insertarNodo(inicio,4, 1);
    inicio = insertarNodo(inicio,3, 2);
    inicio = insertarNodo(inicio,4, 1);
    inicio = insertarNodo(inicio,4, 1);
    inicio = borrarNodosVal(inicio, 3);
    inicio = borrarNodosVal(inicio, 4);
    recorrerLista(inicio);
    printf("\n");
    inicio = anadirMultiplesNodos(inicio, a, 2, 3);
    recorrerLista(inicio);
    printf("\n");
    recorrerAlrevez(inicio);
    printf("\n");
    recorrerLista(inicio);
    buscarElementos(inicio, 3);
    printf("%d", longitudLista(inicio));
    inicio = eliminarLista(inicio);



}

int listaVacia(struct nodo *elemento)
{
    if (elemento == NULL)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

void inicializarLista(struct nodo *inicio)
{
    inicio = NULL;
}

struct nodo* insertarNodo(struct nodo *inicio, int num, int pos)
{
    //Insertar elemento si la lista esta vacia
    if(listaVacia(inicio) == 0)
    {   
        inicio = malloc(sizeof(struct nodo));
        inicio->val = num;
        inicio->siguiente = NULL;
        inicio->atras = NULL;
        return inicio;

    }
    //Cuando hay dos elementos y uno es null y el otro no
    struct nodo *elemento = inicio;
    for (int i = 0; i < pos; i++)
    {
        if(elemento->siguiente == NULL)
        {
            break;
        }

        elemento = elemento->siguiente;
    }
    
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    
    //Insertar elementos si uno de los elementos no esta ligado de manera adecuada

    if(elemento->siguiente == NULL)
    {

        elemento->siguiente = nuevo;
        elemento->atras = nuevo;
        nuevo->siguiente= elemento;
        nuevo->atras = elemento;
        nuevo->val = num;
        if (pos == 0)
            return nuevo;
        else
            return inicio;
    }

    //Insertar elemento si la lista ya está bien ligada con dos elementos
    nuevo->siguiente = elemento;
    nuevo->atras = elemento->atras;
    elemento->atras->siguiente = nuevo;
    elemento->atras = nuevo;
    nuevo->val = num;

    return inicio;

}

int longitudLista(struct nodo *inicio)
{
    if (listaVacia(inicio) == 0)
        return 0;

    int cont = 1;
    struct nodo *elemento = inicio;
    do 
    {
        elemento = elemento->siguiente;
        cont++;
    } while (elemento != inicio);
    return cont;

}

void recorrerLista(struct nodo *inicio)
{
    struct nodo *elemento = inicio;

    do 
    {
        printf("%i \t", elemento->val);
        elemento = elemento->siguiente;
    } while (elemento != inicio);

}
void recorrerAlrevez(struct nodo *inicio)
{
    struct nodo *elemento = inicio->atras;

    while (elemento != inicio)
    {
        printf("%i \t", elemento->val);
        elemento = elemento->atras;
    }
    printf("%i", elemento->val);

}

struct nodo* eliminarLista(struct nodo *inicio)
{
    struct nodo *elemento = inicio;

    while(elemento != inicio->atras)
    {
        elemento = elemento->siguiente;
        free(elemento->atras);
    }
    free(elemento);
    elemento = NULL;
    return elemento;

}

struct nodo * borrarNodosVal(struct nodo *inicio, int val)
{
    //Si la lista esta vacia se termina esto
    if (listaVacia(inicio) == 0)
        return inicio;
    
    //Si la lista solo tiene un elemento se regresa inicio y 
    if (inicio->siguiente == NULL && inicio->val == val)
    {
        free(inicio);
        inicio = NULL;
        return inicio;
    }

    else if (inicio->siguiente == NULL)
        return inicio;
    
    
    struct nodo *elemento = inicio;

    if (inicio->val == val)
    {
        inicio = inicio->siguiente;
        elemento->atras->siguiente = inicio;
        inicio->atras = elemento->atras;
        free(elemento);
        return inicio;
    }

    while (elemento != inicio->atras)
    {
        if(elemento->val == val)
        {
            elemento->atras->siguiente = elemento->siguiente;
            elemento->siguiente->atras = elemento->atras;
            free(elemento);
            return inicio;
        }
        elemento = elemento->siguiente;
    }

    if(elemento->val == val)
    {
        elemento->atras->siguiente = elemento->siguiente;
        elemento->siguiente->atras = elemento->atras;
        free(elemento);
        return inicio;
    }
    return inicio;
}

void buscarElementos(struct nodo *inicio, int val)
{
    struct nodo *elemento = inicio;
    int i = 1;
    printf("\n\n");
    if(elemento->val == val)
        printf("Posicion 0\n");
    
    elemento = elemento->siguiente;
    while (elemento != inicio)
    {
        if (elemento->val == val)
        {
            printf("Posicion %i\n", i);
        }
        elemento = elemento->siguiente;
        i++;
    }

}

struct nodo * anadirMultiplesNodos(struct nodo *inicio, int val[], int pos, int lon)
{
    //Definir Variables
    struct nodo *elemento = inicio;
    struct nodo *inicio_lista = conversionLista(val, lon);


    //Caso si la posicion es mayor a la longitud
    if (pos > longitudLista(inicio))
        printf("Ingresa una posicion menor a la longitud de la lista");
        return inicio;
            printf("Hola");
    //Caso si la lista esta vacía
    if (listaVacia(inicio) == 0)
        return inicio_lista;
    
    //Caso Base
    for (int i = 0; i < lon; i++)
    {

        elemento = elemento->siguiente;
    }
    struct nodo *temporal;
    
    //Nodo de al final de la lista que apunte al elemento
    inicio_lista->atras->siguiente = elemento;
    //Nodo de atras de elemento que apunte 
    elemento->atras->siguiente = inicio_lista;
    //Se pone el temporal para intercambiar nodo de atras con lista Inicial
    temporal = elemento->atras;
    //Se iguala el nodo de elemento atras al inicio de la lista
    elemento->atras = inicio_lista->atras;
    //Se iguala el inicio de la lista con el elemnto de atras
    inicio_lista->atras = temporal;
    

    return inicio;
}


struct nodo * conversionLista(int val[], int lon)
{
    struct nodo *inicio = malloc(sizeof(struct nodo));  
    inicio->val = val[0];
    inicio->siguiente = inicio;
    inicio->atras = inicio;
    struct nodo *elemento = inicio;



    for (int i = 1; i < lon; i++)
    {
        struct nodo *nuevo = malloc(sizeof(struct nodo));
        elemento->siguiente = nuevo;
        nuevo->atras = elemento;
        nuevo->siguiente = inicio->atras;
        inicio->atras = nuevo;
        nuevo->val = val[i];
        elemento = nuevo;
        
 
    }

    return inicio;

}