#include <stdio.h>

int main(void){
	int a=0, b=0, c=0, d=0, e=0, f=0;
	for(int i=999;i>0;i--){
		if(i%7==0)a++;
		if(i%7==0 && (i%11!=0))b++;
		if(i%7==0 && i%11==0)c++;
		if(i%7==0 || i%11==0)d++;
		if(i%7==0 ^ i%11==0)e++;
		if(i%7!=0 && i%11!=0)f++;
	}
	printf("a: %d", a);
	printf("\nb: %d", b);
	printf("\nc: %d", c);
	printf("\nd: %d", d);
	printf("\ne: %d", e);
	printf("\nf: %d", f);
	
	
	return 0;
}

