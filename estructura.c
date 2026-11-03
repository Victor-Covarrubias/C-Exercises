#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
struct nadador{
	char nombre[20], categoria[20];
	int edad;
};

main(){
	struct nadador ndr;
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	
	printf("Nombre: ");
	gets(ndr.nombre);
	printf("\nedad: ");
	scanf("%d", &ndr.edad);
	if(ndr.edad<=18){
		strcpy(ndr.categoria,"Juvenil");
	}else{
		strcpy(ndr.categoria,"Veterano");
	}
	
	printf("\nNombre= %s", ndr.nombre);
	printf("\nEdad= %d", ndr.edad);
	printf("\nCategoria= %s", ndr.categoria);
	return 0;
}
*/
struct nadador{
	char nombre[20], categoria[20];
	int edad;
};

main(){
	struct nadador ndr[3];
	printf("Victor Alfonso Covarrubias Solis, 177294\n\n");
	for(int i=0;i<3;i++){
		printf("Nombre: ");
		fflush(stdin);
		gets(ndr[i].nombre);
		printf("\nedad: ");
		scanf("%d", &ndr[i].edad);
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
