#include <stdio.h>
void despliega_juego(char* nombre_archivo_figura);
int main(){
despliega_juego("figura_5.txt");
  return 0;
}
void despliega_juego(char* nombre_archivo_figura) {
    FILE* arch = fopen(nombre_archivo_figura, "r");
    if (arch == NULL) {
        printf("no es posible abrir el archivo %s\n", nombre_archivo_figura);
        return;}
    char linea[100];
    while (fgets(linea, sizeof(linea), arch)) {
        printf("%s", linea);}
    fclose(arch);
}
