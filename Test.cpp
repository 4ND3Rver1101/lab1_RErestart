#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "data.h"
#include "bubble_method.h"
#include "qsort_method.h"
#include <fstream> 
using namespace std;


// Генерація випадкової структури
void generate_random_data(Data* d) {
    // Генеруємо value1: 31 випадкових символів + '\0'
    for (int i = 0; i < 31; i++) {
        d->value1[i] = rand() % 25 + 97;  // 'a'..'y'
    }
    d->value1[31] = '\0';  // Термінальний нуль

    // Генеруємо value2: випадкове ціле число
    d->value2 = rand() % 1000;

    // Генеруємо value3: 31 випадкових символів + '\0'
    for (int i = 0; i < 31; i++) {
        d->value3[i] = rand() % 25 + 97;  // 'a'..'y'
    }
    d->value3[31] = '\0';  // Термінальний нуль
}

// Друкуємо масив структур (перші n елементів)
void print_array(const Data arr[], int n, int limit = 3) {
    if (limit > n) limit = n;

    printf("first %d elements:\n", limit);
    for (int i = 0; i < limit; i++) {
        printf("[%2d] value1: %-10s | value2: %4d | value3: %s\n",
            i, arr[i].value1, arr[i].value2, arr[i].value3);
    }
}

// Копіюємо масив
void copy_array(const Data src[], Data dst[], int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

// Перевіряємо, чи відсортовано масив правильно
bool is_sorted_correctly(const Data arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Порівнюємо по value3
        int cmp = strcmp(arr[i].value3, arr[i + 1].value3);
        if (cmp > 0) return false;
        if (cmp < 0) continue;

        // Якщо value3 рівні, порівнюємо по value2
        if (arr[i].value2 > arr[i + 1].value2) return false;
        if (arr[i].value2 < arr[i + 1].value2) continue;

        // Якщо value2 рівні, порівнюємо по value1
        if (strcmp(arr[i].value1, arr[i + 1].value1) > 0) return false;
    }
    return true;
}

void test() {
    const int N = 14;  // Кількість елементів
    Data original[N];  // Початковий масив
    Data for_bubble[N];  // Копія для сортування бульбашкою
    Data for_qsort[N];   // Копія для qsort

    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Генеруємо початковий масив
    printf(" %d structur generator.\n", N);
    for (int i = 0; i < N; i++) {
        generate_random_data(&original[i]);
    }

    // Копіюємо масив для обох алгоритмів
    copy_array(original, for_bubble, N);
    copy_array(original, for_qsort, N);

    // Виводимо несортований масив
    printf("\n--- beginning massiv ---\n");
    print_array(original, N);

    // Сортуємо бульбашкою і вимірюємо час
    printf("\n--- bubble sort ---\n");
    clock_t start1 = clock();
    bubble_sort(for_bubble, N);
    clock_t end1 = clock();
    double bubble_time = (double)(end1 - start1) / CLOCKS_PER_SEC;

    printf("Proccesing time: %.6f sec\n", bubble_time);
    printf("Sort result: %s\n",
        is_sorted_correctly(for_bubble, N) ? "correct" : "incorrect");
    print_array(for_bubble, N);

    // Сортуємо qsort і вимірюємо час
    printf("\n--- qsort ---\n");
    clock_t start2 = clock();
    qsort_wrapper(for_qsort, N);
    clock_t end2 = clock();
    double qsort_time = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Proccesing time: %.6f sec\n", qsort_time);
    printf("Sort result: %s\n",
        is_sorted_correctly(for_qsort, N) ? "correct" : "incorrect");
    print_array(for_qsort, N);

    // Порівнюємо результати
    printf("\n--- Comparing results ---\n");
    bool results_match = true;
    for (int i = 0; i < N; i++) {
        if (strcmp(for_bubble[i].value1, for_qsort[i].value1) != 0 ||
            for_bubble[i].value2 != for_qsort[i].value2 ||
            strcmp(for_bubble[i].value3, for_qsort[i].value3) != 0) {
            results_match = false;
            break;
        }
    }

    if (results_match) {
        printf("identical results\n");
    }
    else {
        printf("different rsults\n");
    }

    ofstream fout;
    fout.open("Text.txt");
    fout << "" << endl;
}