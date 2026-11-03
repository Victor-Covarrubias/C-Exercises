#include <stdio.h>
//simple enlazada

int main(){
	
	//eliminar al final
	if(primero==NULL){
	//mensaje lista vacia return
	}else{
		if(primero==ultimo){
			free(ultimo);
		}else{
			aux=primero;
			while(aux->sig!=ultimo){
				aux=aux->sig;
			}
			aux->sig=NULL;
			free(ultimo);
			ultimo=aux;
		}
	}
	
	//eliminar en cualquier lugar
	if(primero==NULL){
	//mensaje lista vacia return
	}else{
		aux=primero;
		aux2=aux->sig;
		//pon el elemento anterior al que quieres eliminar
		//se escanea
		if(aux2==ultimo){
			eliminaralfinal();
		}else{
			while(aux!=/*elemento que fue seleccionado*/){
				aux=aux->sig;
				aux2=aux2->sig;
			}
			aux->sig=aux2->sig;
			free(aux2);
		}
	}
}
