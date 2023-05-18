#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxima_longitud 100
#define maxima_cantidad 100
int palabra_1(char palabras[maxima_cantidad][maxima_longitud],char*archivos);
int palabras_archivo(char*nombre_archivo,char*arreglo);

int main() {
    char nombre_archivo[] = "animales.txt";
    char arreglo[maxima_longitud * maxima_cantidad] = {0};
    int numero_palabras = palabras_archivo(nombre_archivo, arreglo);
    printf("se leyeron %d palabras del archivo:\n%s\n", numero_palabras, arreglo);
    return 0;
}

int palabra(char palabras[maxima_cantidad][maxima_longitud], char* archivos) {
    FILE* fp = fopen(archivos, "r");
    int count = 0;
    if (fp == NULL){
        printf("No se pudo abrir el archivo %s\n",archivos);
        exit(1);
    }
    while (fscanf(fp, "%s",palabras[count]) == 1) {
        count++;
        if (count == maxima_cantidad) {
            printf("el archivo %s contiene demasiadas palabras.\n",archivos);
            exit(1);
        }
    }
    fclose(fp);
    return count;
}

int palabras_archivo(char *nombre_archivo, char *arreglo) {
    char palabras[maxima_cantidad][maxima_longitud];
    int numero_palabras =palabra(palabras, nombre_archivo);
    int longitud_arreglo = 0;
    
    for (int i = 0; i < numero_palabras; i++) {
        int longitud_palabra = strlen(palabras[i]);
        if (longitud_arreglo+longitud_palabra+1>maxima_longitud * maxima_cantidad) {
            printf("El arreglo es demasiado pequeño para almacenar todas las palabras del archivo.\n");
            exit(1);
        }
        strcpy(arreglo + longitud_arreglo,palabras[i]);
        longitud_arreglo += longitud_palabra + 1;
        arreglo[longitud_arreglo-1] = ' ';
    }
    arreglo[longitud_arreglo-1] ='\0';
    return numero_palabras;
}
