// leetcode
// by [alex]
// nivel: Facil

/*

Longitud de la ultima palabra

Dada una cadena compuesta por palabras y espacios,
se devuelve la longitud de la ultima palabra de la cadena.

Una palabra es un maximal subcadena compuesta solo por caracteres no 
espaciales.


*/

#include <stdio.h>

int lengthOfLastWord(char *s) {
    int Lenght = 0;
    int i = 0;

    // Moverse al final de la cadena
    while (s[i] != '\0') {
        i++;
    }

    // Retroceder para saltar espacios al final
    i--; // ahora estamos en el ultimo caracter valido

    // Saltar espacios al final de la cadena
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Contar la longitud de la ultima palabra.
    while (i >= 0 && s[i] != ' ') {
        Lenght++;
        i--;
    }

    return Lenght;

}


int main() {

    char str[] = "Hello World  ";
    int length = lengthOfLastWord(str);
    printf("La longitud de la última palabra es: %d\n", length);
    return 0;
}