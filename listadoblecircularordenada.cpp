#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _agenda{
    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;
    struct _agenda *anterior;
};

struct _agenda *primero=NULL, *ultimo=NULL, *nuevo;
void nuevo_elemento();
void insertar();
void mostrar_listainicio();
void mostrar_listafin();
void eliminarencualquierlugar();
void eliminaralfinal();
void buscar();
void salir();

int main(){
	
	int opc;
	int seguir=0;
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	do{	
		printf("Elige la opcion que necesitas\n1- Mostrar de inicio a fin\n2- Mostrar de fin a inicio\n3- Insertar\n4- Eliminar en cualquier Lugar\n5- Buscar un elemento en la lista y mostrarlo o mandar mensaje, segun sea el caso\n6- Salir\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: mostrar_listainicio();
				break;
			case 2: mostrar_listafin();
				break;
			case 3: insertar();
				break;
			case 4: eliminarencualquierlugar();
				break;
			case 5: buscar();
				break;
			case 6: salir();
				break;
		}
		printf("Quieres seguir? 1=si, otro numero=no\n");
		fflush(stdin);
		scanf("%d", &seguir);
	}while(seguir==1);
	return(0);
}


void insertar(){
	struct _agenda *nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
	struct _agenda *aux1,*aux2;
	int n=0;

	if (nuevo==NULL) printf( "No hay memoria disponible!\n");

	printf("\nNuevo elemento:\n\n");
	printf("Nombre: "); 
	scanf("%s",&nuevo->nombre);
	printf("Telefono: "); 
	scanf("%s",&nuevo->telefono);

	if (primero==NULL){
		primero = nuevo;
		ultimo = nuevo;

		nuevo->siguiente=nuevo;
		nuevo->anterior=nuevo;
	}else{
		//primero las conexiones al primero y al ultimo
		nuevo->siguiente = primero;
		nuevo->anterior=ultimo;
		//luego las conexiones de estos al nuevo
		ultimo->siguiente=nuevo;
		primero->anterior=nuevo;
		//por ultimo se le otorga el ser ultimo al nuevo
		ultimo = nuevo;
	}
	
	//ordenar la lista alfabeticamente
	char c[20];
	char tel[12];
	  
	//primero se checa si hay aunque sea un nodo y que este no sea el unico
	if(primero != NULL && primero->siguiente != primero){
		aux1=primero;
		while(aux1->siguiente!=primero){
			aux2=aux1->siguiente;
			while(aux2!=primero){
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
	}
	
	printf("!!Elemento agregado y ordenado!!\n\n");
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
    do{
    	printf( "Nombre: %s, Telefono: %s\n", auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->siguiente;
	}while (auxiliar!=primero);
    
}

void mostrar_listafin(){
	struct _agenda *auxiliar;

	if(primero == NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

    auxiliar = ultimo;
    printf("\n\n\nMostrando la lista completa:\n");
    printf("--------------------------------\n");
    do{
    	printf( "Nombre: %s, Telefono: %s\n", auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->anterior;
	}while(auxiliar!=ultimo);
}

void eliminarencualquierlugar(){
	struct _agenda *actual;
	char nombre[20];

	if(primero==NULL){
		printf("\nesta vacia\n");
		return;
	}

	printf("\nEscribe el nombre del contacto que quieres eliminar: ");
	scanf("%s", &nombre);

	actual = primero;

	do{
		//si encuentra el nodo
		if(strcmp(nombre, actual->nombre) == 0){
			//si solo hay un nodo en la lista
			if(primero == ultimo){
				primero = NULL;
				ultimo = NULL;
			}else{
				//si no es asi entonces el nodo anterior al que queremos eliminar lo conecto con el siguiente del que se elimina
				actual->anterior->siguiente = actual->siguiente;
				actual->siguiente->anterior  =actual->anterior;

				//si era el primer nodo
				if(actual == primero){
					primero = actual->siguiente;
				}

				//si era el primer nodo
				if(actual == ultimo){
					ultimo = actual->anterior;
				}
			}

			free(actual);
			printf("\nElemento eliminado correctamente!\n");
			return;
		}

		actual = actual->siguiente;
	}while(actual != primero);
	
	printf("\nEl elemento no existe por lo que no se pudo borrar\n");
}

void buscar(){
	struct _agenda *nav;
	char nombre[20];

	if(primero == NULL){
		printf("\nLa lista esta vacia.\n");
		return;
	}

	//int cont=0;
	//bool bandera=true;
	printf("Escribe el nombre de la persona de la cual quieres saber los datos: ");
	scanf("%s", nombre);

	//apuntar nav al primer nodo
	nav=primero;

	do{
		if((strcmp(nombre, nav->nombre))==0){
			printf("Los datos de esta persona son:\n");
			printf("Nombre: %s, Telefono: %s\n", nav->nombre,nav->telefono);
			return;
		}
		nav=nav->siguiente;

	}while(nav != primero);//se checa si volvio al primero
	printf("No se encontro la informacion buscada\n");
}

void eliminaralfinal(){
	if(primero==NULL){
		printf("\nLa lista esta vacia\n");
		return;
	}

	//si solo hay un nodo
	if(primero == ultimo){
		free(primero);
		primero = NULL;
		ultimo = NULL;
	}else{
		struct _agenda *eliminar = ultimo;

		//el ultimo se le otorga el anterior al ultimo
		ultimo = ultimo->anterior;

		ultimo->siguiente = primero;
		primero->anterior = ultimo;

		free(eliminar);
	}
	printf("\nUltimo elemento eliminado correctamente\n");
}

void salir(){
	exit(0);
}
