#include<stdio.h>


// Victor Alfonso Covarrubias Solis, 177294, 0
int main(){
	FILE *lector;
	char caracter;
	
	//lo habro para leer el archivo (r)
	lector = fopen("datos.txt", "r");

	if(lector == NULL){
		printf("No se pudo abrir el archivo.\n");
		//termina el porgrama indicando fracaso
		return 1;
	}
	
	//lee caracter por caracter si quisieramos ir en linea por linea usariamos fgets
	while((caracter = fgetc(lector)) != EOF){
		//imprime el caracter obtenido
		putchar(caracter);
	}
	
	fclose(lector);

	return 0;
}
