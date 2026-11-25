#include <stdio.h>
#include <string.h>

int main(){
	char email[30]="";   //5 caracteres @ 5 caracteres . com
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;
	int cont5=0;
	int cont6=0;
	int i;
	bool control=true;
	do{
		cont1=0;
		cont2=0;
		cont3=0;
		cont4=0;
		cont5=0;
		cont6=0;
		printf("Escribe tu correo: ");
		scanf("%s", email);
		
		if(strlen(email)>15){
			continue;
		}else{
			if(email[0]>=97 && email[0]<=122){
				cont1++;
			}else{
				continue;
			}
			for(i=1;i<5;i++){
				if(email[i]>=97 && email[i]<=122){
					cont2++;
				}else{
					if(email[i]==46 || email[i]==95){
						cont2++;
					}else{
						continue;
					}
				}
			}
			if(email[5]==64){
				cont3++;
			}else{
				continue;
			}
			for(i=6;i<11;i++){
				if(email[i]>=97 && email[i]<=122){
					cont4++;
				}else{
					continue;
				}
			}
			if(email[11]==46){
				cont5++;
			}else{
				continue;
			}
			if(email[12]==99){
				cont6++;
			}else{
				continue;
			}
			if(email[13]==111){
				cont6++;
			}else{
				continue;
			}
			if(email[14]==109){
				cont6++;
			}else{
				continue;
			}
		}
		if(cont1==1 && cont2==4 && cont3==1 && cont4==5 && cont5==1 && cont6==3){
			control=false;
		}
	}while(control);
	
	return 0;
}
