#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

//*nuevoNodo esta de esta manera porque devuelve un puntero hacia un struct nodo
struct Nodo *nuevoNodo(int dato){
    //Solicitar memoria obtiene el tamaño en bytes que necesita la estructura
    size_t tamanioNodo = sizeof(struct Nodo);
    //se crear un puntero hacia un nodo y se solicita memoria dinamica con malloc
    //aqui (struct Nodo *) es para hacver type casting y convertir lo de malloc
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    //Asignar el dato e iniciar hojas
    nodo->dato = dato;
    //cada nodo izquierdo y derecho esta iniocializado en null bueno ams bien los punteros que almacenan la direccion de los otros nodos
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato) {
    //Izquierda o derecha?
    //Si es mayor va a la derecha
    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL){
            nodo->derecha = nuevoNodo(dato);
        } else {
            //Si la derecha ya esta ocupada, recursividad ;)
            insertar(nodo->derecha, dato);
        }
    } else {
        //Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            //Si la izquierda ya esta ocupada, recursividad ;)
            insertar(nodo->izquierda, dato);
        }
    }
}

struct Nodo *eliminar(struct Nodo *raiz, int dato){
    //el nodo raiz no existe
    if(raiz == NULL){
        return NULL;
    }

    //se busca por el subtree derecho
    if(dato > raiz->dato){
        //se hace recursion hasta llegar al dato
        raiz->derecha = eliminar(raiz->derecha, dato);
    }
    //se busca por el subtree izquierdo
    else if(dato < raiz->dato){
        //se hace recursion hasta llegar al dato
        raiz->izquierda = eliminar(raiz->izquierda, dato);
    }

    //el dato del nodo ya es igual al nodo actual osea se encontro el nodo
    else{
        //el nodo no tiene hijos
        if(raiz->izquierda == NULL && raiz->derecha == NULL){
            //si no tiene hijos simplemente se quita no hay que crear nuevas conexiones
            free(raiz);
            //there is no need to add raiz = NULL since its a recursive call with return null and its asigned null to the parent pointer
            return NULL;
        }
        //el nodo tiene un hijo derecho
        else if(raiz->izquierda == NULL){
            struct Nodo *temporal = raiz->derecha;
            free(raiz);
            //como tenia un hijo derecho este ahora pasa a ser el parent
            return temporal;
        }
        //el nodo tiene un hijo izquierdo
        else if(raiz->derecha == NULL){
            struct Nodo *temporal = raiz->izquierda;
            free(raiz);
            //como tenia un hijo derecho este ahora pasa a ser el parent
            return temporal;
        }
        //el nodo tiene ambos hijos
        else{
            //primero buscamos un sucesor en este caso es el de inorder osea el mayor el de la derecha
            struct Nodo *sucesor = raiz->derecha;

            //se busca el hijo izquierdo que este mas a la izquierda ya que si lo tiene este pasaria a ser el sucesor
            while(sucesor->izquierda != NULL){
                //si si tiene hijos izquierdos se mueve hasta encontrar el menor y este pasa a ser el sucesor
                sucesor = sucesor->izquierda;
            }

            //se cambia el dato de la raiz por el del sucesor el cual puede ser el hijo derecho o el hijo mas a la izquierda del hijo derecho
            raiz->dato = sucesor->dato;

            //como el sucesor esta duplicado en el subarbol derecho debemos eliminarlo
            raiz->derecha = eliminar(raiz->derecha, sucesor->dato);
        }
    }

    return raiz;
}

void preorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        printf("%d,", nodo->dato);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d,", nodo->dato);
        inorden(nodo->derecha);
    }
}

void postorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}

int main(void) {
    struct Nodo *raiz = nuevoNodo(28);
    insertar(raiz, 11);
    insertar(raiz, 96);
    insertar(raiz, 21);
    insertar(raiz, 6);
    insertar(raiz, 97);
    insertar(raiz, 1);
    insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);

    printf("\nImprimiendo preorden\n");
    preorden(raiz);
    printf("\nImprimiendo inorden\n");
    inorden(raiz);
    printf("\nImprimiendo postorden\n");
    postorden(raiz);
    
    int num;
    printf("\n\nEscribe el valor que quieres eliminar: ");
    scanf("%d", &num);
    raiz = eliminar(raiz, num);
    //se vuelve a imprimir el arbol
    postorden(raiz);

    return 0;
}
