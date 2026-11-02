#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
	int numa;
	int elec;
	do{
		srand(time(NULL));
		printf("sacar numero aleatorio? 1--> Si, 2--> No\n");
		scanf("%d", &elec);
	}while(elec==2);

	if(elec==1){
		numa=1000+rand()%(2500-1000)+1;
		printf("%d", numa);
	}
	srand(time(NULL));
	printf("\nsacar numero aleatorio? 1--> Si, 2--> No");
	scanf("%d", &elec);
	return 0;
}
