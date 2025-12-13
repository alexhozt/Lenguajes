// leetcode
// by alex
// nivel: facil 

// descripcion del problema:

/*

problem: numero de palindromo

Dado un numero entero, devuelve si la variable es un palindromo o no,
que devuelva true o de lo contrario false.

*/

#include <stdio.h>

int isPalindrome(int x) {
    if (x < 0) {
        return 0; // los numeros negativos no son palindromos
    }
    int original = x;
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10; // obtener el ultimo digito
        reversed = reversed * 10 + digit; // construir el numero invertido
        x /= 10; // eliminar el ultimo digito
    }

    return original == reversed; // comprobar si el numero original es igual al invertido
}

int main() {
    int number = 121; // numero de prueba
    if (isPalindrome(number)) {
        printf("%d es un palindromo.\n", number);
    } else {
        printf("%d no es un palindromo.\n", number);
    }
    return 0;
}

// reversed = reversed * 10 + digit, lo que hace es construir el numero invertido:
// ejemplo: si el numero es 123, el proceso seria:
// iteracion 1: digit = 3, reversed = 0 * 10 + 3 = 3
// iteracion 2: digit = 2, reversed = 3 * 10 + 2 = 32
// iteracion 3: digit = 1, reversed = 32 * 10 + 1 = 321
// al final, reversed sera 321, que es el numero invertido de 123.