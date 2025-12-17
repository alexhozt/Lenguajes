// by alex
// ingenieria civil en informatica
// Fecha del dia siguiente

#include <stdio.h>


int año_bisiesto(int a) {
    // Verifica si un año es bisiesto
    return ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0); // condición de año bisiesto
    // Un año es bisiesto si es divisible por 4, no es divisible por 100, o es divisible por 400
    // Ejemplo: 2000 es bisiesto, 1900 no lo es 
 
}

int cantMaxDiasMes(int m, int a) {
    // Retorna la cantidad máxima de días en un mes dado un año
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30; 
    if (m == 2) {
        if (año_bisiesto(a))
            return 29;
        else 
            return 28;
    }

    return -1; // Mes inválido
}


int main() {
    int d, m, a;
    printf("Ingrese el dia: "); scanf("%d", &d);
    printf("Ingrese el mes: "); scanf("%d", &m);
    printf("Ingrese el año: "); scanf("%d", &a);

    // Verificación de la fecha
    if (a < 0 || m < 1 || m > 12 || cantMaxDiasMes(m, a) < d || d <= 0) {
        printf("La fecha es inválida\n");
        return -1;
    }

    // Obtención de la fecha del día siguiente
    int cantDiasMes = cantMaxDiasMes(m, a);
    if (d == cantDiasMes) {
        if (m == 12) { // Último día del año
            d = 1; 
            m = 1;
            a++;
        } else {
            d = 1;
            m++;
        }
    } else {
        d++;
    }

    printf("La fecha del siguiente día es %d/%d/%d\n", d, m, a);
    
    return 0; // Fin del programa
}