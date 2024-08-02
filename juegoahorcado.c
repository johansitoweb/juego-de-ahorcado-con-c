#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  

#define MAX_INTENTOS 6  
#define TAMAÑO_PALABRA 100  

void inicializar_palabra_oculta(char *palabra_oculta, const char *palabra) {  
    int longitud = strlen(palabra);  
    for (int i = 0; i < longitud; i++) {  
        palabra_oculta[i] = '_';  
    }  
    palabra_oculta[longitud] = '\0';  // Terminación de cadena  
}  

void mostrar_estado(const char *palabra_oculta, int intentos) {  
    printf("Palabra: %s\n", palabra_oculta);  
    printf("Intentos restantes: %d\n", MAX_INTENTOS - intentos);  
}  

int letra_adivinada(const char *palabra, char letra) {  
    return strchr(palabra, letra) != NULL;  
}  

void actualizar_palabra_oculta(char *palabra_oculta, const char *palabra, char letra) {  
    for (int i = 0; i < strlen(palabra); i++) {  
        if (palabra[i] == letra) {  
            palabra_oculta[i] = letra;  
        }  
    }  
}  

int juego_ahorcado(const char *palabra) {  
    char palabra_oculta[TAMAÑO_PALABRA];  
    inicializar_palabra_oculta(palabra_oculta, palabra);  
    
    int intentos = 0;  
    char letra;  
    int palabra_adivinada = 0;  

    while (intentos < MAX_INTENTOS && !palabra_adivinada) {  
        mostrar_estado(palabra_oculta, intentos);  
        printf("Introduce una letra: ");  
        scanf(" %c", &letra);  
        letra = tolower(letra); // Convertir a minúscula  

        if (letra_adivinada(palabra, letra)) {  
            actualizar_palabra_oculta(palabra_oculta, palabra, letra);  
            printf("¡Correcto!\n");  
        } else {  
            intentos++;  
            printf("Incorrecto. Intenta de nuevo.\n");  
        }  

        palabra_adivinada = (strcmp(palabra_oculta, palabra) == 0);  
    }  

    if (palabra_adivinada) {  
        printf("¡Felicidades! Has adivinado la palabra: %s\n", palabra);  
    } else {  
        printf("Has perdido. La palabra era: %s\n", palabra);  
    }  

    return 0;  
}  

int main() {  
    const char *palabra = "programacion"; // Puedes cambiar esta palabra  
    juego_ahorcado(palabra);  
    return 0;  
}