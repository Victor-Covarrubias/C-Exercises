#include <stdio.h>
#include <string.h>//strlen -> tamaño de cadena

int main(){
	
	bool bandera3 = true;
	char estadoc[8]="";
	int eleccion2;
	
	while(bandera3){
		printf("\nElige tu estado civil \n");
    	printf("1.-Soltero\n");
    	printf("2.-Casado\n");
    	scanf("%d", &eleccion2);
    	 switch(eleccion2){
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
	printf("%s", estadoc);

    return 0;
}
