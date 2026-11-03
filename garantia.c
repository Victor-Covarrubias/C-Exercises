char garant[50];
int contn=0;//para contar caracteres
int contl=0;//para contar letras

if(garant[0]>'0' && garant[0]<='9'){//se checa que el primer caracter sea un numero del 1 al 9
	contn++;//aumenta el contador de caracteres
}
if(garant[1]==' '){//se checa que el segundo caracter sea un espacio
	contn++;//aumenta el contador de caracteres
}
if(contn==2){//se comprueba que el primer digito sea un numero y el segundo un espacio
	if(garant[2]=='d'){//si es dia
		if(garant[3]=='i'){
			contl++;//aumenta el contador de letras
		}
		if(garant[4]=='a'){
			contl++;//aumenta el contador de letras
		}
		if(contl!=2){//se checa que el nuemro de letras sea el correcto 
			bandera=false;//bandera se hace falsa
		}else{
			if(garant[0]!='1'){//se checa si solo es un dia
				if(garant[5]!='s'){//si es mas de un dia entonces es dias y no dia
					bandera=false;//bandera se hace falsa
				}
			}
		}
	}else{
		if(garant[2]=='s'){//si es semana
			if(garant[3]=='e'){
				contl++;//aumenta el contador de letras
			}
			if(garant[4]=='m'){
				contl++;//aumenta el contador de letras
			}
			if(garant[5]=='a'){
				contl++;//aumenta el contador de letras
			}
			if(garant[6]=='n'){
				contl++;//aumenta el contador de letras
			}
			if(garant[7]=='a'){
				contl++;//aumenta el contador de letras
			}
			if(contl!=5){//se checa que el nuemro de letras sea el correcto 
				bandera=false;
			}else{
				if(garant[0]!='1'){//se checa si solo es una semana
					if(garant[8]!='s'){//si es mas de una semana entonces es semanas y no semana
						bandera=false;//bandera se hace falsa
					}
				}
			}
		}else{
			if(garant[2]=='m'){//si es mes
				if(garant[3]=='e'){
					contl++;//aumenta el contador de letras
				}
				if(garant[4]=='s'){
					contl++;//aumenta el contador de letras
				}
				if(contl!=2){//se checa que el nuemro de letras sea el correcto 
					bandera=false;
				}else{
					if(garant[0]!='1'){//se checa si solo es un mes
						if(garant[5]!='e'){//si es mas de un mes entonces es meses y no mes
							bandera=false;//bandera se hace falsa
						}
						if(garant[6]!='s'){//si es mas de un mes entonces es meses y no mes
							bandera=false;//bandera se hace falsa
						}
					}
				}
			}else{
				if(garant[2]=='a'){//si es año
					if(garant[3]=='ñ'){
						contl++;//aumenta el contador de letras
					}
					if(garant[4]=='o'){
						contl++;//aumenta el contador de letras
					}
					if(contl!=2){//se checa que el nuemro de letras sea el correcto
						bandera=false;
					}else{
						if(garant[0]!='1'){//se checa si un año
							if(garant[5]!='s'){//si es mas de un año entonces es años y no año
								bandera=false;//bandera se hace falsa
							}
						}
					}
				}
			}
		}
	}
}else{
	break;//si los dos primeros caracteres estan mal se termina el ciclo
}
if(bandera==false){
	printf("tienes un elemento de la garantia mal");
}

