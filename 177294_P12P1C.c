
#include <stdio.h>
#include <stdlib.h>

//prototipos
void llena(int[][5]);
void reemplaza(int[][5]);
int sumando(int[][5]);
void imprimir(int[][5]);
void encabezado();

int main(){
	int num[4][5];
	int sum_num=0;

	//invocacion de las funciones
	encabezado(); 
	llena(num); 
	imprimir(num);
	sum_num=sumando(num);
	printf("\n\nSUMA DE LOS ELEMENTOS DEL ARREGLO: %d\n\n",sum_num);
	reemplaza(num); 
	
}


//Funcion que llena un arreglo con numeros aleatorios entre 1 y 50
void llena(int num[][5]){
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			num[i][j]=1+rand()%(51-1);
		}
	}
}
//Funcion que verifica si un numero es multiplo de 5, entonces lo reemplaza por un -1
void reemplaza(int num[][5]){
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			if((num[i][j]%5)==0){
				num[i][j]=-1;
			}
		}
	}
	imprimir(num);
}

//Funcion que recorre el arreglo, suma todos sus elementos y regresa el resultado
int sumando(int num[][5]){
	int suma=0;
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			suma=suma+num[i][j];
		}
	}
	return suma;
}
//Funcion para recorrer el arreglo elemento por elemento y mostrarlo en pantalla en forma de matriz, si hay elementos menores a 10 agrega un cero
void imprimir(int num[4][5]){
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			if(num[i][j]<(10)){
				if(num[i][j]==-1){
					printf("%c%d%d\t", '-', 0, 1);
				}else{
					printf("%d%d\t", 0, num[i][j]);
				}
			}else{
				printf("%d\t",num[i][j]);
			}
		}
		printf("\n");
	}
}

//Funcion que imprime los datos del alumno en pantalla de ejecucion
void encabezado(){
	printf("------------------------------------\n");
	printf("Victor Alfonso Covarrubias Solis\n");
	printf("177294\n");
	printf("Laboratorio de Programacion 1\n");
	printf("Grupo C\n");
	printf("Semestre 2\n");
	printf("Martes 19 de abril del 2022\n");
	printf("------------------------------------\n");
}
