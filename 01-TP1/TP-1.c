#include <stdio.h>

// a) Calcular y retornar la longitud de una cadena dada.
int calcularLongitud(const char *cadena) {
    int longitud = 0;
    while (*cadena != '\0') {
        longitud++;
        cadena++;
    }
    return longitud;
}

// b) Convertir una cadena de dígitos en su equivalente numérico.
int convertirANumero(const char *cadena) {
    int numero = 0;
    while (*cadena != '\0') {
        numero = numero * 10 + (*cadena - '0');
        cadena++;
    }
    return numero;
}

// c) Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula.
void convertirAMayusculas(char *cadena) {
    while (*cadena != '\0') {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - 32;
        }
        cadena++;
    }
}

// d) Eliminar de una cadena dada todas las ocurrencias de un carácter dado.
void eliminarCaracter(char *cadena, char caracter) {
    char *destino = cadena;
    while (*cadena != '\0') {
        if (*cadena != caracter) {
            *destino = *cadena;
            destino++;
        }
        cadena++;
    }
    *destino = '\0';
}

// e) Concatenar al final de la primera cadena dada una segunda cadena también dada.
void concatenarCadenas(char *cadena1, const char *cadena2) {
    while (*cadena1 != '\0') {
        cadena1++;
    }
    while (*cadena2 != '\0') {
        *cadena1 = *cadena2;
        cadena1++;
        cadena2++;
    }
    *cadena1 = '\0';
}

// f) Modificar la cadena dada con la inserción de un carácter dado en una posición determinada.
void insertarCaracter(char *cadena, char caracter, int posicion) {
    int longitud = calcularLongitud(cadena);
    if (posicion >= 0 && posicion <= longitud) {
        for (int i = longitud; i >= posicion; i--) {
            cadena[i + 1] = cadena[i];
        }
        cadena[posicion] = caracter;
    }
}

int main() {
    char cadena1[100] = "Hola";
    char cadena2[] = "Mundo";
    char cadena3[] = "12345";
    char cadena4[] = "AbcdefAbcdef";
    char cadena5[100] = "Texto";

    printf("Longitud de la cadena '%s': %d\n", cadena1, calcularLongitud(cadena1));
    printf("Número equivalente de la cadena '%s': %d\n", cadena3, convertirANumero(cadena3));

    convertirAMayusculas(cadena1);
    printf("Cadena en mayúsculas: %s\n", cadena1);

    eliminarCaracter(cadena4, 'b');
    printf("Cadena sin ocurrencias de 'b': %s\n", cadena4);

    concatenarCadenas(cadena1, cadena2);
    printf("Concatenación de cadenas: %s\n", cadena1);

    insertarCaracter(cadena5, '!', 5);
    printf("Cadena con carácter insertado: %s\n", cadena5);

    return 0;
}
