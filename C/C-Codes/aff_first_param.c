#include <unistd.h>  // Biblioteca estándar de servicios del sistema operativo POSIX
                     // Proporciona la función write() para escribir en la salida estándar

// Función que calcula la longitud de una cadena de caracteres
int ft_strlen(char* s) {
    int i;  // Contador para recorrer la cadena
    
    // Bucle que recorre la cadena hasta encontrar el carácter nulo ('\0')
    for (i = 0; s[i]; i++);
    
    return i;  // Retorna la cantidad de caracteres (sin incluir el nulo)
}

// Función principal del programa
int main(int ac, char** av) {
    // Verifica si se proporcionó al menos un argumento
    // ac = argument count (contador de argumentos)
    // av[0] = nombre del programa, av[1] = primer argumento real
    if (ac >= 2)
        // Escribe el primer argumento en la salida estándar:
        // - 1 = descriptor de archivo para salida estándar (pantalla)
        // - av[1] = cadena a escribir (primer argumento del usuario)
        // - ft_strlen(av[1]) = cantidad de caracteres a escribir
        write(1, av[1], ft_strlen(av[1]));
    
    // Siempre escribe un salto de línea al final
    write(1, "\n", 1);
    
    return 0;  // Retorna 0 indicando que el programa terminó exitosamente
}