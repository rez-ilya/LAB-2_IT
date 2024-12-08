#include <iostream>
using namespace std;
int five() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    cout << "Введите длину массива (n): ";
    cin >> n;
    while (n < 3) {
        cout << "Ошибка: массив должен содержать минимум 3 элемента." << endl;
        cout << "Введите длину массива (n): ";
        cin >> n;
    }
    cout << "Введите коэффициент k: ";
    cin >> k;
    // Динамическое выделение памяти для массива 
    double* arr = new double[n];
    cout << "Введите " << n << " вещественных чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    // Инициализация минимального элемента
    double min_value = *(arr); // Первое значение берем как минимальное
    // Определяем минимальное значение среди элементов, кроме спадов
    for (int i = 1; i < n - 1; i++) {
        // Обновляем минимальное значение
        if (!((*(arr + i) < *(arr + i - 1)) &&
            (*(arr + i) < *(arr + i + 1))) &&
            *(arr + i) < min_value) min_value = *(arr + i);
    }
    if (*(arr + (n - 1)) < min_value) min_value = *(arr + (n - 1)); //Проверяем последний элемент массива

        // Подсчёт опасных спадов
        int dangerous_drops = 0;
    for (int i = 1; i < n - 1; i++) {
        if ((*(arr + i) < *(arr + i - 1)) &&
            (*(arr + i) < *(arr + i + 1)) &&
            (*(arr + i) <= min_value / k)) dangerous_drops++;
    }
    // Вывод результата
    cout << "Количество опасных спадов: " << dangerous_drops << endl;
    // Освобождение памяти
    delete[] arr;
    return 0;
}