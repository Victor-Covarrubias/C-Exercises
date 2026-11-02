//librerias
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

//estructura para guardar los datos de los almnos
typedef struct{
 char nom_al[20];//nombre del inscrito
 int edad;//edad del inscrito
 int id_al;//id unico para el inscrito
}TipoAl; 

//funciones
void encabezado();//funcion para imprimir encabezado
void capturaIns(TipoAl array[][3], char clases[][15]);
int generaID(TipoAl array[][3], int cn, int i);
void impresionUno(TipoAl array[][3], char clases[][15]);

//variables globales
int aux1[3]={0};
int aux2[3]={0};
int aux3[3]={0};

main(){//funcion principal
	srand(time(NULL));//inicializar la semilla
	char clases[5][15]={{"PROGRAMACION"},{"ELECTRONICA"},{"ARTES"}};//array con los nombres de los grupos que usaran en el codigo los reduje ya que solo se usaran 3
	TipoAl array[3][3];//creacion de array de 3 x 3 para el registro de los datos en la estructura
	
	capturaIns(array, clases);//llamada ala funcion capturains
	impresionUno(array, clases);//impresion de los registros
	
	return 0;
}
void encabezado(){//cuerpo de la funcion encabezado
	printf("Covarrubias Solis Victor Alfonso\n177294\nlaboratorio de Programacion 2\nGrupo A\n16/8/22\n----------------------------------\n\n");//impresion de datos
}
void capturaIns(TipoAl array[][3], char clases[][15]){//llenado de registros de los inscritos
	int cn;//variable para guardar el numero de la clase
	bool bandera=true;//variable para checar si el nombre es en verdad un nombre sin espacios
	int cont;
	for(int x=0;x<3;x++){//llenado de datos
		printf("Grupo %d: ", x+1);//impresion de el numero de grupo que se esta llenando
		for(int y=0;y<3;y++){
			//do{//ciclo para validar el nombre
			//cont=0;//se inicializa el contador
			printf("\nnombre del alumno %d: ", y+1);
			scanf("%s", &array[x][y].nom_al);//se guarda el nombre
				//for(int i=0; i<20; i++){
					//if(array[x][y].nom_al==' '){//se checa caracter por caracter si se encuentra un espacio en la palabra
					//	cont++;
					//}
					//if(cont==0){
					//	bandera=false;//si lo que se guardo en la variable auxiliar es lo requerido se acabara el ciclo
					//}
				//}
			//}while(bandera==true);
			array[x][y].edad=rand()%24+12;//generacion aleatoria de edad
			cn=x;// se le asigna a cn el valor de x
			array[x][y].id_al=generaID(array, cn, y);//se le envia cn para que compare en que clase se encuentra
		}
	}
	
}
int generaID(TipoAl array[][3], int cn, int i){//generacion aleatoria de id dependiendo de la clase
	int id, cont;
	bool flag=true;
	
	do{//ciclo para que si la id se repite entonces el numero aleatorio se cambia
		cont=0;
		if(cn==0){//si se encuentra en programacion
			aux1[i]=rand()%12+100;//del 100 al 111
			for(int y=0;y<3;y++){
				if(aux1[y]==aux1[i]){
					cont++;
				}
			}
			if(cont<2){
				flag=false;
				id=aux1[i];
			}
		}
		if(cn==1){//si se encuentra en electronica
			aux2[i]=rand()%12+120;//del 120 al 131
			for(int y=0;y<3;y++){
				if(aux2[y]==aux2[i]){
					cont++;
				}
			}
			if(cont<2){
				flag=false;
				id=aux2[i];
			}
		}
		if(cn==2){//si se encuentra en artes
			aux3[i]=rand()%12+140;//del 140 al 151
			for(int y=0;y<3;y++){
				if(aux3[y]==aux3[i]){
					cont++;
				}
			}
			if(cont<2){
				flag=false;
				id=aux3[i];
			}
		}
	}while(flag==true);
	return id;//se retorna el valor de la id
}
void impresionUno(TipoAl array[][3], char clases[][15]){
	printf("Grupos creados: %d\n", 3);
	for(int x=0;x<3;x++){//impresion de datos
		printf("%s-", clases[x]);
		printf("inscritos: %d\n", 3);
		printf("NOMBRE\tEDAD\tID\n---------------------\n");//impresion de el encabezado de los datos
		for(int y=0;y<3;y++){//se imprimen los datos
			printf("%s\t", array[x][y].nom_al);
			printf("%d\t",  array[x][y].edad);
			printf("%d\n",  array[x][y].id_al);
		}
		printf("\n");//salto de linea
	}
}
