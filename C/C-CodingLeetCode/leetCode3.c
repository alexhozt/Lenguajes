//leetcode
// by [alex]
// nivel: Facil


/*

problem: de romano a entero 

Los numeros romanso estan reresentados por siete simbolos diferentes:
I, V, X, L, C, D y M.

Simbolo      Valor 
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Por ejemplo:

2 = II
12 = XII
27 = XXVII
4 = IV

Los numeros ramos generalmente se escriben de mayor a menor de izquierda a derecha.
Si un numero menor precede a un numero mayor, se resta. Por ejemplo:

4 = IV (5 - 1)
13 = XIII (10 + 3)

*/

#include <stdio.h> // libreria estandar de entrada y salida

int RomanToInt(char * s) {
    int total = 0;
    int prev_value = 0;

    while(*s) {

        int valor = 0;
        switch(*s) {
            case 'I': valor = 1; break;
            case 'V': valor = 5; break;
            case 'X': valor = 10; break;
            case 'L': valor = 50; break;
            case 'C': valor = 100; break;
            case 'D': valor = 500; break;
            case 'M': valor = 1000; break;
        }

        if (valor > prev_value) {
            total += valor - 2 * prev_value;
        } else {
            total += valor;
        }
        prev_value = valor;
        s++;
    }

    return total;
}

int main() {
    char *roman = "IV";
    int result = RomanToInt(roman);
    printf("El numero entero de %s es %d\n", roman, result);
    return 0;
}

// recordatorio: switch: instruccion de seleccion multiple 