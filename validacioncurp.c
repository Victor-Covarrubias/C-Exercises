#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

int main(){
	char curp[19]="";
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int i;
	bool control=true;
	
	
	do{
		printf("Dame tu curp:");
		fflush(stdin);
		scanf("%s", curp);
		cont1=0;
		cont2=0;
		cont3=0;
		cont4=0;
		if(strlen(curp)>18){
			continue;
		}else{
			for(i=0; i<4; i++){
				if(isalpha(curp[i])){
					cont1++;
				}else{
					continue;
				}
			}
			for(i=4; i<10; i++){
				if(isdigit(curp[i])){
					cont2++;
				}else{
					continue;
				}
			}
			for(i=10; i<16; i++){
				if(isalpha(curp[i])){
					cont3++;
				}else{
					continue;
				}
			}
			for(i=16; i<18; i++){
				if(isdigit(curp[i])){
					cont4++;
				}else{
					continue;
				}
			}
		}
		if(cont1==4 && cont2==6 && cont3==6 && cont4==2){
			control=false;
		}
	}while(control);
	printf("\n%d", cont1);
	printf("\n%d", cont2);
	printf("\n%d", cont3);
	printf("\n%d", cont4);
	printf("\n%s", curp);
	return 0;
}
