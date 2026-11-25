#include <stdio.h>

struct n{
	int num;
}numeros[7];

int main(){
	
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	
	for(int i=0; i<7; i++){
		printf("Escribe un numero:\n");
		scanf("%d", &numeros[i].num);
	}
	for(int i=0; i<7; i++){
		printf("numero %d: %d\n", i+1, numeros[i].num);
	}

	return 0;
}