//leetcode
// by [alex]
// nivel: Facil


/*

problema: prefijo comun mas largo

escribir una funcion que encuentre el prefijo comun mas largo entre un array de cadenas.
si no existe un prefijo comun, devolver una cadena vacia.


*/

#include <stdio.h> // libreria estandar de entrada y salida

int longestCommonPrefix(char ** strs, int strsSize) {

    if (strsSize == 0) return 0;

    int index = 0;

    while(1) {
        char currentChar = strs[0][index];

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][index] != currentChar || strs[i][index] == '\0') { // si el caracter no coincide o se llega al final de un string
                return index; // si no coinciden, devuelve el indice actual
            }
        }

        index++; // avanzar al siguiente caracter

    }

}

int main() {
    char *strs[] = {"flower", "flow", "flight"}; // array de cadenas de prueba
    int strsSize = sizeof(strs) / sizeof(strs[0]); // tamaño del array

    int prefixLength = longestCommonPrefix(strs, strsSize); // obtener la longitud del prefijo comun mas largo

    printf("Longitud del prefijo comun mas largo: %d\n", prefixLength); // imprimir la longitud del prefijo comun mas largo

    return 0;
}

// char ** strs: array de cadenas
// strsSize: tamaño del array de cadenas

