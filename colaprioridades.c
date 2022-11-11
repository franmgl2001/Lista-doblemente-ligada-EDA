#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int valor;
    struct nodo *siguiente;
};
//DOne
int colaVacia(struct nodo *inicio);
struct nodo * inicializarCola(struct nodo *elemento);
void recorrerCola(struct nodo *inicio);
int tamanoCola(struct nodo *inicio);
struct nodo *desenque(struct nodo *inicio);
struct nodo * enque(struct nodo *inicio, int val);
struct nodo *encontrarNodo(struct nodo *inicio, int val);
struct nodo *encontrarPos(struct nodo *inicio,int pos);
struct nodo *eliminarCola(struct nodo *actual);
struct nodo * enqueMultiple(struct nodo *inicio, int tam, int val[]);




void main(void)
{
    
    struct nodo *inicio;
    inicio = inicializarCola(inicio);
    inicio = enque (inicio, 5);
    inicio = enque (inicio, 3);
    inicio = enque (inicio, 4);
    inicio = enque(inicio, 6);
    inicio = enque(inicio, 1);
    inicio = enque(inicio, 1);
    inicio = enque(inicio, 9);
    inicio = desenque(inicio);
    encontrarNodo(inicio, 10);
    encontrarPos(inicio, 2);
    recorrerCola(inicio);
    int i[] = {10,11,15};
    inicio = enqueMultiple(inicio, 3, i);
    printf("\n");
    recorrerCola(inicio);
    //encontrarNodo(inicio, 3);

    printf("\n%d", tamanoCola(inicio));

    inicio = eliminarCola(inicio);


    

}

int colaVacia(struct nodo *inicio)
{
    if (inicio == NULL)
    {
        return 0;
    }

    return 1;
}

struct nodo *inicializarCola(struct nodo *inicio)
{
    inicio = NULL;
    return inicio;
}

struct nodo *enque (struct nodo *inicio, int val)
{   
    //Caso de cola vacia
    if (colaVacia(inicio) == 0)
    {
        inicio = malloc(sizeof(struct nodo));
        inicio->siguiente = NULL;
        inicio->valor = val;

        return inicio;
    }
    //Caso en que este al inicio 

    if (inicio->valor >= val)
    {
        struct nodo *nuevo = malloc(sizeof(struct nodo));
        nuevo->valor = val;
        nuevo->siguiente = inicio;
        return nuevo;
    }

    struct nodo *actual = inicio;
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    
    while (actual->siguiente != NULL)
    {
        if(actual->siguiente->valor >= val)
        {
            nuevo->valor = val;
            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
            return inicio;
        }
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->valor = val;
    nuevo->siguiente = NULL;
    return inicio;
}   

void recorrerCola(struct nodo *elemento)
{
    while (elemento != NULL){

        printf("%d\t", elemento->valor);
        elemento = elemento->siguiente;
    }
    
}

int tamanoCola(struct nodo *elemento)
{
    int val = 0;
    while (elemento != NULL)
    {
        val++;
        elemento = elemento->siguiente;
    }
    return val;
    
}

struct nodo *desenque(struct nodo *inicio)
{
    struct nodo *elemento = inicio->siguiente;
    free(inicio);
    return elemento;

}

struct nodo *encontrarNodo(struct nodo *inicio, int val)
{
    struct nodo *elemento = inicio;
    int cont = 0;
    while (elemento != NULL)
    {
        if(elemento->valor == val)
        {
            printf("Este nodo se encuentra en la poscion: %d\n", cont);
            return elemento;
        }
        cont++;
        elemento = elemento->siguiente;
    }
    printf("No se encontro el nodo\n");
    return NULL;
}

struct nodo *encontrarPos(struct nodo *inicio, int pos)
{
    if (tamanoCola(inicio) <= pos)
    {
        printf("La posicion mandada es mayor al tamanio de la cola\n");
        return NULL;
    }
    int cont = 0;
    while (inicio != NULL)
    {
        if (cont == pos)
        {
            printf("El valor de la posicion dada es: %d\n", inicio->valor);
            return inicio;
        }
            
        cont++;
        inicio = inicio->siguiente;
    }
}

struct nodo *eliminarCola(struct nodo *actual)
{
    struct nodo *anterior = NULL;
    while (actual != NULL)
    {
        anterior = actual;
        actual = actual->siguiente;
        free(anterior);
    }
    return actual;
}

struct nodo *enqueMultiple(struct nodo *inicio, int tam, int val[])
{
    for (int i = 0; i < tam; i++)
    {
        inicio = enque(inicio, val[i]);
    }

    return inicio;

}