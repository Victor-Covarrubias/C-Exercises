#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

int main(){
	int ar[12]={0};
	int ar1[3][4]={1,2,3,4,5,6,7,8,9,10,11};
	ar1[2][3]=98;
	char nom[3][6];
	/*
	for(int j=0;j<12;j++){
		printf("[%d]", ar1[i][j]);
		if(j==3 or j==7){
			printf("\n");
		}
	}
	*/
	/*
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			printf("[%d]", ar1[i][j]);
		}
		printf("\n");
	}
	*/
	printf("Capturar palabras\n\n");
	for(int i=0;i<3;i++){
		scanf("%s", nom[i]);
	}
	printf("\n---------\n");
	
	for(int i=0;i<3;i++){
		printf("%s\n", nom[i]);
	}
}
