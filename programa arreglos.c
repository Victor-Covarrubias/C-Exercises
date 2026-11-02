/*
3 arreglos enteros de 10 elementos cada uno
arreglo 1: llenar con numero aleatorios de entre 19 a 45
arreglo 2: llenar con datos capturados por el usuario, verificar que solo meta numeros pares
arreglo 3: llenar con numeros impares aleatorios en un rango de 5 a 30
imprimir los 3 arreglos por separado, indique cual se esta imprimiendo.
el programa debera estar completamente documentado
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

int main(){
	int arreglo1[10]={0};// inicializo el arreglo 1
	int arreglo2[10]={0};// inicializo el arreglo 2
	int arreglo3[10]={0};// inicializo el arreglo 3
	int valor=0;
	int num=0;
	bool control=true;
	
	srand(time(NULL));// inicializo la semilla ya que si la dejo como esta me sacara los mismos numeros aleatorios
	printf("Victor Alfonso Covarrubias Solis\n177294\n----------------------------------\n\n");
	for(int i=0; i<10; i++){//ciclo for para asignarle un numero aleatorio a cada elemento del arreglo1
		arreglo1[i]=19+rand()%(46-10);//asignacion de numero aleatorio
	}
	
	do{
		for(int i=0; i<10; i++){//ciclo for para asignarle un valor escrito por el usuario a cada elemento del arreglo2
			printf("Valor Par %d:\n", i);//impresion para pedir el valor que se le asignara a ese elemento del arreglo 2
			scanf("%d", &valor);//lectura del valor
			if(valor%2==0){
				arreglo2[i]=valor;//asignacion de valor
			}else{//si no pasa eso entonces pasa lo siguiente
				if(i>=0){//si el ciclo ya se repitio entonces i sera mayor de 0
					i--;//ala i se le resta 1 para que se pida ese valor de nuevo
				}
			}
		}
		control=false;//el boleano se cambia a falso para salir del ciclo
	}while(control);//condicion para que se repita el do
	
	for(int i=0; i<10; i++){//ciclo for para asignarle un valor impar aleatorio del 5 al 30 a cada elemento del arreglo3
		num=5+rand()%(31-5);//asignacion del numero aleatorio
		if(num%2!=0){//checa si el numero aleatorio es impar
			arreglo3[i]=num;//si es impar el numero sera asignado al elemento i del arreglo3
		}else{//si no pasa eso entonces pasa lo siguiente
			if(num%2==0){//si el numero aleatorio es par
				arreglo3[i]=num+1;//se le suma 1 al numero par por lo cual se convierte en impar
			}
		}
	}
	
	
	
	printf("Arreglo 1:\n");//impresion de arreglo 1
	for(int i=0; i<10; i++){//ciclo for para la impresion de cada elemento del arreglo1
		printf("%d\n", arreglo1[i]);//impresion de cada elemento
	}
	
	printf("Arreglo 2:\n");//impresion de arreglo 2
	for(int i=0; i<10; i++){//ciclo for para la impresion de cada elemento del arreglo2
		printf("%d\n", arreglo2[i]);//impresion de cada elemento
	}
	
	printf("Arreglo 3:\n");//impresion de arreglo 2
	for(int i=0; i<10; i++){//ciclo for para la impresion de cada elemento del arreglo2
		printf("%d\n", arreglo3[i]);//impresion de cada elemento
	}
	return 0;
}
