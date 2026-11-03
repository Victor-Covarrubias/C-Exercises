#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct _agenda{
    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;
    struct _agenda *anterior;
};

struct _agenda *primero=NULL, *ultimo=NULL, *nuevo;
bool point=true;
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
	printf("Victor Alfonso Covarrubias Solis, 177294");
	do{	
		printf("Elige la opcion que necesitas\n1- Mostrar de inicio a fin\n2- Mostrar de fin a inicio\n3- Insertar\n4- Eliminar en cualquier Lugar\n5- Buscar un elemento en la lista y mostrarlo o mandar mensaje, según sea el caso\n6- Salir\n");
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
	struct _agenda *nuevo,*aux1,*aux2;
	int n=0;
	do{
		nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
		if (nuevo==NULL) printf( "No hay memoria disponible!\n");
		printf("\nNuevo elemento:\n\n");
		printf("Nombre: "); 
		scanf("%s",&nuevo->nombre);
		printf("Teléfono: "); 
		scanf("%s",&nuevo->telefono);
		nuevo->siguiente = primero;
		if (primero==NULL){
			printf( "Primer elemento \n");
			primero = nuevo;
			ultimo = nuevo;
			primero->anterior=ultimo;
		}
		else{
			ultimo->siguiente = nuevo;
			nuevo->anterior=ultimo;
			ultimo = nuevo;
			ultimo->siguiente=primero;
			primero->anterior=ultimo;
		}
		point=false;
		printf("\n\nDesea insertar otro elemento ? 1=si ");
		scanf("%d",&n);
	}while(n==1);
	
	aux1=primero;
	char c[20];
	while(aux1->siguiente!=primero){
	    aux2=aux1->siguiente;
	    while(aux2->siguiente!=primero){
		    if (strcmp(aux1->nombre,aux2->nombre)>0){		
				strcpy(c,aux1->nombre);
				strcpy(aux1->nombre,aux2->nombre);
				strcpy(aux2->nombre,c);
			}
			aux2=aux2->siguiente;
		}
		aux1=aux1->siguiente;
	}
	printf("!!Elemento ordenado!!\n\n");
}
void mostrar_listainicio(){
	struct _agenda *auxiliar;

    auxiliar = primero;
    printf("\n\n\nMostrando la lista completa:\n");
    printf("--------------------------------\n");
    do{
    	if (point==true){
	    	printf( "\nLa lista está vacía!!\n" );
	    	break;
		}
    	printf( "Nombre: %s, Telefono: %s\n", auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->siguiente;
	}while (auxiliar!=primero);
    
}
void mostrar_listafin(){
	struct _agenda *auxiliar;
    auxiliar = ultimo;
    printf("\n\n\nMostrando la lista completa:\n");
    printf("--------------------------------\n");
    do{
    	if (point==true){
	    	printf( "\nLa lista está vacía!!\n" );
	    	break;
		}
    	printf( "Nombre: %s, Telefono: %s\n", auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->anterior;
	}while(auxiliar!=ultimo);
}

void eliminarencualquierlugar(){
	struct _agenda *aux, *aux2, *aux3;
	char obj[20];
	int opc;
	bool bandera=true;
	if(primero==NULL){
	printf("esta vacia");
	}else{
		printf("Quieres eliminar el primer elemento? 1-si, otro numero no");
		scanf("%d", &opc);
		if(opc==1){
			struct _agenda *eliminar;
			eliminar=primero;
			primero=primero->siguiente;
			primero->anterior=ultimo;
			free(eliminar);
		}else{
			aux=primero;
			aux2=aux->siguiente;
			aux3=aux2->siguiente;
			printf("Despues de que elemento desea usted hacer la desinstalacion\n");
			scanf("%s", obj);
			if(aux2->siguiente==primero){
				eliminaralfinal();
			}else{
				while(strcmp(obj, aux->nombre)==1){
					aux=aux->siguiente;
					aux2=aux2->siguiente;
					aux3=aux3->siguiente;
					if(aux->siguiente==primero){
						printf("\nNo existe\n");
						bandera=false;
						break;
					}
				}
				if(bandera==true){
					if(aux2==ultimo){
						eliminaralfinal();
					}else{
						aux->siguiente=aux2->siguiente;
						aux3->anterior=aux2->anterior;
						free(aux2);
					}
				}
			}
		}
	}
}

void buscar(){
	struct _agenda *nav;
	char nombre[20];
	int cont=0;
	bool bandera=true;
	printf("Escribe el nombre de la persona de la cual quieres saber los datos: ");
	scanf("%s", nombre);
	nav=primero;
	while(cont==0){
		if((strcmp(nombre, nav->nombre))==0){
			printf("Nombre: %s, Telefono: %s\n", nav->nombre,nav->telefono);
			nav=NULL;
			cont++;
			bandera=false;
		}else{
			nav=nav->siguiente;
			if(nav->siguiente!=primero){
				break;
			}
		}
	}
	if(bandera==true){
		printf("No se encontro la informacion buscada\n");
	}
}
void eliminaralfinal(){
	struct _agenda *eliminar2, *previo;
	eliminar2=primero;
	do{
		previo=eliminar2;
		eliminar2=eliminar2->siguiente;
	}while(eliminar2->siguiente!=primero);
	previo->siguiente=primero;
	previo->anterior=ultimo;
	ultimo = previo;
	free(eliminar2);
}
void salir(){
	exit(0);
}
