//librerias
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

//prototipos
void encabezado();//funcion para imprimir encabezado
void funcion1(int arreglo[][4]);//inicializa el arreglo con ceros
void funcion2(int arreglo[][4]);//llena el arreglo con numeros aleatorios del 1 al 45, sin qu se repitan
void funcion3(int arreglo[][4]);//ordena el arreglo en zigzag

main(){//funcion principal

	//variables
	int arreglo[5][4];//arreglo paraguardar varios datos enteros
	//llamadas de funciones
	encabezado();//llamada ala funcion encabezado
	funcion1(arreglo);
	funcion2(arreglo);
	
	//impresion delm arreglo ya con numeros random
	for(int i=0;i<5;i++){//ciclo for para las filas
		for(int j=0;j<4;j++){//ciclo for para las columnas
			printf("%d\t", arreglo[5][4]);
		}
		printf("\n");//salto de linea
	}
	
	funcion3(arreglo);

	return 0;//finalizacio0n de la funcion main, se usa return porque main es int
}

void encabezado(){//cuerpo de la funcion encabezado
	printf("Covarrubias Solis Victor Alfonso\n177294\nlaboratorio de Programacion 2\nGrupo A\n16/8/22\n----------------------------------\n\n");//impresion de datos
}

void funcion1(int arreglo[][4]){
	for(int i=0;i<5;i++){//ciclo for para las filas
		for(int j=0;j<4;j++){//ciclo for para las columnas
			arreglo[5][4]=0;
		}
	}
}

void funcion2(int arreglo[][4]){
	int aux[45]={0};//variable para vr si hay un numero repetido
	int num;
	bool bandera=true;
	for(int i=0;i<5;i++){//ciclo for para las filas
		for(int j=0;j<4;j++){//ciclo for para las columnas
			do{
				srand(time(NULL));//inicializar la semilla
				num=rand()%45+1;//genrar numeros aleatorios entre 1 y 45
				if(aux[num]==0){
					aux[num]=1;
					arreglo[i][j]=num;
					bandera=true;
				}else{
					bandera=false;
				}
			}while(bandera==false);
		}
	}
}

void funcion3(int arreglo[][4]){
	for(int i=0;i<5;i++){//ciclo for para las filas
		for(int j=0;j<4;j++){//ciclo for para las columnas
			
		}
	}
}
