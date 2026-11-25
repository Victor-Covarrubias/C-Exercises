#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	char curp[19]="";
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int i;
	bool control=true;
	
	
	do{
		printf("Escribe la curp para validarla:");
		scanf("%s", curp);
		cont1=0;
		cont2=0;
		cont3=0;
		cont4=0;
		if(strlen(curp)>18){
			printf("La curp es muy larga\n");
			continue;
		}else{
			for(i=0; i<4; i++){
				if(isalpha(curp[i])){
					cont1++;
				}else{
					printf("Los primeros 4 caracteres deben ser letras\n");
					continue;
				}
			}
			for(i=4; i<10; i++){
				if(isdigit(curp[i])){
					cont2++;
				}else{
					printf("La segunda seccion de la curp empieza en el caracter 5 y debe contener 6 digitos\n");
					continue;
				}
			}
			for(i=10; i<16; i++){
				if(isalpha(curp[i])){
					cont3++;
				}else{
					printf("La tercera seccion de la curp empieza en el caracter 11 y debe contener 6 letras\n");
					continue;
				}
			}
			if(isdigit(curp[16]) || isalpha(curp[16])){
				cont4++;
			}else{
				continue;
			}
			if(isdigit(curp[17])){
				cont4++;
			}else{
				continue;
			}
		}
		if(cont1==4 && cont2==6 && cont3==6 && cont4==2){
			control=false;
		}
	}while(control);
	printf("\ncurp valida :)\n");
	printf("\n%s", curp);
	return 0;
}
