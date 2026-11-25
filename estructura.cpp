#include <stdio.h>
#include <string.h>

struct nadador{
	char nombre[20], categoria[20];
	int edad;
};

int main(){
	struct nadador ndr[3];
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	for(int i=0;i<3;i++){
		printf("Nombre del nadador %d: ", i + 1);
		//fflush(stdin); 
		fgets(ndr[i].nombre, sizeof(ndr[i].nombre), stdin);
		ndr[i].nombre[strcspn(ndr[i].nombre, "\n")] = '\0';
		printf("\nEdad del nadador %d: ", i + 1);
		scanf("%d", &ndr[i].edad);

		//limpiar el salto de linea para que no lo tome como el siguiente nombre
		int c;
		//se checa que sea fin de linea con el salto de linea o con EOF que es una constante de stdio.h
		while((c = getchar()) != '\n' && c !=EOF);
		if(ndr[i].edad<=18){
			strcpy(ndr[i].categoria,"Juvenil");
		}else{
			strcpy(ndr[i].categoria,"Veterano");
		}
	}
	printf("Nombre\tEdad\tCategoria\n");
	for(int i=0;i<3;i++){
		printf("%s\t", ndr[i].nombre);
		printf("%d\t", ndr[i].edad);
		printf("%s\n", ndr[i].categoria);
	}
	return 0;
}
