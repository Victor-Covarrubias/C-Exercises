#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _agenda{
    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;
};

struct _agenda *primero=NULL, *ultimo=NULL;

void nuevo_elemento();
void insertaralfinal();
void insertaralinicio();
void eliminaralinicio();
void eliminaralfinal();
void insertarencualquierlugar();
void eliminarencualquierlugar();
void mostrar_lista();

int main(){
	
	int opc;
	int seguir=0;
	printf("Victor Alfonso Covarrubias Solis, 177294\n");
	nuevo_elemento();
	do{	
		printf("Elige la opcion que necesitas\n1.MOSTRAR\n2.INSERTAR AL FINAL\n3.ELIMINAR AL INICIO\n4.ELIMINAR AL FINAL\n5.INSERTAR AL INICIO\n6.INSERTAR EN CUALQUIER LUGAR\n7.ELIMINAR EN CUALQUIER LUGAR\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: mostrar_lista();
				break;
			case 2: insertaralfinal();
				break;
			case 3: eliminaralinicio();
				break;
			case 4: eliminaralfinal();
				break;
			case 5: insertaralinicio();
				break;
			case 6: insertarencualquierlugar();
				break;
			case 7: eliminarencualquierlugar();
				break;
		}
		printf("Quieres seguir? 1=si, otro numero=no\n");
		fflush(stdin);
		scanf("%d", &seguir);
	}while(seguir==1);
	return(0);
}

void nuevo_elemento(){
	struct _agenda *nuevo;
    int n=0;
	do{
		/* reservamos memoria para el nuevo elemento */
		nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
		if (nuevo==NULL){
			printf("No hay memoria disponible!\n");
			return;
		}
		
		printf("\nNuevo elemento:\n\n");
		printf("Nombre: "); 
		scanf("%s",&nuevo->nombre);
		printf("Telefono: "); 
		scanf("%s",&nuevo->telefono);

	    /* el campo siguiente va a ser NULL por ser el ultimo elemento
		de la lista */
		nuevo->siguiente = NULL; 

		/* ahora metemos el nuevo elemento en la lista. lo situamos
		al final de la lista */
		/* comprobamos si la lista esta vacia. si primero==NULL es que no
		hay ningun elemento en la lista. tambien vale ultimo==NULL */
		if (primero==NULL){
			primero = nuevo;
			ultimo = nuevo;
		}else{
			/* el que hasta ahora era el ultimo tiene que apuntar al nuevo */
			ultimo->siguiente = nuevo;
			/* hacemos que el nuevo sea ahora el ultimo */
			ultimo = nuevo;
		}
		
		printf("\n\nDesea insertar otro elemento ? 1=si ");
		scanf("%d",&n);
	}while(n==1);
}

void mostrar_lista(){
	struct _agenda *auxiliar;

	if(primero == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

	auxiliar = primero;

    printf("\n\n\nMostrando la lista completa:\n");
    printf("--------------------------------\n");
    while (auxiliar!=NULL) {
		printf( "Nombre: %s, Telefono: %s\n",
		auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->siguiente;
    }
}

void insertaralfinal(){
	struct _agenda *nuevo;
	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
    if (nuevo==NULL){
		printf( "No hay memoria disponible!\n");
		return;
	}
       
    printf("\nNuevo elemento:\n\n");
    printf("Nombre: "); 
    scanf("%s",&nuevo->nombre);
    printf("Telefono: "); 
    scanf("%s",&nuevo->telefono);

    nuevo->siguiente = NULL; 

	if(primero == NULL){
		primero = nuevo;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		ultimo = nuevo;
	}

	printf("\nElemento agregado al final\n");
}

void insertaralinicio(){
	struct _agenda *nuevo;
	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
    if (nuevo==NULL){
		printf( "No hay memoria disponible!\n");
		return;
	}
    fflush(stdin);
    printf("\nNuevo elemento:\n\n");
    printf("Nombre: "); 
    scanf("%s",&nuevo->nombre);
    printf("Telefono: "); 
    scanf("%s",&nuevo->telefono);

    nuevo->siguiente = primero;
    primero = nuevo;

	if(ultimo == NULL){
		ultimo = nuevo;
	}

	printf("\nElemento agregado al inicio");
}

void eliminaralinicio(){
	struct _agenda *eliminar;

	if(primero == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

	eliminar=primero;
	primero=primero->siguiente;

	if(primero == NULL){
		ultimo = NULL;
	}
	free(eliminar);

	printf("\nPrimero elemento eliminado\n");
}

void eliminaralfinal(){
	
	struct _agenda *eliminar2, *previo;

	if(primero == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

	if(primero == ultimo){
		eliminar2=primero;
		primero = NULL;
		ultimo = NULL;
		free(eliminar2);
	}else{
		previo = primero;

		while(previo->siguiente != ultimo){
			previo=previo->siguiente;
		}

		eliminar2 = ultimo;
		previo->siguiente=NULL;
		ultimo = previo;
		free(eliminar2);
	}

	printf("\nUltimo elemento eliminado\n");
}

void insertarencualquierlugar(){
	struct _agenda *i, *nuevo;
	char obj[20];

	if(primero == NULL){
		printf("\nLa lista esta vacia por lo que no hay contacto despues del cual insertar\n");
		return;
	}

	printf("Despues de que elemento desea usted hacer la instalacion\n");
    scanf("%s", obj);
    
    i=primero;
	while(i != NULL && strcmp(obj, i->nombre) != 0){
		i = i->siguiente;
	}

	if (i==NULL){
		printf( "No se encontro\n");
		return;
	}

	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
    if (nuevo==NULL){
		printf( "No hay memoria disponible!\n");
		return;
	}

	printf("\nNuevo elemento:\n\n");
	printf("Nombre: "); 
	scanf("%s",&nuevo->nombre);
	printf("Telefono: "); 
	scanf("%s",&nuevo->telefono);

	nuevo->siguiente=i->siguiente;
	i->siguiente=nuevo;

	//si i era el ultimo entonces ahora el nuevo es el ultimo
	if(i == ultimo){
		ultimo = nuevo;
	}

	printf("\nElemento agregado correctamente");
}

void eliminarencualquierlugar(){
	struct _agenda *aux, *aux2;
	char obj[20];
	if(primero==NULL){
		printf("esta vacia");
		return;
	}

	printf("Despues de que elemento desea usted hacer la desinstalacion\n");
	scanf("%s", obj);

	aux=primero;

	while(aux != NULL && strcmp(obj, aux->nombre)!=0){
		aux=aux->siguiente;
	}

	if(aux==NULL){
		printf("\nNo se encontro el elemento\n");
		return;
	}
	
	if(aux->siguiente == NULL){
		printf("\nNo existe un elemento despues de este elemento\n");
		return;
	}
	
	aux2 = aux->siguiente;
	aux->siguiente = aux2->siguiente;

	if(aux2==ultimo){
		ultimo = aux;
	}
	free(aux2);

	printf("\nElemento eliminado\n");
}
