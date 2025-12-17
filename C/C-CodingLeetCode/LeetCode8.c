// leetcode
// by [alex]
// nivel: Facil

/*

Eliminar elemento

Dado un array entero y un entero, elmina todas las ocurrencias in situ. El orden de los elementos puede
cambiarse. Luego devuelve el numero de elementos en los que no son iguales a val.


¿Qué pide el problema?

Tienes un array nums y un valor val. Debes:

Eliminar todas las ocurrencias de val del array

Mover todos los elementos que NO son iguales a val al principio del array

Devolver cuántos elementos quedan después de "eliminar" val



*/ 


#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) {

    int k = 0; // contador de elementos que no son iguales a val

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // mover el elemento al principio del array, nums[k] es la posicion donde se guarda el elemento, nums[i] es el elemento actual
            k++; // incrementar el contador
        }
    }
    return k; // devolver el numero de elementos que no son iguales a val

}


int main() {
    int nums[] = {3, 2, 2, 3}; // array de prueba
    int val = 3; // valor a eliminar
    int numsSize = sizeof(nums) / sizeof(nums[0]); // tamaño del array

    int k = removeElement(nums, numsSize, val); // llamar a la funcion

    printf("El numero de elementos que no son iguales a %d es: %d\n", val, k);
    printf("El array modificado es: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]); // imprimir el array modificado
    }
    printf("\n");

    return 0;
}