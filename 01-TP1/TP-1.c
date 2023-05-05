#include <stdio.h>

int longitudCadena(char *cadena) {
    int i = 0;
    while (*cadena != '\0') {  // mientras no se llegue al final de la cadena ('\0')
        i++;                  // incrementar variable de longitud
        cadena++;             // avanzar al siguiente carácter de la cadena
    }
    return i;
}

void convCadenaANumerico(char* cadena){
    int i, num;
    while (cadena[i] != '\0') {
            num *= 10; // multiplicamos por 10 para mover el dígito anterior un lugar a la izquierda
            num += cadena[i] - '0'; // sumamos el valor numérico del carácter actual al número entero
            i++;
    }
}

void convCadenaAMayuscula(char* str) {
    int i = 0;

    while(str[i] != '\0') { // Iterar sobre cada caracter de la cadena
        if(str[i] >= 'a' && str[i] <= 'z') { // Si el caracter es una letra minúscula
            str[i] = str[i] - 'a' + 'A'; // Convertir a mayúscula
        }
        i++; // Incrementar el índice
    }
}

void eliminar_caracter(char* cadena, char caracter_a_eliminar) {
    int i, j;

    // Recorremos la cadena de caracteres
    for (i = 0; cadena[i] != '\0'; i++) {
        // Si encontramos el carácter a eliminar, reorganizamos la cadena
        if (cadena[i] == caracter_a_eliminar) {
            // Recorremos el resto de la cadena hacia la izquierda
            for (j = i; cadena[j] != '\0'; j++) {
                cadena[j] = cadena[j + 1];
            }
            // Al eliminar un carácter, mantenemos la posición del índice en el mismo lugar, para no saltarnos caracteres
            i--;
        }
    }
}

void concatenar(char* cadena1, char* cadena2) {
    // Encontrar la longitud de la primera cadena
    int longitud = longitudCadena(cadena1);

    // Concatenar la segunda cadena al final de la primera cadena
    int i = longitud;
    int j = 0;
    
    // Encontrar la longitud de cadena1
    for (i = 0; cadena1[i] != '\0'; i++);
    
    // Concatenar cadena2 al final de cadena1
    for (j = 0; cadena2[j] != '\0'; j++) {
        cadena1[i] = cadena2[j];
        i++;
    }
    
    cadena1[i] = '\0'; // Agregar el caracter nulo al final de la cadena1
}

void modificaCaracter(char* cadena, int posicion, char caracter){
    // Encontrar la longitud de la primera cadena
    int longitud_cadena = longitudCadena(cadena);

    for (int i = longitud_cadena; i >= posicion; i--) {
    cadena[i+1] = cadena[i];
    }
    cadena[posicion] = caracter;
}


int main()
{
/*
    1) Realizar en Lenguaje C una función para realizar cada una de las operaciones solicitadas, sin la utilización de funciones de biblioteca:  
*/
    //a) Calcular y retornar la longitud de una cadena dada.
    char cadena[] = "hola mundo";
    int longitud = longitudCadena(cadena);
    printf("La longitud de la cadena '%s' es %d\n", cadena, longitud); // imprimir la longitud de la cadena
    printf("\n");

    //b) Convertir una cadena de dígitos en su equivalente numérico. 
    char str[] = "hola"; // cadena de caracteres a convertir
    int numero;

    printf("Cadena original: %s\n", str);

    convCadenaANumerico(str);

    printf("El número resultante es: %d\n", numero);
    printf("\n");

    //c) Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula. 
    char string[] = "hola mundo";

    printf("Cadena original: %s\n", string);

    convCadenaAMayuscula(string); // Convertir la cadena a mayúsculas

    printf("La cadena en mayusculas es: %s\n", string); // Imprimir la cadena convertida
    printf("\n");

    //d) Eliminar de una cadena dada todas las ocurrencias de un carácter dado. 
    char caracter_a_eliminar = 'o';

    printf("Cadena original: %s\n", cadena);

    eliminar_caracter(cadena, caracter_a_eliminar);

    printf("Cadena sin el caracter '%c': %s\n", caracter_a_eliminar, cadena);
    printf("\n");

    //e)Concatenar al final de la primera cadena dada una segunda cadena también dada.
    // Definir dos cadenas de caracteres
    char cadena1[20] = "Hola ";
    char cadena2[20] = "mundo!";

    printf("Primera Cadena: %s \nSegunda Cadena: %s\n", cadena1, cadena2);
    concatenar(cadena1, cadena2);
    
    printf("Cadena concatenada: %s", cadena1);
    printf("\n\n");

    //f)Modificar la cadena dada con la inserción de un carácter dado en una posición determinada. 
    // Primero, pedimos introduzca la cadena de caracteres
    printf("Ingrese una cadena de caracteres: ");
    char cadena3[100];
    scanf("%s", cadena3);

    // Luego, solicitamos que elija la posición donde desea insertar el caracter
    printf("Ingrese la posicion donde desea insertar el caracter: ");
    int posicion;
    scanf("%d", &posicion);

    // Después, preguntamos al usuario qué caracter desea insertar
    printf("Ingrese el caracter que desea insertar: ");
    char caracter;
    scanf(" %c", &caracter);

    modificaCaracter(cadena3, posicion, caracter);

    // Finalmente, imprimimos la cadena modificada
    printf("La cadena modificada es: %s", cadena3);

    

    return 0;
}