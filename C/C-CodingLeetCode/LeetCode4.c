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
        char currentChar = strs[0][index]; // toma el caracter en posicion index del primer string como referencia, ejemplo: 'f', 'l', 'o', 'w', 'e', 'r'

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][index] != currentChar || strs[i][index] == '\0') { // si el caracter no coincide o se llega al final de un string
                return index; // si no coinciden, devuelve el indice actual
            }
        }

        index++; // avanza al siguiente caracter, ejemplo: 'f'->'l'->'o'->'w'->'e'->'r'

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

// str[][index] : acceder al caracter en la posicion index de cada cadena, ejemplo: str[0][0] = 'f', str[1][0] = 'f', str[2][0] = 'f'
// str[] : acceder a cada cadena en el array, ejemplo: str[0] = "flower", str[1] = "flow", str[2] = "flight"
// [index] : acceder al caracter en la posicion index de una cadena, ejemplo: str[0][1] = 'l', str[1][1] = 'l', str[2][1] = 'l'
// ejemplo: strs[1][2] = 'o' (de "flow"), strs[2][2] = 'i' (de "flight")
