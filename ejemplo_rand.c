#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
	int numa;
	int elec;
	srand(time(NULL));
	do{
		printf("\nsacar numero aleatorio? 1--> Si, 2--> No\n");
		scanf("%d", &elec);
		if(elec == 1){
			numa = 1000 + rand()%(2500 - 1000 +1);
			printf("%d", numa);
		}
	}while(elec != 2);
	return 0;
}
