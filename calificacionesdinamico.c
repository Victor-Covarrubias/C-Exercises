#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


//funciones
void R_TN(int filas, char **nombres){
	for(int i=0;i<filas;i++){
		printf("Escribe la materia %d\n", i+1);
		scanf("%s", nombres[i]);
	}
}

void R_TC(int filas, int cols, float **cal, bool bandera){
	for(int i=0;i<filas;i++){
		bandera=true;
		printf("Escribe las calificaciones de la materia %d\n", i+1);
		for(int j=0;j<cols;j++){
			do{
				bandera=true;
				printf("Calificacion %d:", j+1);
				scanf("%f", &cal[i][j]);
				if(cal[i][j]>=0 && cal[i][j]<=10){
					bandera=false;
				}
			}while(bandera);
			
		}
	}
	
}

void tabla(int filas, int cols, float **cal, char **nombres){
	float suma;
	int cont;
	float promedio=0;

	for(int i=0;i<filas;i++){
		cont=0;
		suma=0;
		promedio=0;
		printf("%s\t", nombres[i]);
		for(int j=0;j<cols+1;j++){
			//si j es igual que cols significa que ya imprimio todas las calificaciones por eso es que puse el cols+1 en el for para tener una columna extra y poner el promedio
			if(j==cols){
				promedio=suma/cont;
				printf("%.2f\t", promedio);
			}else{
				printf("%.2f\t", cal[i][j]);
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
	int filas;
	int cols;
	bool bandera;
	
	
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	
	printf("Cuantas materias necesitas\n");
	scanf("%d", &filas);
	
	printf("Cuantas calificaciones necesitas?\n");
	scanf("%d", &cols);
	
	cal = (float**)malloc (filas*sizeof(float *));
	if(cal==NULL){
		printf("Problemas al reservar memoria");
		exit(1);
	}
	for(int x=0;x<filas;x++){
		cal[x] = (float*) malloc ((cols+1)*sizeof(float));
		if(cal[x]==NULL){
			printf("Problemas al reservar memoria");
			exit(1);
		}
	}
	nombres = (char**)malloc (filas*sizeof(char *));
	if(nombres==NULL){
		printf("Problemas al reservar memoria");
		exit(1);
	}
	for(int x=0;x<filas;x++){
		nombres[x] = (char*) malloc (20*sizeof(char));
		if(nombres[x]==NULL){
			printf("Problemas al reservar memoria");
			exit(1);
		}
	}
	
	R_TN(filas, nombres);
	R_TC(filas, cols, cal, bandera);
	
	
	
	printf("\nImpresion de la tabla\n\n");
	tabla(filas, cols, cal, nombres);

	//liberar cada fila
	for(int i=0; i< filas; i++){
		if(cal != NULL){
			free(cal[i]);
		}

		if(nombres != NULL){
			free(nombres[i]);
		}
	}
	
	//liberar los arrays de punteros
	free(nombres);
	free(cal);
	
	return 0;
}
