#include <stdio.h>

int main(){
	int ar2[4][3];
	
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			ar2[i][j]=i*5;
			printf("%d", ar2[i][j]);
		}
		printf("\n");
	}
	return 0;
}
