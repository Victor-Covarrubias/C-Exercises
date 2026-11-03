#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float factorial(float n){
	float fact=1;
	for(int i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}

float combinaciones(float n, float r){
	return factorial(n)/(factorial(n-r)*factorial(r));
}

int main(void){
	float n=0, r=0;
	char pal[30];
	int cont[26]={0};
	float den=0;
	printf("\nIntroduce n para sacar el factorial: ");
	scanf("%f", &n);
	printf("\n\nEl factorial del numero es: %.f", factorial(n));
	
	printf("\nIntroduce n para el numero de objetos de la permutacion lineal: ");
	scanf("%f", &n);
	printf("\nIntroduce r para los lugares: ");
	scanf("%f", &r);
	printf("\n\nLas permutaciones lineales son nPr : %.f", factorial(n)/factorial(n-r));
	
	printf("\nIntroduce n para sacar permutaciones circulares: ");
	scanf("%f", &n);
	printf("\n\nLas peermutaciones circulares son: %.f", factorial(n-1));
	den=1;
	
	fflush(stdin);
	printf("\nIntroduce la palabra para la permutacion con repeticion: ");
	scanf("%s", pal);
	for(int i=0;i<=strlen(pal)-1;i++){
		pal[i]=toupper(pal[i]);
		cont[pal[i]-65]++;
	}
	for(int j=0;j<25;j++){
		den*=factorial(cont[j]);
	}
	printf("\n\nEl total de permutaciones con repeticion son: %.f", factorial(strlen(pal))/den);
	
	printf("\nIntroduce n para el numero total para la combinacion: ");
	scanf("%f", &n);
	printf("\nIntroduce r para la cantidad del grupo: ");
	scanf("%f", &r);
	printf("\n\nEl total de combinaciones es: %.f", combinaciones(n,r));
	
	printf("\nIntroduce n para sacar el polinomio: ");
	scanf("%f", &n);
	printf("\n\nEl polinomio es: ");
	for(int k=0;k<=n;k++){
		if(k==n){
			printf("%.f x^%.f y^%d",combinaciones(n, k),(n-k),k);
		}else{
			printf("%.f x^%.f y^%d + ",combinaciones(n, k),(n-k),k);
		}
	}
	
	printf("\nIntroduce n para el numero de recipientes para la distribucion: ");
	scanf("%f", &n);
	printf("\nIntroduce r para el numero de objetos: ");
	scanf("%f", &r);
	printf("\n\nLa distribucion es: %.f", combinaciones(n+r-1, r));
	return 0;
}

