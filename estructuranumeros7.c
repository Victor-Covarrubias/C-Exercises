#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct n{
	int num;
}numeros[7];

int main(){
	
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	
	for(int i=0; i<7; i++){
		printf("Escribe un dato:\n");
		scanf("%d", &numeros[i].num);
	}
	for(int i=0; i<7; i++){
		printf("numero %d: %d\n", i+1, numeros[i].num);
	}
	
	
	return 0;
}
