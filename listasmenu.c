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
	printf("Victor Alfonso Covarrubias Solis, 177294");
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

   int n=0;
      do
      {
      /* reservamos memoria para el nuevo elemento */
      nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
      if (nuevo==NULL) printf( "No hay memoria disponible!\n");
       
      printf("\nNuevo elemento:\n\n");
      printf("Nombre: "); 
                scanf("%s",&nuevo->nombre);
      printf("Teléfono: "); 
              scanf("%s",&nuevo->telefono);

  /* el campo siguiente va a ser NULL por ser el último elemento
         de la lista */
      nuevo->siguiente = NULL; 

/* ahora metemos el nuevo elemento en la lista. lo situamos
         al final de la lista */
/* comprobamos si la lista está vacía. si primero==NULL es que no
         hay ningún elemento en la lista. también vale ultimo==NULL */
      if (primero==NULL) 
      {
         printf( "Primer elemento \n");
         primero = nuevo;
         ultimo = nuevo;
         } 

      else 
      {
           /* el que hasta ahora era el último tiene que apuntar al nuevo */
           ultimo->siguiente = nuevo;
           /* hacemos que el nuevo sea ahora el último */
           ultimo = nuevo;
      }
      
      printf("\n\nDesea insertar otro elemento ? 1=si ");
      scanf("%d",&n);
      }while(n==1);
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
    if (i==0) printf( "\nLa lista está vacía!!\n" );
}
void insertaralfinal(){

	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
      if (nuevo==NULL) printf( "No hay memoria disponible!\n");
       
      printf("\nNuevo elemento:\n\n");
      printf("Nombre: "); 
                scanf("%s",&nuevo->nombre);
      printf("Teléfono: "); 
              scanf("%s",&nuevo->telefono);

      nuevo->siguiente = NULL; 
	ultimo->siguiente = nuevo;
    ultimo = nuevo;
}
void insertaralinicio(){
	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
    if (nuevo==NULL) printf( "No hay memoria disponible!\n");
       fflush(stdin);
      printf("\nNuevo elemento:\n\n");
      printf("Nombre: "); 
                scanf("%s",&nuevo->nombre);
      printf("Teléfono: "); 
              scanf("%s",&nuevo->telefono);

      nuevo->siguiente = primero;
      ultimo->siguiente = NULL;
    primero = nuevo;
}
void eliminaralinicio(){
	struct _agenda *eliminar;
	eliminar=primero;
	primero=primero->siguiente;
	free(eliminar);
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
void insertarencualquierlugar(){
	struct _agenda *i;
	char obj[20];
	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
    if (nuevo==NULL) printf( "No hay memoria disponible!\n");
    
    printf("Despues de que elemento desea usted hacer la instalacion\n");
    scanf("%s", obj);
    for(i=primero;i!=NULL;i=i->siguiente){
    	if(strcmp(obj, i->nombre)==0){
    		printf("\nNuevo elemento:\n\n");
		    printf("Nombre: "); 
		    scanf("%s",&nuevo->nombre);
		    printf("Teléfono: "); 
		    scanf("%s",&nuevo->telefono);
		    nuevo->siguiente=i->siguiente;
		    i->siguiente=nuevo;
		}
	}
}
void eliminarencualquierlugar(){
	struct _agenda *aux, *aux2;
	char obj[20];
	if(primero==NULL){
	printf("esta vacia");
	}else{
		aux=primero;
		aux2=aux->siguiente;
		printf("Despues de que elemento desea usted hacer la desinstalacion\n");
		scanf("%s", obj);
		if(aux2==ultimo){
			eliminaralfinal();
		}else{
			while(strcmp(obj, aux->nombre)==1){
				aux=aux->siguiente;
				aux2=aux2->siguiente;
			}
			aux->siguiente=aux2->siguiente;
			free(aux2);
		}
	}
}
