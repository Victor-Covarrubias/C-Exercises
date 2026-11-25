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
	char nombre[50]="";
    int edad;
	char telefono[11]="";
	int calle,numero;
	char colonia[50]="";
	char Cpostal[6]="";
	char ciudad[50]="";
	char curp[19]="";
	char email[50]="";
	int escolar;
	char escolaridad[13]="";
	char estadoc[50]="";
    int eleccion;
    int numa;
    int i;
    int j;
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    
	srand(time(NULL));
    do{
    	system("cls");

    	printf("\nEscribe tu Nombre Completo: ");
    	//scanf("%s",nombre);
    	//fflush(stdin);
		fgets(nombre, sizeof(nombre), stdin);
		//con strcpn encuentro el salto de line y luego este lo cambio pro el final de la cadena
		nombre[strcspn(nombre, "\n")] = '\0';

    	printf("\nEscribe tu Edad: ");
    	scanf("%d",&edad);

    	printf("\nEscribe tu Telefono: ");
    	scanf("%s",telefono);

    	printf("\nEscribe tu Direccion");
    	printf("\nEscribe tu Calle(numero): ");
    	scanf("%d",&calle);
    	printf("\nEscribe tu Numero de casa: ");
    	scanf("%d",&numero);

		//para limpiar el ultimo salto de linea
    	getchar();

    	printf("\nEscribe tu Colonia: ");
    	//scanf("%s",colonia);
		fgets(colonia, sizeof(colonia), stdin);
		//con strcpn encuentro el salto de line y luego este lo cambio pro el final de la cadena
		colonia[strcspn(colonia, "\n")] = '\0';

    	printf("\nEscribe tu Codigo Postal: ");
    	scanf("%s",Cpostal);

    	//para limpiar el ultimo salto de linea
    	getchar();
		
    	printf("\nEscribe tu Ciudad: ");
    	//scanf("%s",ciudad);
		fgets(ciudad, sizeof(ciudad), stdin);
		//con strcpn encuentro el salto de line y luego este lo cambio pro el final de la cadena
		ciudad[strcspn(ciudad, "\n")] = '\0';

    	printf("\nEscribe tu CURP: ");
    	scanf("%s",curp);

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

		//para limpiar el ultimo salto de linea
    	getchar();

    	printf("Dime tu Estado \n");
    	//scanf("%s",estadoc);
		fgets(estadoc, sizeof(estadoc), stdin);
		//con strcpn encuentro el salto de line y luego este lo cambio pro el final de la cadena
		estadoc[strcspn(estadoc, "\n")] = '\0';

    	printf("La informacion es la correcta? 1 --> Si  2 --> No\n");
    	scanf("%d",&eleccion);
    	
	}while(eleccion== 2);
    
    if(eleccion == 1){
    	system("cls");
    	numa=1000+rand()%(2500-1000+1);
        printf(" Nombre: %s \n",nombre);
        printf(" Edad: %d \n",edad);
        printf(" Telefono: %s \n",telefono);
        printf(" Numero de Calle: %d \n",calle);
        printf(" Numero de Casa: %d \n",numero);
		printf("\n");
        printf(" Colonia: %s \n",colonia);
        printf(" Codigo Postal: %s \n",Cpostal);
        printf(" Ciudad: %s \n",ciudad);
		printf("\n");
        printf(" CURP: %s \n",curp);
        printf(" Correo Electronico: %s \n",email);
        printf(" Escolaridad: %s \n", escolaridad);
        printf(" Estado: %s \n",estadoc);
        printf(" Id: %d", numa);

		/*
		//linea horizontal de arriba
		for(i=0;i<75;i++){
   			SetConsoleTextAttribute(hd, 14); 
        	gotoxy(1+i,0);
			printf("%c", 205);
		}
		*/
		
		//linea vertical izquierda
		for(i=0;i<15;i++){
   			SetConsoleTextAttribute(hd, 14); 
        	gotoxy(0,0+i);
			printf("%c", 186);
		}

		//linea vertical derecha
		for(i=0;i<15;i++){
   			SetConsoleTextAttribute(hd, 14); 
    	    gotoxy(75,0+i);
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
    	    gotoxy(1+i,15);
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
    	gotoxy(0,15);
    	printf("%c", 200);
    	SetConsoleTextAttribute(hd, 14); 
    	gotoxy(75,15);
    	printf("%c", 188);
		
		
    	getch();

    }
    return 0;
}
