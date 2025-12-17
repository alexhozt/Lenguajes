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
        int j = 0;
        while (j < n_len && haystack[i + j] == needle[j]) { // haystack[i + j] es el caracter actual de haystack, needle[j] es el caracter actual de needle
            j++;
        }
        if (j == n_len) { 
            return i; // se encontro needle en haystack, devolver el indice inicial
        }
    }
    
    return -1;
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


*/