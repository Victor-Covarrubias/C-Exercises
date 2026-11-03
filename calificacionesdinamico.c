#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//funciones
void R_TN(int FILAS, char **nombres){
	for(int i=0;i<FILAS;i++){
		printf("Escribe la materia %d\n", i+1);
		scanf("%s", nombres[i]);
	}
}

void R_TC(int FILAS, int COLS, float **cal, bool bandera){
	for(int i=0;i<FILAS;i++){
		bandera=true;
		printf("Escribe las calificaciones de la materia %d\n", i+1);
		for(int j=0;j<COLS;j++){
			do{
				printf("Calificacion %d:", j+1);
				scanf("%f", &cal[i][j]);
				if(cal[i][j]>=0 && cal[i][j]<=10){
					bandera=false;
				}
			}while(bandera==true);
			
		}
	}
	
}

void tabla(int FILAS, int COLS, float **cal, char **nombres, float suma, int cont, float promedio){
	for(int i=0;i<FILAS;i++){
		cont=0;
		suma=0;
		promedio=0;
		printf("%s\t", nombres[i]);
		for(int j=0;j<COLS+1;j++){
			if(j==COLS){
				promedio=suma/cont;
				printf("%.2f\t", promedio);
			}else{
				printf("%f\t", cal[i][j]);
				suma+=cal[i][j];
				cont++;
			}
		}
		printf("\n");
	}
}


int main(){
	
	float **cal;
	char **nombres;
	int FILAS;
	int COLS;
	float suma;
	int cont;
	float promedio=0;
	bool bandera;
	
	
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	
	printf("Cuantas materias necesitas\n");
	scanf("%d", &FILAS);
	
	printf("Cuantas calificaciones necesitas?\n");
	scanf("%d", &COLS);
	
	cal = (float**)malloc (FILAS*sizeof(float *));
	if(cal==NULL){
		printf("Problemas al reservar memoria");
		exit(1);
	}
	for(int x=0;x<FILAS;x++){
		cal[x] = (float*) malloc ((COLS+1)*sizeof(float));
		if(cal[x]==NULL){
			printf("Problemas al reservar memoria");
			exit(1);
		}
	}
	nombres = (char**)malloc (FILAS*sizeof(char *));
	if(nombres==NULL){
		printf("Problemas al reservar memoria");
		exit(1);
	}
	for(int x=0;x<FILAS;x++){
		nombres[x] = (char*) malloc (20*sizeof(char));
		if(nombres[x]==NULL){
			printf("Problemas al reservar memoria");
			exit(1);
		}
	}
	
	R_TN(FILAS, nombres);
	R_TC(FILAS, COLS, cal, bandera);
	
	
	
	printf("Impresion de la tabla\n\n");
	tabla(FILAS, COLS, cal, nombres, suma, cont, promedio);
	
	free(nombres);
	free(cal);
	
	return 0;
}
