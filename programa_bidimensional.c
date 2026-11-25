#include <stdio.h>


int main(){
	char nom[3][6];

	printf("Capturar palabras\n\n");
	for(int i=0;i<3;i++){
		printf("Escribe la palabra numero %d: ", i+1);
		scanf("%s", nom[i]);
	}
	printf("\n---------\n");
	printf("Palabras guardadas:\n");
	for(int i=0;i<3;i++){
		printf("%s\n", nom[i]);
	}
}
