// leetcode
// by [alex]
// nivel: Facil

/*

Posicion de inserción de Busqueda

Dado un array ordenado de enteros distintos y un valor objetivo,
se devuelve el indice si se encuentra el objetivo. Si no, se devuelva
el indice donde estaria si se insertara en orden.

Debes escribir un algoritmo con O(log n) de complejidad de tiempo.


*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    // definicion de punteros para el inicio y el final del array
    int left = 0; // inicio
    int right = numsSize - 1; // final, limite superior de la busqueda

    while(left <= right) {
        int mid = left + (right - left) / 2; // punto medio

        if(nums[mid] == target) {
            return mid; // si el elemento del medio es el objetivo, devolver su indice
        } else if(nums[mid] < target) {
            left = mid + 1; // buscar en la mitad derecha
        } else {
            right = mid - 1; // buscar en la mitad izquierda.
        }
    }

    return left;

}


int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int index = searchInsert(nums, numsSize, target);
    printf("El índice de inserción para el objetivo %d es: %d\n", target, index);

    target = 2;
    index = searchInsert(nums, numsSize, target);
    printf("El índice de inserción para el objetivo %d es: %d\n", target, index);

    target = 7;
    index = searchInsert(nums, numsSize, target);
    printf("El índice de inserción para el objetivo %d es: %d\n", target, index);

    target = 0;
    index = searchInsert(nums, numsSize, target);
    printf("El índice de inserción para el objetivo %d es: %d\n", target, index);

    return 0;
}

