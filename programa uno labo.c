//librerias
#include <stdio.h>
#include <conio.h>

main(/*parametros*/) //función de inicio
{
/*variables...
entero int: números enteros -32000 al 32000 (%d, %i)
flotante float: números decimales (%f)
caracter char: letras, números, simbolos .. (%c)
NO nombrar variables con ñ
NO debe contener simbolos ni acentos
No debe contener espacios
NO puede comenzar con números
No puede contener guion medio
*/
//declaración de variables
int can_gpos = 0,alumnos = 0;
float promedio = 0;
char letra;
//Entrada de datos
printf("Programacion 1 \n\n"); //función para imprimir en pantalla
printf("Cantidad de grupos: ");
scanf("%d",&can_gpos);
printf("Promedio: ");
scanf("%f",&promedio);
fflush(stdin);//limpiar la entrada del teclado
printf("Ingresa una letra: ");
scanf("%c",&letra);
printf("Cantidad de alumnos: ");
scanf("%d",&alumnos);
getch();//espera una tecla para terminar, es opcional
//Salida de datos
//printf nunca lleva &
printf("\nSALIDA DE DATOS...");
printf("\n\tGrupos: %d \n\tPromedio: %.2f \n\tLetra: %c \n\tALumnos: %d",can_gpos,promedio,letra,alumnos);
getch();
}

