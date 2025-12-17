// by alex
// ingenieria civil en informatica
// conversor de direccion IP de binario a decimal


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //

int validar_ip_binaria(const char *ip_bin) {
    // Validar longitud exacta
    if (strlen(ip_bin) != 32) { // cuenta los caracteres hasta el \0, si no son 32 devuelve 0
        return 0;
    }
    
    // Validar que todos los caracteres sean '0' o '1'
    for (int i = 0; i < 32; i++) {
        if (ip_bin[i] != '0' && ip_bin[i] != '1') {
            return 0;
        }
    }
    
    return 1;
}

void conv_to_decimal(const char *ip_bin, char *ip_dec) {
    // Usar const para indicar que no modificamos ip_bin
    char octeto_str[9];
    
    ip_dec[0] = '\0';
    
    for (int i = 0; i < 4; i++) {
        // Extraer octeto
        strncpy(octeto_str, ip_bin + i * 8, 8);
        octeto_str[8] = '\0';
        
        // Convertir binario a decimal
        int decimal = 0;
        for (int j = 0; j < 8; j++) {
            decimal = (decimal << 1) | (octeto_str[j] - '0');
            // alternativa: decimal = decimal * 2 + (octeto_str[j] - '0');
        }
        
        // Agregar a la cadena resultado
        char temp[5]; // Máximo 3 dígitos + '\0' (255)
        sprintf(temp, "%d", decimal);
        
        if (i > 0) {
            strcat(ip_dec, ".");
        }
        strcat(ip_dec, temp);
    }
}

int main() {
    // se declaran dos arrays de caracteres, uno para la IP en binario y otro para la IP en decimal
    char ip_bin[33] = {0};  // 32 bits + '\0'
    char ip_dec[16];        // Formato decimal maximo "
    
    printf("Ingrese la direccion IP en formato binario (32 bits): ");
    
    // Leer con validación de longitud
    if (scanf("%32s", ip_bin) != 1) { // si no se lee correctamente la entrada 
        printf("Error al leer la entrada.\n");
        return 1;
    }
    
    // Limpiar buffer de entrada
    // el proposito es si el usuario ingresa mas de 32 caracteres, se descartan los sobrantes
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // Validar entrada
    if (!validar_ip_binaria(ip_bin)) {
        printf("Error: La entrada debe contener exactamente 32 bits (solo 0 y 1).\n");
        printf("Ejemplo valido: 11000000101010001100000010101001\n");
        return 1;
    }
    
    // Convertir
    conv_to_decimal(ip_bin, ip_dec);
    
    printf("La direccion IP en formato decimal es: %s\n", ip_dec);
    
    // Ejemplo de prueba
    printf("\nEjemplo de prueba:\n");
    printf("Binario: 11000000101010001100000010101001\n");
    conv_to_decimal("11000000101010001100000010101001", ip_dec);
    printf("Decimal esperado: 192.168.0.169\n");
    printf("Decimal obtenido: %s\n", ip_dec);
    
    return 0;
}


/*

USUARIO INGRESA: "11000000101010001100000010101001"

1. main() lee: ip_bin = "11000000101010001100000010101001\0"
2. Valida: ¿32 caracteres? ✓ ¿Solo 0/1? ✓
3. conv_to_decimal():
   Octeto 1: "11000000" → 192
   Octeto 2: "10101000" → 168
   Octeto 3: "11000000" → 0
   Octeto 4: "10101001" → 169
4. ip_dec = "192.168.0.169"
5. Muestra resultado

*/
