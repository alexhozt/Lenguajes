// lo que hace el programa: escribe el ultimo parametro pasado al programa seguido de un salto de linea

#include <unistd.h> // biblioteca estandar de servicios del sistema operativo POSIX, proporciona la funcion write() que se usa para escribir la salida esatandar.

size_t uf_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0')
        len += 1;
    return len;

}

int main(int ac, const char **av) {
    if (ac > 1) {
        write(1, av[ac - 1], uf_strlen(av[ac - 1]));
    }
    write(1, "\n", 1);
    return 0;
}