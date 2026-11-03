#include <stdio.h>
#include <windows.h>
#include <string.h>
main(){
	//arreglo para 5 cadenas, 3 cadenas estaran predefinidas, las ultimas dos seran solicitadas
	printf("Victor Alfonso Covarrubias Solis, 177294\n");
	char cadenas[5][15]={"hola", "como estas", "adios"};
	int opcion;
	int cont=0;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int i=3;i<5;i++){
		printf("Cadena:");
			scanf("%s", cadenas[i]);
	}
	for(int i=0;i<5;i++){
		printf("cadena: %s\n", cadenas[i]);
	}
	printf("\n");
	for(int i=0;i<5;i++){
		for(int j=0;j<15;j++){
			if(cadenas[i][j]=='a' || cadenas[i][j]=='e'|| cadenas[i][j]=='i' || cadenas[i][j]=='o' || cadenas[i][j]=='u' || cadenas[i][j]=='A' || cadenas[i][j]=='E'|| cadenas[i][j]=='I' || cadenas[i][j]=='O' || cadenas[i][j]=='U'){
				cadenas[i][j]='$';
			}
		}
	}
	for(int i=0;i<5;i++){
		if(i%2==0){
			SetConsoleTextAttribute(hConsole, i);
			printf("cadena: %s\n", cadenas[i]);
		}else{
			SetConsoleTextAttribute(hConsole, 7);
			printf("cadena: %s\n", cadenas[i]);
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
	printf("Que palabra quieres modificar?\n");
	
	for(int i=0;i<5;i++){
		printf("cadena numero %d: %s\n", i, cadenas[i]);
	}
	scanf("%d", &opcion);
	printf("Escribe la nueva palabra\n");
	scanf("%s", cadenas[opcion]);
	for(int i=0;i<5;i++){
		printf("cadena: %s\n", cadenas[i]);
	}
	printf("\n");
	printf("Arreglo\tCaracteres\n");
	for(int i=0;i<5;i++){
		printf("%s\t%d\n", cadenas[i], strlen(cadenas[i]));
	}
	printf("\n");
	printf("Arreglo\tConsonantes\n");
	for(int i=0;i<5;i++){
		cont=0;
		for(int j=0;j<strlen(cadenas[i]);j++){
			if(cadenas[i][j]!='$' && cadenas[i][j]!=' '){
				cont++;
			}
		}
		printf("%s\t%d\n", cadenas[i], cont);
	}
	return 0;
}
