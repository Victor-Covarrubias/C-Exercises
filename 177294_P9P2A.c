//librerias
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>

//estructura
struct Node{
	int data;
	char user[10];
	struct Node *next;
	struct Node *prev;
}*head = NULL;//lo interpretamos como el apuntador primero

//prototipo de funciones
void encabezado();
void dibujarn();
void dibujarnew();
void dibujarfn(int x);
void dibujarfp(int x);
void insertaNodo();
void insertaNodo();
Node* GeneraNodo();
void eliminaNodo();
void imprimir(int o);

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);//para que funcionen los cambios de color

char sp_car[12]={"#$%&/?!._"};//variable global de la cual se sacan los caracteres especiales
int cont=0;//variable global para contabilizar las veces que se hace algo comienza en 10 porque es la posicion que me sirve al principio
int cont2 =10;//variable global para contabilizar las veces que se hace algo
int posx =5;//variable global para contabilizar las veces que se hace algo
int posy =11;//variable global para contabilizar las veces que se hace algo
Node* j, *k;//decidi poner j aqui porque la usaba en otra funcion tambien, k sirve para ver lo que esta dos nodos adelante de j
int direccion=1010;//variable global para indicar la direccion de memoria

void gotoxy(int x,int y){//funcion que sirve para hacer los dibujos
	HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;//los para metros que resive los cuales son las coordenadas x y y se le asignan a dwPos
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);//se ejecuta la salida en las coordenadas de dwPos
}
int main(){//funcion principal en la cual se encuentran las llamadas a las funciones que hacen el codigo
	encabezado();//llamada de la funcion encabezado
	getch();//funcion de la libreria conio.h para que el programa se detenga mientras no persiva que se tecleo algo
	system("cls");//funcion de la libreria de windows que sirve para que la pantalla se limpie y se pueda mostrar algo donde antes estaba otra cosa
	srand(time(NULL));//inicializar la semilla
	head = NULL;//se inicialñiza el puntero head en nulo aunque esta demas ya que ya estaba arriba como global
	int op_user = 0;//variable que srve para ver que opcion escogio el usuario y ejecutarla
	srand(time(0));////es igual que la anterior de nulo
	
	do{//ciclo do
		fflush(stdin);//se limpia la entrada para que no capte el enter
		SetConsoleTextAttribute(hCon, 15);//se cambia el color
		printf("\n\n\n\n\n\n\t\t\t\t\t\t1.Inserta, 2.Elimina, 3.Terminar programa: ");//se hace impresion de las opciones a disposicion del usuario
		scanf("%d",&op_user);//se lee la eleccion del usuario
		switch(op_user){//uso del switch para que sea como un menu
			case 1: 
				system("cls");//se limpia la salida
				insertaNodo();//se llama a la funcion insertarnodo
				imprimir(1);//se llama a la funcion imprimir
				system("cls");//se limpia la salida
				imprimir(2);
				break;//se termina el case 1 del switch
			case 2: 
				//system("cls");//se limpia la salida
				//imprimir(2);//se llama a la funcion imprimir para que el usuario pueda ver la lsita y escoger que elemento eliminara
				eliminaNodo();//se llama a la funcion imprimir para que el usuario pueda ver
				system("cls");//se limpia la salida
				imprimir(2);//se llama a la funcion imprimir
				system("cls");//se limpia la salida
				break;//se termina el case 2 del switch
			case 3:
				exit(0);
			default://opcion por si el usuario no escoge una opcion existente
				printf("Esta opcion no existe porfavor introduzca una existente\n");//impresion para advertir al usuario
		}
	}while(op_user!=0);//cero para terminar
	
	return 0;//se retorna 0 y se termina la funcion main lo cual termina el programa
	
}
//funciones
void encabezado(){//cuerpo de la funcion encabezado
	printf("Covarrubias Solis Victor Alfonso\n177294\nlaboratorio de Programacion 2\nGrupo A\n16/8/22\n\nIMPORTANTE: DEBE USAR LA PANTALLA COMPLETA DE LO CONTRARIO LAS IMPRESIONES CON GOTOXY NO SALDRAN DE MANERA CORRECTA\n-------------------------------------------------------------------------------------------------------------------\n\n");//impresion de datos
}
void GenCad(char *user){
	int rng;//variable para guardar numeros aleatorios
	char pal[8];//variable que guarda diferentes caracteres y al final le traspasa su contenido a user
	
	for(int i=0;i<7;i++){
		if(i==0 || i==6){
			rng=rand()%26+65;//generacion aleatoria de numeros del 65 al 90
			pal[i]=rng;//al elemento i de pal se le agrega el caracter ascii que coincida con el numero aleatorio
		}
		if(i==1 || i==2){
			rng=rand()%26+97;//generacion aleatoria de numeros del 97 al 122
			pal[i]=rng;//al elemento i de pal se le agrega el caracter ascii que coincida con el numero aleatorio
		}
		if(i==3 || i==4){
			rng=rand()%10+48;//generacion aleatoria de numeros del 48 al 57
			pal[i]=rng;//al elemento i de pal se le agrega el caracter ascii que coincida con el numero aleatorio
		}
		if(i==5){
			rng=rand()%9;//generacion aleatoria de numeros del 0 al 8
			pal[i]=sp_car[rng];//dependiendo de ra sera el caracter especial
		}
	}
	strcpy(user, pal);//se copia el contenido de pal y se pega en user
}
/*DOCUMENTAR*/
Node* GeneraNodo(){//funcion para generar un nuevo nodo
	Node *newNode = new Node;//reserva de memoria para el nuevo nodo //new Node;
	newNode->data = 100 + rand()%501;//asignacion de un numero aleatorio a data
	GenCad(newNode->user);//llamada a la funcion de generar cadena
	newNode->next = NULL;//el puntero next de el nuevo nodo apunta a nulo
	newNode->prev = NULL;//el puntero prev de el nuevo nodo apunta a nulo
	return newNode;//se retorna el nuevo nodo a donde fue llamada la funcion
}
/*DOCUMENTAR*/
void insertaNodo(){//funcion para insertar nodos
	Node *newNode = new Node;//reserva de memoria para el nuevo nodo
	Node *temp = NULL;//creacion de un puntero con valor nulo
	newNode = GeneraNodo();//variable la cual consigue el valor de el retorno de la funcion de generarnodo
	temp = head;//hacemos que el nuevo puntero se situe donde esta head
	
	if(head == NULL){//si head es nulo significa que la lista esta vacia asi que se hace uso de la variable newmode
		head = newNode;//y se establece que es la cabezera de la lista o el primer nodo
	}
	else{ /*DOCUMENTAR*/
		while(temp->next!=NULL)//se checa si el puntero next de temp no sea nulo
		temp = temp->next;//temp avanza hasta donde la condicion del while lo permite
			
		temp->next = newNode;//si llego a nulo significa que ya no hay mas nodos en esta parte por lo tanto se inserta uno nuevo despues de temp
		newNode->prev = temp;//el nuevo nodo ya esta conectado a la lista por el next de temp pero falta conectar su anterior el cual se conecta a temp para completar la lista 
	}		
}
/*DOCUMENTAR*/
void eliminaNodo(){//funcion para eliminar el nodo
    int del_data = 0;//se inicializa en 0
    
    SetConsoleTextAttribute(hCon, 14);//se cambia el color de la salida
    printf("\n\tDato: ");//impresion de la palabra dato
    scanf("%d",&del_data);//se lee el dato que antes se habia inicializado en 0
    
    if(head!=NULL){//como se va recorriendo la lista se checa que esta
        if(head->data == del_data){//se checa que el dato de la lista sea el que escogio el usuario
            head = head->next;//se recorre la lista
            if(head != NULL) head->prev = NULL;}//si la condicion se cumple se le asiga al prev de head el valor nulo
        else{
            for(Node* i = head; i!=NULL; i=i->next){//se recorre la lista hasta llegar a nulo
                if(i->data == del_data){//se comparan los datos
                    if(i->next == NULL)
                        i->prev->next = NULL;//si es verdero a el prev de i y a su next se les asigna nulo
                    else{
                        i->prev->next = i->next;//sus dos apuntadores apuntan a el siguiente
                        i->next->prev = i->prev;}//sus dos apuntadores apuntan al anterior
                    free(i);//se libera la memoria
                    break;//se termina de ejecutar el for
                }
            }
        }    
    }
}
void imprimir(int o){//funcion para crear los dibujos de los nodos
	if(o==1){
		int x = 0;//se inicializa x en 0 esta variable sirve para contar las veces que se hace un dibujo
	
		for( j= head; j!=NULL; j=j->next){//se recorre la lista con un puntero que esta en las variables globales
			k=j->next;//se le iguala a lo que esta siguiente de j->next
			if(j==head){//si el puntero apunta al principio de la lista entonces significa que es la impresion del primer nodo
				SetConsoleTextAttribute(hCon, 10);//el primer nodo se imprimiria de color verde
			}else{
				if(j->next==NULL){// si el puntero apunta al finak de la lista significa que apunta a el ultimo nodo
					SetConsoleTextAttribute(hCon, 9);//el nuevo nodo se imrpimiria en color azul
					dibujarnew();//si es el ultimo se llama la funcion dibujar new
				}else{
					SetConsoleTextAttribute(hCon, 6);//si no es el primero ni elñ ultimo nodo significa que esta en medio de estos asi que se imprime de color amarillo
				}
			}
			if(j->next!=NULL){//se checa si la lista al ser recorrida no llega al ultimo elemento
				dibujarn();//si no es el ultimo elemento se llama la funcion dibujar nodo o n como le puse
				gotoxy(posx,posy+1);//se empieza a usar la funcion gotoxy
				printf("%d",j->data);
				gotoxy(posx+9,posy+1);
				printf("%s",j->user);
				if(j->next==NULL){//se checa a que apunta el apuntador next
					gotoxy(posx+4,posy+3);
					printf("N-NULL");//si no apunta a nada se imprime null
				}else{//si no se cumple eso
					gotoxy(posx+4,posy+3);
					printf("N-%d", direccion+10);//imprime la direccion del siguiente nodo
				}
				if(j->prev==NULL){//se checa a que apunta el apuntador prev
					gotoxy(posx+4,posy+5);
					printf("P-NULL");//si no apunta a nada se imprime null
				}else{//si no se cumple eso
					gotoxy(posx+4,posy+5);
					printf("P-%d", direccion-10);//imprime la direccion del nodo aterior
				}
				gotoxy(posx+4,posy+7);
				printf("%d", direccion);//se imprime la direccion de memoria del nodo del cual se imprimen los datos
				if(j==head){
					gotoxy(posx+4,posy+8);
					printf("Head");//se le pone que es el primer elemento
				}
				dibujarfn(x);//llamada ala funcion dibujar f n
				if(k->next!=NULL){//se checa que no llegue al final porque si lo hace imprimira la flecha prev del element que todavia no esta
					dibujarfp(x);//llamada ala funcion dibujar f p
				}
			}else{
				if(j==head){
					SetConsoleTextAttribute(hCon, 9);//el nuevo nodo se imrpimiria en color azul
					dibujarnew();//si es el ultimo se llama la funcion dibujar new
				}
			}
			x++;
			cont+=40;//se aumentan las cariables globales que cambian la posicion en x para que el soguiente nodo se imprima mas a la derecha
			posx+=40;
			direccion+=10;//se le suma 10 a direccion
			if(x == 4){cont=0;posx=5;cont2+=15;posy+=15;x = 0;}//cuando ya son 4 nodos se empiezan a imrpimir abajo de los anteriores
		}
	}else{
		if(o==2){
			int x = 0;//se inicializa x en 0 esta variable sirve para contar las veces que se hace un dibujo
	
			for( j= head; j!=NULL; j=j->next){//se recorre la lista con un puntero que esta en las variables globales
				if(j==head){//si el puntero apunta al principio de la lista entonces significa que es la impresion del primer nodo
					SetConsoleTextAttribute(hCon, 10);//el primer nodo se imprimiria de color verde
				}else{
					SetConsoleTextAttribute(hCon, 6);//si no es el primero se imprime de color amarillo
				}
				dibujarn();//se llama ala funcion dibujar n
				gotoxy(posx,posy+1);//se empieza a usar la funcion gotoxy
				printf("%d",j->data);
				gotoxy(posx+9,posy+1);
				printf("%s",j->user);
				if(j->next==NULL){//se checa a que apunta el apuntador next
					gotoxy(posx+4,posy+3);
					printf("N-NULL");//si no apunta a nada se imprime null
				}else{//si no se cumple eso
					gotoxy(posx+4,posy+3);
					printf("N-%d", direccion+10);//imprime la direccion del siguiente nodo
				}
				if(j->prev==NULL){//se checa a que apunta el apuntador prev
					gotoxy(posx+4,posy+5);
					printf("P-NULL");//si no apunta a nada se imprime null
				}else{//si no se cumple eso
					gotoxy(posx+4,posy+5);
					printf("P-%d", direccion-10);//imprime la direccion del nodo aterior
				}
				gotoxy(posx+4,posy+7);
				printf("%d", direccion);//se imprime la direccion de memoria del nodo del cual se imprimen los datos
				if(j==head){
					gotoxy(posx+4,posy+8);
					printf("Head");//se le pone que es el primer elemento
				}
				dibujarfn(x);//llamada ala funcion dibujar f n
				if(j->next!=NULL){//se checa que no llegue al final porque si lo hace imprimira la flecha prev del element que todavia no esta
					dibujarfp(x);//llamada ala funcion dibujar f p
				}
				x++;
				cont+=40;//se aumentan las cariables globales que cambian la posicion en x para que el soguiente nodo se imprima mas a la derecha
				posx+=40;
				direccion+=10;//se le suma 10 a direccion
				if(x == 4){cont=0;posx=5;cont2+=15;posy+=15;x = 0;}//cuando ya son 4 nodos se empiezan a imrpimir abajo de los anteriores
			}
		}
	}
	cont=0;//se inicializa la variable global cont en 0 para que se puedan imrprimir los nodos otra vez desde el principio
	posx=5;//se inicializa la variable global posx en 5 para que se puedan imrprimir los nodos otra vez desde el principio
	cont2=0;//se inicializa la variable global cont2 en 0 para que se puedan imrprimir los nodos otra vez desde el principio
	posy=0;//se inicializa la variable global posy en 0 para que se puedan imrprimir los nodos otra vez desde el principio
	direccion=1010;//tambien se inicializa direccion
	getch();//se espera el enter para continuar esto sirve para que permanezca mas tiempo la lista antes de ser borrada
}
void dibujarn(){//funcion para dibujar nodos que no sean el nuevo
	int i=0;//inicializacion de la variable i que nos servira de contador
	do{//dibujar lado horizontal superior
		gotoxy(cont+i,cont2);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar linea separadora horizontal
		gotoxy(cont+i,cont2+2);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar linea separadora horizontal
		gotoxy(cont+i,cont2+4);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar lado horizontal inferior
		gotoxy(cont+i,cont2+6);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar lado vertical izquierdo
		gotoxy(cont,cont2+i); 
		printf("%c", 124);
		i++;
	}while(i<7);
	i=0;
	do{//dibujar lado vertical derecho
		gotoxy(cont+23,cont2+i); 
		printf("%c", 124);
		i++;
	}while(i<7);
	i=0;
	do{//dibujar linea separadora vertical
		gotoxy(cont+11,cont2+i); 
		printf("%c", 124);
		i++;
	}while(i<2);
}
void dibujarnew(){
	int i=0;//iniciacion de variable i
	int contador=0;//variable para contar las veces que se imprimen las lineas verticales
	do{//dibujar lado horizontal superior
		gotoxy(i,cont2+10);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar linea separadora horizontal
		gotoxy(i,cont2+12);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar linea separadora horizontal
		gotoxy(i,cont2+14);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=0;
	do{//dibujar lado horizontal inferior
		gotoxy(i,cont2+16);
		printf("%c", 45);
		i++;
	}while(i<24);
	i=10;
	do{//dibujar lado vertical izquierdo
		gotoxy(0,cont2+i); 
		printf("%c", 124);
		i++;
		contador++;
	}while(contador<7);
	i=10;
	contador=0;
	do{//dibujar lado vertical derecho
		gotoxy(23,cont2+i); 
		printf("%c", 124);
		i++;
		contador++;
	}while(contador<7);
	i=10;
	contador=0;
	do{//dibujar linea separadora vertical
		gotoxy(11,cont2+i);
		printf("%c", 124);
		i++;
		contador++;
	}while(contador<2);
	gotoxy(5,cont2+11);//impresion de los datos de el nuevo elemento esta parte es igual a la de un elemento cualquiera solo cambian las coordendas
	printf("%d",j->data);
	gotoxy(14,cont2+11);
	printf("%s",j->user);
	if(j->next==NULL){
		gotoxy(9,cont2+13);
		printf("N-NULL");
	}else{
		gotoxy(9,cont2+13);
		printf("N-%d", direccion+10);
	}
	if(j->prev==NULL){
		gotoxy(9,cont2+15);
		printf("P-NULL");
	}else{
		gotoxy(9,cont2+15);
		printf("P-%d", direccion-10);
	}
	gotoxy(9,cont2+17);
	printf("%d", direccion);
	gotoxy(9,cont2+18);//tambien se le agrega otro elemento mas abajo de los demas
	printf("*Nuevo");//para saber que es el nuevo
	//flechas de nuevo elemento
	SetConsoleTextAttribute(hCon, 13);//el color de las flechas next sera rosado
	i=0;
	do{//ciclo para dibujar la flecha next
		gotoxy(25+i,cont2+13);
		if(i<14){
			printf("%c", 45);//cola de la flecha
		}else{
			printf("%c", 62);//punta de la flecha
		}
		i++;
	}while(i<15);
	SetConsoleTextAttribute(hCon, 15);//el color de las flechas next sera rosado
	i=0;
	do{//ciclo para dibujar la flecha next
		gotoxy(25+i,cont2+15);
		if(i<14){
			printf("%c", 45);//cola de la flecha
		}else{
			printf("%c", 62);//punta de la flecha
		}
		i++;
	}while(i<15);
}

void dibujarfn(int x){//funcion para dibujar las flechas next
	SetConsoleTextAttribute(hCon, 13);//el color de las flechas next sera rosado
	int i=0;
	if(x<3){//si x es menor a 4 y nuevo ya esta insertado
		do{//ciclo para dibujar la flecha next
			gotoxy(cont+24+i,cont2+3);
			if(i<15){
				printf("%c", 45);//cola de la flecha
			}else{
				printf("%c", 62);//punta de la flecha
			}
			i++;
		}while(i<16);
	}else{
		if(x==3){//si el elemento es el ultimo antes de que se empiezen a imprimir abajo entonces las flechas son diferentes
			i=0;
			do{//ciclo para dibujar la flecha next parte horizontal
				gotoxy(cont+24+i,cont2+3);
				printf("%c", 45);//cola de la flecha
				i++;
			}while(i<5);
			i=0;
			do{//ciclo para dibujar la flecha next parte vertical
				gotoxy(cont+29,cont2+3+i);
				printf("%c", 124);//cola de la flecha
				i++;
			}while(i<10);
			i=0;
			do{//ciclo para dibujar la flecha next segunda parte horizontal
				gotoxy(cont+29-i,cont2+12);
				printf("%c", 45);//cola de la flecha
				i++;
			}while(i<135);
			i=0;
			do{//ciclo para dibujar la flecha next segunda parte vertical
				gotoxy(cont-105,cont2+12+i);
				if(i<2){
					printf("%c", 124);//cola de la flecha
				}else{
					printf("%c", 25);//punta de la flecha
				}
				i++;
			}while(i<3);
		}
	}
}

void dibujarfp(int x){//funcion para dibujar las flechas prev
	SetConsoleTextAttribute(hCon, 15);//el color de las flechas prev sera blanco
	int i=0;
	if(x<3){//si x es menor a 4 y nuevo ya esta insertado
		i=0;
		do{//ciclo para dibujar la flecha prev
			gotoxy(cont+39-i,cont2+5);
			if(i<15){
				printf("%c", 45);//cola de la flecha
			}else{
				printf("%c", 60);//punta de la flecha
			}
			i++;
		}while(i<16);
	}else{
		if(x==3){//si el elemento es el ultimo antes de que se empiezen a imprimir abajo entonces las flechas son diferentes
			i=0;
			do{//ciclo para dibujar la flecha prev parte horizontal
				gotoxy(cont+24+i,cont2+5);
				if(i<1){
					printf("%c", 60);//punta de la flecha
				}else{
					printf("%c", 45);//cola de la flecha
				}
				i++;
			}while(i<3);
			i=0;
			do{//ciclo para dibujar la flecha prev parte vertical
				gotoxy(cont+27,cont2+5+i);
				printf("%c", 124);//cola de la flecha
				i++;
			}while(i<6);
			i=0;
			do{//ciclo para dibujar la flecha prev segunda parte horizontal
				gotoxy(cont+27-i,cont2+10);
				printf("%c", 45);//cola de la flecha
				i++;
			}while(i<137);
			i=0;
			do{//ciclo para dibujar la flecha prev segunda parte vertical
				gotoxy(cont-109,cont2+10+i);
				printf("%c", 124);//cola de la flecha
				i++;
			}while(i<5);
		}
	}
}


