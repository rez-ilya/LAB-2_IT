#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    // Ввод размерностей массива
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;
    // Проверка ограничения n * m < 100
    while (n * m >= 100) {
        cout << "Ошибка: n * m должно быть меньше 100." << endl;
        cout << "Введите количество строк n: ";
        cin >> n;
        cout << "Введите количество столбцов m: ";
        cin >> m;
    }
    // Динамическое выделение памяти для массива A
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }
    // Заполнение массива по диагоналям
    int value = 0;
    for (int diag = 0; diag < n + m - 1; diag++) {
        for (int i = 0; i < n; i++) {
            int j = diag - i;
            if (j >= 0 && j < m) {
                A[i][j] = value;
                value++;
            }
        }
    }
    // Вывод массива с отступом для каждого элемента
    cout << "\nПолученный массив:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Ручное форматирование для отступа в 3 символа
            if (A[i][j] < 10) {
                cout << "  " << A[i][j] << " ";  // Отступ для однозначных чисел
            }
            else if (A[i][j] < 100) {
                cout << " " << A[i][j] << " ";   // Отступ для двухзначных чисел
            }
            else {
                cout << A[i][j] << " ";          // Без отступа для трехзначных чисел
            }
        }
        cout << endl;
    }
    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}