#pragma once
#ifndef DATA_H
#define DATA_H

// Структура даних з трьома полями
struct Data {
    char value1[32];  // Перший рядок (пріоритет 3)
    int value2;       // Ціле число (пріоритет 2)
    char value3[32];  // Другий рядок (пріоритет 1)
};

#endif // DATA_H