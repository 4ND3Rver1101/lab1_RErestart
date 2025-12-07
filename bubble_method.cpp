#include "bubble_method.h"
#include <string.h>  // Для strcmp
#include <stdlib.h>  // Для qsort

// Функція порівняння для сортування (враховує пріоритети)
int compare_data(const Data* a, const Data* b) {
    // 1. Порівнюємо value3 (найвищий пріоритет)
    int cmp = strcmp(a->value3, b->value3);
    if (cmp != 0) return cmp;

    // 2. Порівнюємо value2 (другий пріоритет)
    if (a->value2 != b->value2) return a->value2 - b->value2;

    // 3. Порівнюємо value1 (третій пріоритет)
    return strcmp(a->value1, b->value1);
}

// Реалізація сортування бульбашкою
void bubble_sort(Data arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Використовуємо функцію порівняння
            if (compare_data(&arr[j], &arr[j + 1]) > 0) {
                // Міняємо місцями
                Data temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}