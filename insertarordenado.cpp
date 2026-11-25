#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct _agenda{
    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;
};

struct _agenda *primero=NULL, *ultimo=NULL, *nuevo;

void insertar();
void eliminarencualquierlugar();
void mostrar_lista();
void eliminaralfinal();

int main(){
	int opc;
	int seguir=0;
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	do{	
		printf("Elige la opcion que necesitas\n1.MOSTRAR\n2.INSERTAR\n3.ELIMINAR EN CUALQUIER LUGAR\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: mostrar_lista();
				break;
			case 2: insertar();
				break;
			case 3: eliminarencualquierlugar();
				break;
		}
		printf("Quieres seguir? 1=si, otro numero=no\n");
		fflush(stdin);
		scanf("%d", &seguir);
	}while(seguir==1);
	return(0);
}

void mostrar_lista(){
	struct _agenda *auxiliar;
    int i;
 
    i=0;
    auxiliar = primero;
    printf("\n\n\nMostrando la lista completa:\n");
    printf("--------------------------------\n");
    while (auxiliar!=NULL) {
		printf( "Nombre: %s, Telefono: %s\n",
		auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->siguiente;
		i++;
    }
    if (i==0) printf( "\nLa lista esta vacia!!\n" );
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
	    printf("Telefono: "); 
	    scanf("%s",&nuevo->telefono);
	    nuevo->siguiente = NULL; 
	    if (primero==NULL){
		    printf( "Primer elemento \n");
		    primero = nuevo;
		    ultimo = nuevo;
	    }else{
		    ultimo->siguiente=nuevo;
		    ultimo=nuevo;
	    } 
	    printf("\n\nDesea insertar otro elemento ? 1=si 2=no");
	    scanf("%d",&n);
    }while(n==1);    

    aux1=primero;
	char pal[20];
	char tel[12];

    while(aux1!=NULL){
	    aux2=aux1->siguiente;
	    while(aux2!=NULL){
		    if (strcmp(aux1->nombre,aux2->nombre)>0){		
				strcpy(pal,aux1->nombre);
				strcpy(aux1->nombre,aux2->nombre);
				strcpy(aux2->nombre,pal);

				strcpy(tel,aux1->telefono);
				strcpy(aux1->telefono,aux2->telefono);
				strcpy(aux2->telefono,tel);
			}
			aux2=aux2->siguiente;
		}
		aux1=aux1->siguiente;
	}
}

void eliminarencualquierlugar(){
	struct _agenda *aux, *aux2;
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
			free(eliminar);
		}else{
			aux=primero;
			aux2=aux->siguiente;
			printf("Despues de que elemento(nombre) desea usted hacer la eliminacion\n");
			scanf("%s", obj);
			if(aux2==ultimo){
				eliminaralfinal();
			}else{
				while(strcmp(obj, aux->nombre)==1){
					aux=aux->siguiente;
					aux2=aux2->siguiente;
					if(aux->siguiente==NULL){
						printf("No existe");
						bandera=false;
						break;
					}
				}
				if(bandera==true){
					aux->siguiente=aux2->siguiente;
					free(aux2);
				}
			}
		}
	}
}

void eliminaralfinal(){
	
	struct _agenda *eliminar2, *previo;
	eliminar2=primero;
	while(eliminar2!=ultimo){
		previo=eliminar2;
		eliminar2=eliminar2->siguiente;
	}
	previo->siguiente=NULL;
	ultimo = previo;
	free(eliminar2);
}
