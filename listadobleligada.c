#include <stdio.h>
#include <stdlib.h>

//ESTRUCTURA DE DATOS
struct nodo{
    int val;
    struct nodo *siguiente;
    struct nodo *atras;
};

//Prototipo de funciones
void inicializarLista(struct nodo *inicio);
struct nodo* insertarNodo(struct nodo *inicio, int num, int pos);
int longitudLista(struct nodo *inicio);
void recorrerLista(struct nodo *inicio);
void recorrerAlrevez(struct nodo *inicio);
int listaVacia(struct nodo *elemento);
struct nodo* eliminarLista(struct nodo *inicio);
void buscarElementos(struct nodo *inicio, int val);
struct nodo * conversionLista(int val[], int lon);
struct nodo * borrarMultiplesNodos(struct nodo *inicio, int val);
struct nodo * anadirMultiplesNodos(struct nodo *inicio, int val[], int pos, int lon);
struct nodo * borrarNodosVal(struct nodo *inicio, int val);
struct nodo *cambiarInicio(struct nodo *inicio, int pos);





void main(void)
{
    struct nodo *inicio = NULL;
    int a[] = {1,2,3} ;

    
    inicio = insertarNodo(inicio, 10, 2);
    inicio = insertarNodo(inicio, 4, 0);

    inicio = anadirMultiplesNodos(inicio, a, 0, 3);
    inicio = anadirMultiplesNodos(inicio, a, 1, 3);

    recorrerLista(inicio);
    printf("\n");
    insertarNodo(inicio, 11, 6);
    printf("\n");
    recorrerLista(inicio);
    insertarNodo(inicio, 15, 15);
    inicio = cambiarInicio(inicio,4);
    printf("\n");
    recorrerLista(inicio);
    buscarElementos(inicio, 2);
    borrarNodosVal(inicio, 15);
    inicio = borrarNodosVal(inicio, 1);
    inicio = borrarNodosVal(inicio, 1);
    printf("\n");
    recorrerLista(inicio);
    inicio = eliminarLista(inicio);



}

int listaVacia(struct nodo *elemento)
{
    //CHECA QUE LA LISTA ESTE VACIAS SI EL ELEMENTO ES NULO
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
    //INICIALIZA LA LISTA EN NULL
    inicio = NULL;
}

struct nodo* insertarNodo(struct nodo *inicio, int num, int pos)
{
    //CASO 1
    //Insertar elemento si la lista esta vacia
    if(listaVacia(inicio) == 0)
    {   
        //ALLOCAR NODO
        inicio = malloc(sizeof(struct nodo));
        struct nodo *inicio = malloc(sizeof(struct nodo));  
        if (inicio == NULL)
        {
        printf("El nodo no se pudo alocar ");
        return inicio;
        }
        inicio->val = num;
        //SE PONEN EN SIGUIENTE Y DESPUES 
        inicio->siguiente = inicio;
        inicio->atras = inicio;
        return inicio;

    }

    // Caso de insertar al comienzo
    if (pos == 0)
    {
        //SE ALOCA EL NODO
        struct nodo *nuevo = malloc(sizeof(struct nodo));
        if (nuevo == NULL)
        {
            printf("El nodo no se pudo alocar ");
            return inicio;
        }
        nuevo->val = num;
        //SE INSERTA
        nuevo->siguiente = inicio;
        nuevo->atras = inicio->atras;
        inicio->atras->siguiente = nuevo;
        inicio->atras = nuevo;
        //SE REGRESA LA POSICION NUEVA COMO INICIO
        return nuevo;
    }
    //Caso Base
    struct nodo *elemento = inicio;
    int i = 0;

    // Recorrer elementos hasta llegar a la posicion donde se quiere insertar el codigo
    do
    {

        elemento = elemento->siguiente;
        i++;
    } while (elemento != inicio && pos != i);
    
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    if (nuevo == NULL)
    {
        printf("El nodo no se pudo alocar ");
        return inicio;
    }
    
    //SE ALOCA e INSERTA EL NODO 
    nuevo->siguiente = elemento;
    nuevo->atras = elemento->atras;
    elemento->atras->siguiente = nuevo;
    elemento->atras = nuevo;
    nuevo->val = num;

    return inicio;

}

int longitudLista(struct nodo *inicio)
{
    //SE CHECA SI LA LISTA ESTA VACIA
    if (listaVacia(inicio) == 0)
        return 0;

    int cont = 1;
    struct nodo *elemento = inicio;
    //SE RECORRE LA LISTA HASTA LLEGAR AL FINAL (se cuenta en cada iteracion)
    do 
    {
        elemento = elemento->siguiente;
        cont++;
    } while (elemento != inicio);
    //Se regresa el contador
    return cont;

}

void recorrerLista(struct nodo *inicio)
{
    //Se 
    struct nodo *elemento = inicio;
    //SE RECORRE LA LISTA LIGADA
    do 
    {
        printf("%i \t", elemento->val);
        elemento = elemento->siguiente;
    } while (elemento != inicio);

}
void recorrerAlrevez(struct nodo *inicio)
{
    struct nodo *elemento = inicio->atras;
    //Se recorre la lista con el apuntador de atras
    do 
    {
        printf("%i \t", elemento->val);
        elemento = elemento->atras;
    }while (elemento != inicio->atras);

}

struct nodo* eliminarLista(struct nodo *inicio)
{
    struct nodo *elemento = inicio;
    // SE recorre la lista y en cada iteracion se hace free en cada 
    do
    {
        elemento = elemento->siguiente;
        free(elemento->atras);
    } while (elemento != inicio);
    free(elemento);
    elemento = NULL;
    return elemento;

}

struct nodo * borrarNodosVal(struct nodo *inicio, int val)
{
    //CASO 0 ELIMINAMOS SI LA LISTA ESTA VACIA
    if (listaVacia(inicio) == 0)
        return inicio;
    
    //CASO 1 ELIMINAMOS SI SOLO HAY UN ELEMENTO
    if (inicio->siguiente == inicio && inicio->val == val)
    {
        // LO eliminamos 
        free(inicio);
        inicio = NULL;
        return inicio;
    }
    
    
    struct nodo *elemento = inicio;
    //CASO 2 ELIMINAMOS PRIMER ELEMENTO
    if (inicio->val == val)
    {
        inicio = inicio->siguiente;
        elemento->atras->siguiente = inicio;
        inicio->atras = elemento->atras;
        free(elemento);
        return inicio;
    }
    //Caso 3 ELIMINAMOS CUALQUIER OTRO NUMERO
    //recoremos la lista
    do 
    {
        
        if(elemento->val == val)
        {
            elemento->atras->siguiente = elemento->siguiente;
            elemento->siguiente->atras = elemento->atras;
            free(elemento);
            return inicio;
        }
        elemento = elemento->siguiente;
    }while (elemento != inicio->atras);

    return inicio;
}

void buscarElementos(struct nodo *inicio, int val)
{
    struct nodo *elemento = inicio;
    int i = 0;
    //BUCLE DO WHILE Para recorrer
    do 
    {
        //SE imprime si se encuentra el elemento
        if (elemento->val == val)
        {
            printf("Posicion %i\n", i);
        }
        elemento = elemento->siguiente;
        i++;
    } while (elemento != inicio);

}

struct nodo * anadirMultiplesNodos(struct nodo *inicio, int val[], int pos, int lon)
{
    //Definir Variables
    struct nodo *elemento = inicio;
    struct nodo *inicio_lista = conversionLista(val, lon);
    
    //Caso si la lista esta vacía
    if (listaVacia(inicio) == 0)
        return inicio_lista;
    
    //Caso si esta al frente de la lista
    if (pos == 0)
    {
        elemento = elemento->atras;
        inicio->atras = inicio_lista->atras;
        elemento->siguiente = inicio_lista;
        inicio_lista->atras->siguiente = inicio;
        inicio_lista->atras = elemento;
        return inicio_lista;
    }
    //Caso Base
    int i = 0;
    do
    {
        elemento = elemento->siguiente;
        i++;
        
    } while (inicio != elemento && pos != i);
    
    
    struct nodo *temporal;
    
    temporal = elemento->atras;
    elemento->atras = inicio_lista->atras;
    temporal->siguiente = inicio_lista;
    inicio_lista->atras->siguiente = elemento;
    inicio_lista->atras = temporal;

    

    return inicio;
}


struct nodo * conversionLista(int val[], int lon)
{
    // SE CREA LA LISTA LIGADA
    struct nodo *inicio = malloc(sizeof(struct nodo));  
    if (inicio == NULL)
    {
        printf("El nodo no se pudo alocar ");
        return inicio;
    }
    inicio->val = val[0];
    inicio->siguiente = inicio;
    inicio->atras = inicio;
    struct nodo *elemento = inicio;


    // SE AÑADEN LOS DEMAS NODOS A LA LISTA
    for (int i = 1; i < lon; i++)
    {
        struct nodo *nuevo = malloc(sizeof(struct nodo)); 
        if (nuevo == NULL)
        {
            printf("El nodo no se pudo alocar ");
            return inicio;
        }
        elemento->siguiente = nuevo;
        nuevo->atras = elemento;
        nuevo->siguiente = inicio;
        inicio->atras = nuevo;
        nuevo->val = val[i];
        elemento = nuevo;
        
 
    }

    return inicio;

}

struct nodo * borrarMultiplesNodos(struct nodo *inicio, int val)
{

    //Si la lista esta vacia se termina esto
    if (listaVacia(inicio) == 0)
        return inicio;
    
    //Si la lista solo tiene un elemento se regresa inicio y 
    if (inicio->siguiente == inicio && inicio->val == val)
    {
        free(inicio);
        inicio = NULL;
        return inicio;
    }
    
    
    struct nodo *elemento = inicio;

//TODO CHECAR QUE FUNCIONE EL CASO DE BORRAR INICIO
    while (inicio->val == val)
    {
        
        inicio = inicio->siguiente;
        elemento->atras->siguiente = inicio;
        inicio->atras = elemento->atras;
        elemento->siguiente = NULL;
        elemento->atras = NULL;
        free(elemento);
        elemento = inicio;
        
    }
    
    elemento = inicio;
    struct nodo *temporal;
    do 
    {
        if(elemento->val == val)
        {
            temporal = elemento;
            elemento = elemento->siguiente;
            temporal->atras->siguiente = temporal->siguiente;
            temporal->siguiente->atras = temporal->atras;
            free(temporal);

        }
        else
        {
            elemento = elemento->siguiente;
        }
        
    } while(elemento != inicio);
    printf("\n\n");
    recorrerLista(inicio);
    printf("\n");
    return inicio;
}

//CAMBIA EL PUNTO DE INICIO DE LA LISTA
struct nodo *cambiarInicio(struct nodo *inicio, int pos)
{
    int i = 1;
    do{

        inicio = inicio->siguiente;
        i++;
    }while (i != pos);
    return  inicio;
}