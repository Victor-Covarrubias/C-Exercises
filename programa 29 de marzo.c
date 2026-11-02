#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

int main(){
	int var1, var2, var3, var4, var5, var6, ar[8]={0}, ar1[9], ar2[4][3];
	char nom[30];
	
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			ar2[i][j]=i*5;
			printf("%d", ar2[i][j]);
		}
		printf("\n");
	}
	return 0;
}
