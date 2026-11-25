//librerias
#include <stdio.h>
#include <conio.h>

int main(/*parametros*/) //funcion de inicio
{
    /*variables...
    entero int: numeros enteros -32000 al 32000 (%d, %i)
    flotante float: numeros decimales (%f)
    caracter char: letras, numeros, simbolos .. (%c)
    NO nombrar variables con acentos
    NO debe contener simbolos ni acentos
    No debe contener espacios
    NO puede comenzar con numeros
    No puede contener guion medio
    */

    //declaracion de variables
    int can_gpos = 0,alumnos = 0;
    float promedio = 0;
    char letra;

    //Entrada de datos
    printf("Programacion 1 \n\n"); //funcion para imprimir en pantalla
    printf("Cantidad de grupos: ");
    scanf("%d",&can_gpos);
    printf("Promedio: ");
    scanf("%f",&promedio);
    printf("Ingresa una letra: ");
    scanf(" %c",&letra);
    printf("Cantidad de alumnos: ");
    scanf("%d",&alumnos);
    printf("Presiona enter para mostrar");
    getch();//espera una tecla para terminar, es opcional
    
    //Salida de datos
    //printf nunca lleva &
    printf("\nSALIDA DE DATOS...");
    printf("\n\tGrupos: %d \n\tPromedio: %.2f \n\tLetra: %c \n\tALumnos: %d",can_gpos,promedio,letra,alumnos);
    getch();

    return 0;
}

