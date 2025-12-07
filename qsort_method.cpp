#include "qsort_method.h"
#include <stdlib.h>  // Для qsort
#include <string.h>  // Для strcmp

// Функція порівняння для qsort (має специфічну сигнатуру)
int compare_for_qsort(const void* a, const void* b) {
    const Data* da = (const Data*)a;
    const Data* db = (const Data*)b;

    // 1. Порівнюємо value3 (найвищий пріоритет)
    int cmp = strcmp(da->value3, db->value3);
    if (cmp != 0) return cmp;

    // 2. Порівнюємо value2 (другий пріоритет)
    if (da->value2 != db->value2) return da->value2 - db->value2;

    // 3. Порівнюємо value1 (третій пріоритет)
    return strcmp(da->value1, db->value1);
}

// Обгортка для qsort
void qsort_wrapper(Data arr[], int n) {
    qsort(arr, n, sizeof(Data), compare_for_qsort);
}