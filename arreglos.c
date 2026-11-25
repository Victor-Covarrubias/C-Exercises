#include<stdio.h>

int main(){
	
	int arreglo[6]={1,2,3,4,5,6};
	int suma=0;
	printf("Victor Alfonso Covarrubias Solis, 177294\n");
	for(int i=0;i<6;i++){
		printf("numero %d: %d\n", i, arreglo[i]);
		if(i%2==0){
			suma+=arreglo[i];
		}
	}
	printf("\n sumatoria de los numeros pares es= %d", suma);
	return 0;
}
