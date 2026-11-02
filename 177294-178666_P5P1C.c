#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
 void gotoxy(int x,int y){
 HANDLE hcon;
 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y= y;
 SetConsoleCursorPosition(hcon,dwPos);
 } 


int main(){
	char nombre[30]="";
    int edad;
	char telefono[11]="";
	int calle,numero;
	char colonia[20]="";
	char Cpostal[6]="";
	char ciudad[20]="";
	char curp[19]="";
	char email[30]="";
	int escolar;
	char escolaridad[13]="";
	char estadoc[8]="";
    int eleccion;
    int numa;
    int i;
    int j;
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    
    do{
    	
    	system("cls");
    	srand(time(NULL));
    	printf("\nEscribe tu Nombre Completo: ");
    	scanf("%s",nombre);
    	fflush(stdin);
    	printf("\nEscribe tu Edad: ");
    	scanf("%d",&edad);
    	fflush(stdin);
    	printf("\nEscribe tu Telefono: ");
    	scanf("%s",telefono);
    	printf("\nEscribe tu Direccion");
    	printf("\nEscribe tu Calle: ");
    	scanf("%d",&calle);
    	printf("\nEscribe tu Numero de casa: ");
    	scanf("%d",&numero);
    	fflush(stdin);
    	printf("\nEscribe tu Colonia: ");
    	scanf("%s",colonia);
    	fflush(stdin);
    	printf("\nEscribe tu Codigo Postal: ");
    	scanf("%s",Cpostal);
    	fflush(stdin);
    	printf("\nEscribe tu Ciudad: ");
    	scanf("%s",ciudad);
    	fflush(stdin);
    	printf("\nEscribe tu CURP: ");
    	scanf("%s",curp);
    	fflush(stdin);
    	printf("\nEscribe tu correo electronico: ");
    	scanf("%s",email);
    	printf("Escoge tu escolaridad: \n"); 
    	printf("1.-Primaria\n");
    	printf("2.-Secundaria\n");
    	printf("3.-Preparatoria\n");
    	printf("4.-Universidad\n");
    	printf("5.-Licenciatura\n");
    	scanf("%d",&escolar);
    	switch(escolar){
    		case 1:
    			strcpy(escolaridad, "Primaria");
    			break;
    		case 2:
    			strcpy(escolaridad, "Secundaria");
    			break;
    		case 3:
    			strcpy(escolaridad, "Preparatoria");
    			break;
    		case 4:
    			strcpy(escolaridad, "Universidad");
    			break;
    		case 5:
    			strcpy(escolaridad, "Licenciatura");
    			break;
    		default:
    			printf("Opcion no valida");
    			break;
    	}
    	printf("Dime tu Estado \n");
    	scanf("%s",estadoc);
    	fflush(stdin);
    	printf("La informacion es la correcta? 1 --> Si  2 --> No\n");
    	scanf("%d",&eleccion);
    	
	}while(eleccion== 2);
    
    if(eleccion == 1){
    	system("cls");
    	numa=1000+rand()%(2500-1000+1);
        printf("Nombre: %s \n",nombre);
        printf("Edad: %d \n",edad);
        printf("Telefono: %s \n",telefono);
        printf("Calle: %d \n",calle);
        printf("Numero: %d \n",numero);
        printf("Colonia: %s \n",colonia);
        printf("Codigo Postal: %s \n",Cpostal);
        printf("Ciudad: %s \n",ciudad);
        printf("CURP: %s \n",curp);
        printf("Correo Electronico: %s \n",email);
        printf("Escolaridad: %s \n", escolaridad);
        printf("Estado: %s \n",estadoc);
        printf("%d", numa);
        	//linea horizontal de arriba
		for(i=0;i<75;i++){
   			SetConsoleTextAttribute(hd, 14); 
        	gotoxy(1+i,0);
			printf("%c", 205);
		}
		//linea horizontal de abajo
		for(i=0;i<75;i++){
   			SetConsoleTextAttribute(hd, 14); 
        	gotoxy(1+i,30);
			printf("%c", 205);
		}
		//linea vertical izquierda
		for(i=0;i<29;i++){
   			SetConsoleTextAttribute(hd, 14); 
        	gotoxy(0,1+i);
			printf("%c", 186);
		}
		//linea vertical derecha
		for(i=0;i<29;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(75,1+i);
			printf("%c", 186);
		}
		//linea horizontal primera
		for(i=0;i<74;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(1+i,5);
			printf("%c", 205);
		}
		//linea horizontal segunda
		for(i=0;i<74;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(1+i,9);
			printf("%c", 205);
		}
		//linea horizontal tercera
		for(i=0;i<74;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(1+i,20);
			printf("%c", 205);
		}
		//linea horizontal segunda y medio
		for(i=0;i<38;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(37+i,14);
			printf("%c", 205);
		}
		//linea vertical primera
		for(i=0;i<15;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(36,10+i);
			printf("%c", 186);
		}
		//linea horizontal cuarta
		for(i=0;i<74;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(1+i,24);
			printf("%c", 205);
		}
		
		//esquinas
		SetConsoleTextAttribute(hd, 14); 
    	gotoxy(0,0);
    	printf("%c", 201);
    	SetConsoleTextAttribute(hd, 14); 
    	gotoxy(75,0);
    	printf("%c", 187);
    	SetConsoleTextAttribute(hd, 14); 
    	gotoxy(0,30);
    	printf("%c", 200);
    	SetConsoleTextAttribute(hd, 14); 
    	gotoxy(75,30);
    	printf("%c", 188);
    	getch();

    }
    return 0;
}
