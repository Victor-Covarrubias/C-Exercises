#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _agenda{
    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;
    struct _agenda *anterior;
};

struct _agenda *primero=NULL, *ultimo=NULL;

//void nuevo_elemento();
void insertar();
void eliminarencualquierlugar();
void mostrar_listainicio();
void mostrar_listafin();
void eliminaralfinal();
void buscar();
void salir();

int main(){
	
	int opc;
	int seguir=0;
	printf("Victor Alfonso Covarrubias Solis, 177294\n");
	do{	
		printf("Elige la opcion que necesitas\n1- Mostrar de inicio a fin\n2- Mostrar de fin a inicio\n3- Insertar\n4- Eliminar en cualquier Lugar\n5- Buscar un elemento en la lista y mostrarlo o mandar mensaje, segun sea el caso\n6- Salir\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: mostrar_listainicio();//ya esta
				break;
			case 2: mostrar_listafin();//ya esta
				break;
			case 3: insertar();
				break;
			case 4: eliminarencualquierlugar();
				break;
			case 5: buscar();//ya esta
				break;
			case 6: salir();//ya esta
				break;
		}
		printf("Quieres seguir? 1=si, otro numero=no\n");
		fflush(stdin);
		scanf("%d", &seguir);
	}while(seguir==1);
	return(0);
}


void insertar(){
	struct _agenda *nuevo,*aux1,*aux2;
	int n=0;

	do{
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
		nuevo->anterior = ultimo;

		if (primero == NULL){
			primero = nuevo;
			ultimo = nuevo;
		}else{
			ultimo->siguiente = nuevo;
			ultimo = nuevo;
		}
		printf("\n\nDesea insertar otro elemento ? 1=si ");
		scanf("%d",&n);
	}while(n==1);

	//ordenar la lista alfabeticamente
	aux1=primero;
	char c[20];
	char tel[20];

    while(aux1!=NULL){
	    aux2=aux1->siguiente;
	    while(aux2!=NULL){
		    if (strcmp(aux1->nombre,aux2->nombre)>0){		
				strcpy(c,aux1->nombre);
				strcpy(aux1->nombre,aux2->nombre);
				strcpy(aux2->nombre,c);

				strcpy(tel,aux1->telefono);
				strcpy(aux1->telefono,aux2->telefono);
				strcpy(aux2->telefono,tel);
			}
			aux2=aux2->siguiente;
		}
		aux1=aux1->siguiente;
	}
	printf("!!Elemento ordenado!!\n\n");
}

void mostrar_listainicio(){
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

	while(aux != NULL && strcmp(obj, aux->nombre) != 0){
		aux = aux->siguiente;
	}

	if(aux == NULL){
		printf("\nNo se encontro\n");
		return;
	}

	if(aux->siguiente == NULL){
		printf("\nNo existe un elemento despues de este contacto.\n");
		return;
	}

	//para conseguir el nodo a eliminar
	aux2 = aux->siguiente;
	//se cambia el siguiente del anterior a eliminar
	aux->siguiente = aux2->siguiente;

	if(aux2->siguiente != NULL){
		aux2->siguiente->anterior = aux;
	}else{
		ultimo = aux;
	}

	free(aux2);
	printf("\nElemento eliminado correctamente\n");
}

void mostrar_listafin(){
	struct _agenda *auxiliar;

	if(ultimo == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

    auxiliar = ultimo;

    printf("\n\n\nMostrando la lista completa invertida:\n");
    printf("--------------------------------\n");
    while (auxiliar!=NULL) {
		printf( "Nombre: %s, Telefono: %s\n",
		auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->anterior;
    }
}

void buscar(){
	struct _agenda *nav;
	char nombre[20];

	if(primero == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

	printf("Escribe el nombre de la persona de la cual quieres saber los datos: ");
	scanf("%s", nombre);

	nav=primero;
	while(nav != NULL){
		if((strcmp(nombre, nav->nombre))==0){
			printf("Nombre: %s, Telefono: %s\n", nav->nombre,nav->telefono);
			return;
		}

		nav=nav->siguiente;
	}
	printf("No se encontro la informacion buscada\n");
}

void eliminaralfinal(){
	struct _agenda *eliminar2;

	if(ultimo == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

	eliminar2=ultimo;

	if(primero == ultimo){
		primero = NULL;
		ultimo = NULL;
	}else{
		ultimo = ultimo->anterior;
		ultimo->siguiente = NULL;
	}

	free(eliminar2);
	printf("\nUltimo nodo eliminado\n");
}

void salir(){
	struct _agenda *auxiliar;

	while(primero != NULL){
		auxiliar = primero;
		primero = primero->siguiente;

		free(auxiliar);
	}

	ultimo = NULL;
	exit(0);
}
