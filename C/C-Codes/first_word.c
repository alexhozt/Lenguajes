// Code by Alex
// Codigo quue imprime la primera palabra de un argumento pasado, ignorardo esapcios y tabuladores iniciales.


#include <stdio.h> // bibloteca estandar de entrada y salida
#include <unistd.h> // biblioteca estandar de servicios del sistema operativo POSIX, proporciona la funcion write() que se usa para escribir la salida esatandar.

void print_upto(char* start, char* end) {
    while (start != end) {
        write(1, start, 1); // escribe un caracter a la salida estandar, 1 es el descriptor de archivo para la salida estandar (stdout), start es un puntero al caracter que se va a escribir, y 1 indica que se escribe un solo caracter.
        start++; // incrementa el puntero para apuntar al siguiente caracter.
    }
}

// argc: numero de argumentos pasados al programa desde la linea de comandos
// argv: array de cadenas de caracteres que contienen los argumentos pasados al programa desde la linea

int main(int argc, char** argv) {

    char* start; // puntero al inicio de la primera palabra
    char* end; // puntero al final de la primera palabra

    if (argc == 2) {
        start = argv[1]; // inicializa el puntero start al inicio del primer argumento pasado al programa.

        // avanzar el puntero start para ignorar espacios y tabuladores iniciales
        // *start es el caracter actual

        while (*start == ' ' || *start == '\t') {
            start++; // incrementar start para saltar/saltar espacios y tabuladores iniciales.
        }

        end = start; // copia la direccion de start a end

        // avanzar el puntero end hasta el final de la primera palabra
        // *end es el caracter actual
        // *end && --> asegura que no se llegue al final de la cadena
        // *end != ' ' --> asegura que no se llegue a un espacio
        while (*end && *end != ' ' && *end != '\t') {
            end++;
        }

        print_upto(start, end); // llama a la funcion print_upto para imprimir la primera palabra
    }

    write(1, "\n", 1); // escribe un salto de linea al final de la salida
    return 0; // indica que el programa termino correctamente

}


/*

Flujo de ejecucion con ejemplo:

$> ./first_word " Hello, World!"

argv[1] = " Hello, World!"
            ^
            start apunta al primer caracter del argumento
            end apunta al primer caracter del argumento
            ^
            start avanza para ignorar espacios y tabuladores iniciales
              ^
              start apunta al caracter 'H'
              end apunta al caracter 'H'
              ^
            end avanza hasta el final de la primera palabra
                   ^
                   start apunta al caracter 'H'
                   end apunta al espacio despues de la coma
                   ^
            print_upto imprime los caracteres desde start hasta end
            Salida: "Hello,"

*/

