#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

struct DLLNode{
	int id_item;
	char name[20];
	char desc[50];              
	float price;
	int rated;
	struct DLLNode *next;
	struct DLLNode *prev;
}*DLLhead = NULL;

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

//variables globales para el gotoxy
int x=0;
int y=1;
//variable global para saber cuantos nodos se han insertado
int cont=0;

 //Genera el nodo y lo inserta al final en una lista de doble enlace circular
void DoublyLinkedList(){//creacion de lista
	FILE *arch;//puntero fp de tipo archivo para manejar el uso del archivo arch.txt
	if(!(arch=fopen("arch.txt", "r"))){//se abre el archivo y se checa si hubo un error
		printf("Error al intentar leer archivo");
		exit(1);
	}
	while(!feof(arch)){//se checa que no llegue al fin el archivo
		DLLNode *newNodeDLL = new DLLNode;//se guarda memoria para el nuevo nodo
		cont++;//se incrementa el contador de nodos
		DLLNode *temp = DLLhead;//se crea un nuevo puntero de la estructura que apunta a el primer elemento
		newNodeDLL->id_item=rand()%300+100;//numeros aleatorios del 100 al 400
    	newNodeDLL->rated=rand()%5+1;//numeros aleatorios del 1 al 5
		fscanf(arch, "%[^\t]\t", newNodeDLL->name);//se saca el nombre del archivo
	    fscanf(arch, "%[^\t]\t", newNodeDLL->desc);//se saca la descripcion del archivo
	    fscanf(arch, "%f\n", &newNodeDLL->price);//se saca el precio del archivo
		if(DLLhead==NULL){//si la lista doble esta vacia                                        
			DLLhead=newNodeDLL;
			newNodeDLL->next=DLLhead;
			DLLhead->prev=newNodeDLL;
		}else{//si la lista no esta vacia, se llega al ultimo nodo con ayuda de un temp y se realiza la insercion                                                  
			while(temp->next!=DLLhead){
				temp = temp->next;//recorremos hasta encontrar el ultimo nodo de la lista
			}
			temp->next=newNodeDLL;             						
			newNodeDLL->prev=temp;
			newNodeDLL->next=DLLhead;
		}
	}
	fclose(arch);//se cierra el archivo
}

 //Impresión de la lista nueva generada - generada en doubly linked list
void printDLList(){//funcion para imprimir los datos de los nodos
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//cambia a color azul
	gotoxy(100, 0);//posicion del encabezado
	printf("CATALOGO DE PRODUCTOS");//impresion de encabezado
	DLLNode *t=DLLhead;//se coloca en el primer nodo
	int a=0, b=2;//variables para cambair el comportamiento de elgotoxy
	do{//se recorre toda la lista
		gotoxy(x+a, y);
		printf("%s", t->name);//dato del nodo
		gotoxy(x+a, y+b);
		printf("$%.2f", t->price);//dato del nodo
		a=a+10;//incrementa a
		t=t->next;//se desplaza el puntero a el siguiente nodo
	}while(t->next!=DLLhead->next);//hasta que recorra toda la lista
}
void printDesc(int busnom){//funcion para imprimir la descripcion del nodo en el cual se encuentra la flecha
	system("cls");//se limpia la pantalla para que no se empalmen las descripciones de los nodos
	DLLNode *t=DLLhead;//se coloca en el primer nodo
	int contador=0;//contador que sirve para llegar a la posicion de busnom
	int i=50, j=15, k=0;//variables para cambair el comportamiento de elgotoxy
	while(contador<busnom){//se recorre la lista hasta llegar a el nodo indicado
		t=t->next;//se desplaza el puntero a el siguiente nodo
		contador++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//cambia a color azul
	gotoxy(x+i, y+j+k);//posiciones
	printf("id: %d", t->id_item);//dato del nodo
	k++;//aumenta k
	gotoxy(x+i, y+j+k);//posiciones
	printf("%s", t->name);//dato del nodo
	k++;//aumenta k
	gotoxy(x+i, y+j+k);//posiciones
	printf("%s", t->desc);//dato del nodo
	k++;//aumenta k
	gotoxy(x+i, y+j+k);//posiciones
	printf("%.2f", t->price);//dato del nodo
	k++;//aumenta k
	gotoxy(x+i, y+j+k);//posiciones
	printf("%d estrellas", t->rated);//dato del nodo
}
void encabezado(){//cuerpo de la funcion encabezado
	printf("Covarrubias Solis Victor Alfonso\n177294\nGuerrero Gonzalez Diego Adolfo\n177156\nlaboratorio de Programacion 2\nGrupo A\n16/8/22\n\nUsar pantalla completa para que se imprima el gotoxy correctamente\n\n-------------------------------------------------------------------------------------------------------------------\n\n");//impresion de datos
	getch();//se espera una tecla para avanzar
	system("cls");//se borra la pantalla 
}
int main(){
	srand(time(NULL));//para inicializar semilla
	encabezado();//funcion parallamar encabezado
	HANDLE Con = GetStdHandle(STD_OUTPUT_HANDLE);
	int tecla = 0;//valor de tecla
	int condicion=1;//checa que no te vayas muy atras o adelante y tambien sirve para saber si se llego a el final de la lista
	int post=3;//posisicon que cambia dependiendo de la tecla que estes usando
	int busnom=0;//variable para ver en que nodo esta y con esa informacion poner su descripcion
	DoublyLinkedList();//llamada de funcion
	do{//ciclo do
		printDLList();//llamada de funcion
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//cambia a color verde
		gotoxy(post,4);//coordenadas del indicador de nodo
		printf("%c",30);//impresion de flechita que apunta a el nodo
		fflush(stdin);//no se toma en cuenta la entrada
		tecla = getch();//tecla guarda el valor de la tecla presionadas
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//cambia a negro para que no se vea lo anterior pintado
		gotoxy(post,4);//posicion de la flecha
		printf("%c", 30);//ipresion de la flecha
		switch(tecla){
			case 75://left
				if(condicion>1){//se checa que la posicion sea mayor que 1 para poder retroceder
					post=post-10;//se restan posiciones
					condicion--;//se le resta a condicion
				}
			break;
			case 77://right
				if(condicion<cont){//se checa que sea menor que el numero de nodos para poder avanzar
					post=post+10;//se suman posiciones
					condicion++;//se le suma a condicion
				}
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//cambia a color verde
		gotoxy(post,4);//coordenadas del indicador de nodo
		printf("%c", 30);//impresion de flechita que apunta a el nodo
		busnom=(post-3)/10;//al restarle 3 me dara un multiplo de 10 ya que avanza de 10 en 10 pero empieza en el 3 luego se divide entre tres para saber en que posicion de la lista se encuentra
		printDesc(busnom);//llamada de funcion
	}while(tecla!=27);//mientras tecla no sea 27 se repetira
	return 0;
}
