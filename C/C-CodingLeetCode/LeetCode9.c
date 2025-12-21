// leetcode
// by [alex]
// nivel: Facil


/*

Encontrar el indice de la primera aparicion en una cadena

Problema: Dadas dos cadenas needle y haystack, debes encontrar la primera aparición de needle dentro de haystack y
devolver su índice inicial. Si needle no está en haystack, devuelves -1.


*/


#include <stdio.h>


int strStr(char* haystack, char* needle) {
    if (*needle == '\0') { // *needle es el primer caracter de needle
        return 0;
    }
    
    int h_len = 0; // longitud de haystack
    int n_len = 0; // longitud de needle
    
    // Calcular longitudes primero
    while (haystack[h_len] != '\0') h_len++; 
    while (needle[n_len] != '\0') n_len++;
    
    // Si needle es más largo, no puede estar contenido
    if (n_len > h_len) {
        return -1;
    }
    
    // Solo buscar hasta donde needle puede caber
    for (int i = 0; i <= h_len - n_len; i++) { // ¿por que hasta h_len - n_len? porque si needle es mas largo que el resto de haystack, no puede caber
        int j = 0; // indice para needle
        while (j < n_len && haystack[i + j] == needle[j]) { // haystack[i + j] es el caracter actual de haystack, needle[j] es el caracter actual de needle
            j++;
        }
        if (j == n_len) { 
            return i; // se encontro needle en haystack, devolver el indice inicial
        }
    }
    
    return -1; // no se encontro needle en haystack
}

int main() {
    char haystack[] = "mississippi";
    char needle[] = "issip";
    
    int index = strStr(haystack, needle);
    
    if (index != -1) { 
        printf("La primera aparición de '%s' en '%s' está en el índice: %d\n", needle, haystack, index);
    } else {
        printf("'%s' no se encuentra en '%s'\n", needle, haystack);
    }
    
    return 0;
}




/*

while (haystack[h_len] != '\0') h_len++; 

proceso: 

h_len = 0: haystack[0] = 'm' != '\0' → h_len = 1
h_len = 1: haystack[1] = 'i' != '\0' → h_len = 2
h_len = 2: haystack[2] = 's' != '\0' → h_len = 3
...
h_len = 10: haystack[10] = 'i' != '\0' → h_len = 11
h_len = 11: haystack[11] = '\0' → ¡PARA!

Resultado: h_len = 11

-----------------------------------------------
while (needle[n_len] != '\0') n_len++;

proceso:

n_len = 0: needle[0] = 'i' != '\0' → n_len = 1
n_len = 1: needle[1] = 's' != '\0' → n_len = 2
n_len = 2: needle[2] = 's' != '\0' → n_len = 3
n_len = 3: needle[3] = 'i' != '\0' → n_len = 4
n_len = 4: needle[4] = 'p' != '\0' → n_len = 5
n_len = 5: needle[5] = '\0' → ¡PARA!

Resultado: n_len = 5


el for (int i = 0; i <= h_len - n_len; i++) {
    int j = 0; // indice para needle
    while (j < n_len && haystack[i + j] == needle[j]) { // haystack[i + j] es el caracter actual de haystack, needle[j] es el caracter actual de needle
        j++;
    }
    if (j == n_len) { 
        return i; // se encontro needle en haystack, devolver el indice inicial
    }
}

proceso:
i = 0: haystack[0 + 0] = 'm' != needle[0] = 'i' → no entra al while
i = 1: haystack[1 + 0] = 'i' == needle
[0] = 'i' → j = 1
        haystack[1 + 1] = 's' == needle[1] = 's' → j = 2
        haystack[1 + 2] = 's' == needle[2] = 's' → j = 3
        haystack[1 + 3] = 'i' == needle[3] = 'i' → j = 4
        haystack[1 + 4] = 's' != needle[4] = 'p' → sale del while
    i = 2: haystack[2 + 0] = 's' != needle[0] = 'i' → no entra al while
    i = 3: haystack[3 + 0] = 's' != needle[0] = 'i' → no entra al while
    i = 4: haystack[4 + 0] = 'i' == needle[0] = 'i' → j = 1
        haystack[4 + 1] = 's' == needle[1] = 's' → j = 2
        haystack[4 + 2] = 's' == needle[2] = 's' → j = 3
        haystack[4 + 3] = 'i' == needle[3] = 'i' → j = 4
        haystack[4 + 4] = 'p' == needle[4] = 'p' → j = 5
    Ahora j == n_len (5), se encontró needle en haystack en el índice i = 4, devuelve 4.

*/