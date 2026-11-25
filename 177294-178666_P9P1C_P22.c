#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
} 
 

int main(){
	printf("Covarrubias Solis Victor Alfonso-177294\n\nprogramacion 1\n presiona enter");
	getch();
	
	char nombre[50]="";
	char email[30]="";   //5 caracteres @ 5 caracteres . com
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int cont5=0;
	int cont6=0;
	int e;
	bool control=true;
    int edad,cont=0;
	char telefono[11]="";
	int calle,numero;
	char colonia[50]="";
	char Cpostal[6]="";
	char ciudad[50]="";
	char curp[19]="";
	int escolar;
	char escolaridad[13]="";
	char estadoc[50]="";
    int eleccion;
    int numa,eleccion2;
    int i;
    int j;
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    do{
    	bool bandera = true, bandera3=true;
    	system("cls");
    	srand(time(NULL));// se reinicia el numero aleatorio
    	printf("\nEscribe tu Nombre Completo: ");/*El usuario ingresara su nobre completo*/
    	fflush(stdin);
    	scanf("%[^\n]",nombre);
    	fflush(stdin);/*sirve para realizar la limpieza del buffer de entrada*/
    	do{//checar el rango de edad si esta entre 3 y 89 es valida
    		printf("\nEscribe tu Edad: ");
			//si es letra y no numero
    		if(scanf("%d",&edad) != 1){
				printf("debe ser un numero\n");

				while(getchar() != '\n');
				edad = 0;
				continue;
			}

    		if(edad>89 || edad<3){
    		   	printf("su edad no es aceptada, !!vuelve a intentarlo!!\n");
			}
		}while(edad<3 || edad>89);
		
    	while(bandera){//el while se repite mientras el bolenano sea verdadero
	    	printf("\nEscribe tu Telefono: "); /*El usuario ingresa su numero telefonico solo son 10 digitos no mas*/
	   		scanf("%s",telefono);//se lee la cadena
	    	fflush(stdin);
	    	cont=0;// se inicializa el contador
	 
	    	if(strlen(telefono)>10){//si la cadena es de mas de 10 caracteres se repite el while 
	    		continue;//el continue hace que se regrese al while y por ende vuelva a pedir el telefono
			}else{
				for(i=0; i<strlen(telefono); i++){// el strlen hace que la i no pueda incrementarse mas que el tama�o de la cadena
					if(isalpha(telefono[i]) || telefono[i]==' '){// se checa si algun caracter de la cadena es letra o espacio, si lo es se repite el while
						continue;//el continue hace que se regrese al while y por ende vuelva a pedir el telefono
					}else{
						for(i=0;i<strlen(telefono);i++){//se checa caracter a caracter si es un numero
							if(isdigit(telefono[i])){//se checa caracter a caracter si es un numero
								cont++;// si es un numero el caracter se suma uno al contador 
							
							}
						}
					}
				}
			}
			if(cont==10){// se checa si el contador llego a diez de lo contrario se repetira el while
				bandera=false;// si el contador es igual a 10 la variable boleana se cambia a falso para salir del while inmediatamente
			}
		}
    	printf("\nEscribe tu Direccion");
    	printf("\nEscribe tu Calle: ");/*El usuario ingresa el nombre de la calle por donde vive*/
    	scanf("%d",&calle);
    	fflush(stdin);
    	printf("\nEscribe tu Numero de casa: ");
    	scanf("%d",&numero);/*El usuario ingresa el numero de su casa*/
    	fflush(stdin);
    	printf("\nEscribe tu Colonia: ");
    	scanf("%[^\n]",colonia);
    	fflush(stdin);
    	printf("\nEscribe tu Codigo Postal: ");
    	scanf("%s",Cpostal);/*El usuario ingresa el codigo postal solo 5 digitos*/
    	fflush(stdin);
    	printf("\nEscribe tu Ciudad: ");
    	scanf("%[^\n]",ciudad);/*El usuario ingresa el nomre de la ciudad en donde vive*/
    	fflush(stdin);
    	printf("\nEscribe tu CURP: ");
    	scanf("%s",curp);/*El usuario ingresa su curp solo 18 caracteres*/
    	fflush(stdin);
    	do{
			cont1=0;
			cont2=0;
			cont3=0;
			cont4=0;
			cont5=0;
			cont6=0;
			printf("Escribe tu correo: ((5 letras minusculas)@gmail.com)");
			scanf("%s", email);//Se le pide al usuario ingresar un correo electronico con las especificaciones correspondientes
			
			if(strlen(email)>15){
				continue;
			}else{
				if(email[0]>=97 && email[0]<=122){//Solo 5 seran validos las letras minusculas
					cont1++;
				}else{
					continue;
				}
				for(e=1;e<5;e++){
					if(email[e]>=97 && email[e]<=122){
						cont2++;
					}else{
						if(email[e]==46 || email[e]==95){//se acepta un punto o guion bajo si el usuario lo desea
							cont2++;
						}else{
							continue;
						}
					}
				}
				if(email[5]==64){//En esta parte el usuario se le obliga a colocar un @ si no lo hace no se hara valido 
					cont3++;
				}else{
					continue;
				}
				for(e=6;e<11;e++){
					if(email[e]>=97 && email[e]<=122){// 5 letras minusculas
						cont4++;
					}else{
						continue;
					}
				}
				if(email[11]==46){//Se le solicita escribir un punto
					cont5++;
				}else{
					continue;
				}
				if(email[12]==99){//escribir la letra c
					cont6++;
				}else{
					continue;
				}
				if(email[13]==111){//escribir la letra o
					cont6++;
				}else{
					continue;
				}
				if(email[14]==109){//escribir la letra m
					cont6++;
				}else{
					continue;
				}
			}
			if(cont1==1 && cont2==4 && cont3==1 && cont4==5 && cont5==1 && cont6==3){
				control=false;
			}
		}while(control);/*El usuario ingresa su correo electronico*/
		
    	do{
			printf("\nEscoge tu escolaridad: \n");   //esta funcion switch servira para saber que escolaridad tiene,
	    	printf("1.-Primaria\n");                // dependiendo la que escoga
	    	printf("2.-Secundaria\n");
	    	printf("3.-Preparatoria\n");
	    	printf("4.-Universidad\n");
	    	printf("5.-Licenciatura\n");
	    	scanf("%d",&escolar);
	    	switch(escolar){// se checa lo que contiene la variable escolar y mediante eso escoje para donde ir
	    		case 1:
	    			strcpy(escolaridad, "Primaria");// el strcpy hace que la variable escolaridad tenga Primaria como valor solo se puede con cadenas
	    			break;// el break hace que termine la opcion y que no se siga con lo que esta mas abajo
	    		case 2:
	    			strcpy(escolaridad, "Secundaria");// el strcpy hace que la variable escolaridad tenga Primaria como valor solo se puede con cadenas
	    			break;
	    		case 3:
	    			strcpy(escolaridad, "Preparatoria");// el strcpy hace que la variable escolaridad tenga Primaria como valor solo se puede con cadenas
	    			break;
	    		case 4:
	    			strcpy(escolaridad, "Universidad");// el strcpy hace que la variable escolaridad tenga Primaria como valor solo se puede con cadenas
	    			break;
	    		case 5:
	    			strcpy(escolaridad, "Licenciatura");// el strcpy hace que la variable escolaridad tenga Primaria como valor solo se puede con cadenas
	    			break;
	    		default:// si lo que contiene escolar no es una opcion se va directamente a esta y imprime lo siguiente:
	    			printf("\n!!Opcion no valida intentalo otra vez!!\n");
	    			break;// por lo regular esta no es necesaria ya que es la ultima opcion, pero la pongo porque si 
	    	}
		}while((escolar<1)||(escolar>5));// se checa si enverdad se entro a una de las opciones si no fue asi se repite la pregunta
		
        while(bandera3){
			printf("\nElige tu estado civil \n"); /*se le pregunta al usuario sue estado civil*/
	    	printf("1.-Soltero\n");
	    	printf("2.-Casado\n");
	    	scanf("%d", &eleccion2);
	    	switch(eleccion2){//dependiendo a la opcion que escoga se mostrara en pantalla
	    	 	case 1:
	    	 		strcpy(estadoc,"Soltero");
	    	 		bandera3=false;
	    	 		break;
	    	 	case 2:
	    	 		strcpy(estadoc,"Casado");
	    	 		bandera3=false;
	    	 		break;
	    	 	default:
	    	 		printf("Eleccion erronea vuelva a intentarlo\n");
	    	 		break;
		 	}
		}

    	fflush(stdin);
    	printf("La informacion es la correcta? 1 --> Si  2 --> No\n"); /*aqui al usuario se le pregunta si toda la informacion es correcta y que confirme si es verdad*/
    	scanf("%d",&eleccion);
	}while(eleccion== 2);

    if(eleccion == 1){
    	system("cls");//impresin de variables en coordenadas especificas
    	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hd, 1);
    	gotoxy(28,2);
        printf("Nombre:");
        SetConsoleTextAttribute(hd, 2);
        printf(" %s \n",nombre);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(10,6);
        printf("Edad: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%d \n",edad);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(40,6);
        numa=1000+rand()%(2500-1000+1);
        printf("folio");
        SetConsoleTextAttribute(hd, 2);
        printf("%d",numa);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(40,11);
        printf("Telefono: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n",telefono);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(5,10);
        printf("Direccion --Calle: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%d \n",calle);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(5,12);
        printf("Numero: ");
        SetConsoleTextAttribute(hd, 2);
        printf(" %d \n",numero);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(5,14);
        printf("Colonia: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n",colonia);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(5,16);
        printf("Codigo Postal: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n",Cpostal);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(5,18);
        printf("Ciudad: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n",ciudad);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(15,25);
        printf("CURP: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n",curp);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(40,16);
        printf("Correo Electronico: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n",email);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(5,22);
        printf("Escolaridad: ");
        SetConsoleTextAttribute(hd, 2);
        printf("%s \n", escolaridad);
        SetConsoleTextAttribute(hd, 1);
        gotoxy(40,22);
        printf("Estado: ");/*por ultimo se plasma en pantalla todo lo que el usuario escribio*/
        SetConsoleTextAttribute(hd, 2);
		printf("%s\n",estadoc);
		
    	getch();

    }
    return 0;
}
