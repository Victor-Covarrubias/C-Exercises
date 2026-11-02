#include <stdio.h>//librerias
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
 void gotoxy(int x,int y){//funcion gotoxy para imprimir cosas en coordenadas especificas
 HANDLE hcon;
 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y= y;
 SetConsoleCursorPosition(hcon,dwPos);
 } 
 
void llenararreglo(float arreglo[][5]); //prototipo de la funcion que sirve para ser llamada
void imprimirarreglo(float arreglo[][5], char marcas[][10]);//prototipo de la funcion que sirve para ser llamada
void encabezado();//funcion con datos
void porPresentacion(float arreglo[][5], char presentacion[], char marcas[][10]);
void unLitro(float arreglo[][5], char marcas[][10]);
void porProducto(float arreglo[][5], char marcas[][10]);

int main(){//inicio de la funcion normal
	float arreglo[6][5];
	char presentacion[10];//arreglo para guardar la presentacion que escribe el usuario
	char marcas[6][10]={"COCA\t","PEPSI\t","FANTA\t","SANGRIA\t","SPRITE\t","MIRINDA\t"};//areglo para imprimir las marcas
	srand(time(NULL));
	
	encabezado();//impresion de mis datos
	llenararreglo(arreglo);//se envia el arreglo ala funcion llenar arreglo
	imprimirarreglo(arreglo, marcas);//se envia el arreglo ala funcion imprimir arreglo
	printf("\nINSERTE CUAL PRESENTACION DESEA CONSULTAR: ");
	scanf("%s", presentacion);
	porPresentacion(arreglo, presentacion, marcas);
	unLitro(arreglo, marcas);
	porProducto(arreglo, marcas);
	return 0;
}
 
void llenararreglo(float arreglo[][5]){//funcion para llenar el arreglo
	for(int i=0; i<5; i++){//ciclo para llenar el arreglo en orden
		for(int j=0; j<6; j++){
			
			if(i==0){ //la condicion es para ver en que columna se encuentra y dependiendo de ella es el rango del rand
				arreglo[j][i]=((float)(6+rand()%(11-6+1)))/1.1;//rango del rand de 5 a 10
			}
			if(i==1){
				arreglo[j][i]=((float)(9+rand()%(16-9+1)))/1.1;//rango del rand de 8 a 15
			}
			if(i==2){
				arreglo[j][i]=((float)(10+rand()%(17-10+1)))/1.1;//rango del rand de 9 a 16
			}
			if(i==3){
				arreglo[j][i]=((float)(15+rand()%(22-15+1)))/1.1;//rango del rand de 14 a 21
			}
			if(i==4){
				arreglo[j][i]=((float)(20+rand()%(28-20+1)))/1.1;//rango del rand de 19 a 27
			}
		}
	}
} //10000+rand()%(99999-10000+1);

void imprimirarreglo(float arreglo[][5], char marcas[][10]){//funcion para imprimir el arreglo
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\t\tLATA\t500ML\t600ML\t1LT\t2LT\n");//imprimir el encabezado
	for(int i=0; i<6; i++){//ciclo para imprimir el arreglo de forma que quede como tabla
		printf("%s\t", marcas[i]);
		for(int j=0; j<5;j++){
			printf("%.2f\t", arreglo[i][j]);
		}
		printf("\n");// salto de linea
	}
	/*
	//lineas horizontales
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,8);
		printf("%c", 196);
	}
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,10);
		printf("%c", 196);
	}
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,12);
		printf("%c", 196);
	}
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,14);
		printf("%c", 196);
	}
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,16);
		printf("%c", 196);
	}
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,18);
		printf("%c", 196);
	}
	for(int i=0;i<40;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14+i,20);
		printf("%c", 196);
	}
	//lineas verticales
	for(int i=0;i<12;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(14,9+i);
		printf("%c", 186);
	}
	for(int i=0;i<12;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(22,9+i);
		printf("%c", 186);
	}
	for(int i=0;i<12;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(30,9+i);
		printf("%c", 186);
	}
	for(int i=0;i<12;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(38,9+i);
		printf("%c", 186);
	}
	for(int i=0;i<12;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(46,9+i);
		printf("%c", 186);
	}
	for(int i=0;i<12;i++){
		SetConsoleTextAttribute(hd, 14); 
	    gotoxy(54,9+i);
		printf("%c", 186);
	}
	getch();
	*/
	
}
void porPresentacion(float arreglo[][5], char presentacion[], char marcas[][10]){
	if(strcmp(presentacion, "LATA")==0){//se checa si la presentacion coincide con este string se regresa el cero si c ve que es real la igualdad
		float mayor= arreglo[0][0];//se iguala un valor a mayor para tenerlo como comparacion
		for(int i=0; i<5;i++){//se recorren todas las filas
			if(arreglo[i][0] > mayor){//si en alguna tra fila el numero es mayor
				mayor=arreglo[i][0];//le quita el mayor a el numero al que se lo pusimos al principio
			}
		}
		printf("\n\nProducto mas caro: ");//ya que se recorrieron todas las filas
		for(int i=0; i<5;i++){//se recorren de nuevo para ver en que i osea en que numero exacto de fila esta el mayor
			if(arreglo[i][0] == mayor){//al encontranse el mayor
				printf("%s\t", marcas[i]);//se imprime el string que se encuentra en la misma fila en el arregl de marcas
			}
		}
	}else{
		if(strcmp(presentacion, "500ML")==0){//se checa si la presentacion coincide con este string
			float mayor= arreglo[0][1];
			for(int i=0; i<5;i++){
				if(arreglo[i][1] > mayor){
					mayor=arreglo[i][1];
				}
			}
			printf("\nProducto mas caro: ");
			for(int i=0; i<5;i++){
				if(arreglo[i][1] == mayor){
					printf("%s\t", marcas[i]);
				}
			}
		}else{
			if(strcmp(presentacion, "600ML")==0){//se checa si la presentacion coincide con este string
				float mayor= arreglo[0][2];
				for(int i=0; i<5;i++){
					if(arreglo[i][2] > mayor){
						mayor=arreglo[i][2];
					}
				}
				printf("\nProducto mas caro: ");
				for(int i=0; i<5;i++){
					if(arreglo[i][2] == mayor){
						printf("%s\t", marcas[i]);
					}
				}
			}else{
				if(strcmp(presentacion, "1LT")==0){//se checa si la presentacion coincide con este string
					float mayor= arreglo[0][3];
					for(int i=0; i<5;i++){
						if(arreglo[i][3] > mayor){
							mayor=arreglo[i][3];
						}
					}
					printf("\nProducto mas caro: ");
					for(int i=0; i<5;i++){
						if(arreglo[i][3] == mayor){
							printf("%s\t", marcas[i]);
						}
					}
				}else{
					if(strcmp(presentacion, "2LT")==0){//se checa si la presentacion coincide con este string
					float mayor= arreglo[0][4];
					for(int i=0; i<5;i++){
						if(arreglo[i][4] > mayor){
							mayor=arreglo[i][4];
						}
					}
					printf("\nProducto mas caro: ");
					for(int i=0; i<5;i++){
						if(arreglo[i][4] == mayor){
							printf("%s\t", marcas[i]);
						}
					}
					}else{
						printf("presentacion inexistente");//si no coincidio con ninguno imprime esto
					}
				}
			}
		}
	}
}

void unLitro(float arreglo[][5], char marcas[][10]){
	float mayor= arreglo[0][3];//igual que antes se le concede a un numero el mayor
	float segundomayor=0;//variable para el segundo mayor
	int y;
	for(int i=0; i<5;i++){
		if(arreglo[i][3] > mayor){
			mayor=arreglo[i][3];
		}
	}
	printf("\n\nPRESENTACION DE 1 LITRO: \n");//se imprime Presentacion de 1 Litro:
	for(int i=0; i<5;i++){
		if(arreglo[i][3] == mayor){
			printf("%s\n", marcas[i]);// se imprime la marca que esta en la misma fila que el mayor
			y=i;//se usa otra variable la cual se iguala a el numero de fila de el mayor
		}
	}
	for(int i=0; i<5; i++){//se recorre un ciclo for para igualar sel segundo mayor a un numero igual que al principio con el mayor
		if(y!=i){//para hacer la igualacion el numero debe ser diferente a mayor
			segundomayor=arreglo[i][3];//se iguala
		}
	}
	for(int i=0; i<5; i++){
		if(arreglo[i][3] > segundomayor){//se checa fila por fila otraves si en otra fila hay un numero mayor a el segundomayor
			if(y!=i){//pero como el segundo mayor seria menor al mayor quitamos la posibilidad de darle ese puesto a el mayor 
				segundomayor=arreglo[i][3];
			}
		}
	}
	for(int i=0; i<5;i++){
		if(arreglo[i][3] == segundomayor){//se checa fila por fila el numero de fila de el segundo mayor
			printf("%s", marcas[i]);//al momento de encontrar el segundomayor se imprime la marca que esta en la misma fila que el
			y=i;
		}
	}
	
}

void porProducto(float arreglo[][5], char marcas[][10]){
	float promedio=0;
	float menor[5];
	printf("\n\nPROMEDIO POR PRODUCTO");
	printf("\n%s\t", marcas[0]);//se imprime la marca primero
	for(int i=0;i<5;i++){// luego se recorren todas las columnas de esa marca
		promedio=promedio+arreglo[0][i];//se sabe que son columnas de esa marca ya que establecemos la misma fila que la marca, al ir recorriendo las columnas se le van sumando sus valores a promedio
	}
	promedio=promedio/5;// cunado promedio tiene todos los valores se divide entra la catidad de columnas para sacar el promedio
	printf("%.2f", promedio);//se imprime el promedio
	menor[0]=promedio;//voy guardando los promedios de cada marca para ver cual es el menor despues
	promedio=0;// se reinicia el promedio para usarlo con el siguiente producto
	
	printf("\n%s\t", marcas[1]);
	for(int i=0;i<5;i++){
		promedio=promedio+arreglo[1][i];
	}
	promedio=promedio/5;
	printf("%.2f", promedio);
	menor[1]=promedio;
	promedio=0;
	
	printf("\n%s\t", marcas[2]);
	for(int i=0;i<5;i++){
		promedio=promedio+arreglo[2][i];
	}
	promedio=promedio/5;
	printf("%.2f", promedio);
	menor[2]=promedio;
	promedio=0;
	
	printf("\n%s\t", marcas[3]);
	for(int i=0;i<5;i++){
		promedio=promedio+arreglo[3][i];
	}
	promedio=promedio/5;
	printf("%.2f", promedio);
	menor[3]=promedio;
	promedio=0;
	
	printf("\n%s\t", marcas[4]);
	for(int i=0;i<5;i++){
		promedio=promedio+arreglo[4][i];
	}
	promedio=promedio/5;
	printf("%.2f", promedio);
	menor[4]=promedio;
	promedio=0;
	
	printf("\n%s\t", marcas[5]);
	for(int i=0;i<5;i++){
		promedio=promedio+arreglo[5][i];
	}
	promedio=promedio/5;
	printf("%.2f", promedio);
	menor[5]=promedio;
	promedio=0;
	
	float elmenor=menor[0];//ahora checo cual es el promedio menor
	for(int i=0; i<5;i++){//igual se recorren todas las filas
		if(menor[i] < elmenor){// se checan si son menores al que le pusimos menor primero
			elmenor=menor[i];//si lo es se van cambiando el puesto de menor
		}
	}
	printf("\nPRODUCTO MAS BARATO: ");//se imprime producto mas barato:
	for(int i=0; i<5;i++){//se checvan las filas
		if(menor[i] == elmenor){//se checa la fila exacta del promedio menor
			printf("%s\t", marcas[i]);//y se imprime la marca que esta en esa misma fila
		}
	}
}

void encabezado()//impresion de mis propios datos
{
	printf("------------------------------------\n");
	printf("Victor Alfonso Covarrubias Solis\n");
	printf("177294\n");
	printf("Laboratorio de Programacion 1\n");
	printf("Grupo C\n");
	printf("Semestre 2\n");
	printf("Martes 26 de abril del 2022\n");
	printf("------------------------------------\n");
}
