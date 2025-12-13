// leetcode
// by alex
// nivel: facil 

// descripcion del problema:

/*

Problem: dos sumas

dada una matriz de numeros enteros y un numero entero, devuelve los indices de dos 
numeros que suman el numero entero dado.
puede suponer que cada entrada tiene una solucion, y no puedes usar 
el mismo elemento dos veces.

*/


#include <stdio.h> // libreria estandar de entrada y salida

int main() {
    int nums[] = {2, 7, 11, 15}; // matriz de numeros enteros
    int target = 9; // numero entero objetivo
    int size = sizeof(nums) / sizeof(nums[0]); // tamaño de la matriz

    for (int i = 0; i < size; i++) { // bucle a traves de la matriz
        for (int j = i + 1; j < size; j++) { // bucle anidado para encontrar el segundo numero
            if (nums[i] + nums[j] == target) { // comprobar si la suma es igual al objetivo
                printf("Indices: [%d, %d]\n", i, j); // imprimir los indices encontrados
                return 0; // salir del programa
            }
        }
    }

    return 0; // salir del programa si no se encuentran indices
}
// sizeof: operador que devuelve el tamaño en bytes de una variable o tipo de datos
// printf: funcion para imprimir en la consola
// return: instruccion para salir de una funcion y devolver un valor