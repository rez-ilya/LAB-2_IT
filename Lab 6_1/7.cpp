#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int N, M;
    // Ввод размерностей массива Z
    cout << "Введите количество строк (N): ";
    cin >> N;
    cout << "Введите количество столбцов (M): ";
    cin >> M;
    while (N <= 0 || M <= 0) {
        cout << "Ошибка: размеры массива должны быть положительными." << endl;
        cout << "Введите количество строк (N): ";
        cin >> N;
        cout << "Введите количество столбцов (M): ";
        cin >> M;
    }
    // Динамическое выделение памяти для массива Z
    int** Z = new int* [N];
    for (int i = 0; i < N; i++) {
        Z[i] = new int[M];
    }
    // Ввод элементов массива Z
    cout << "Введите элементы массива Z[" << N << "][" << M << "]:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Введите число Z[" << i << "][" << j << "]: ";
            cin >> Z[i][j];
        }
    }
    // Динамическое выделение памяти для массива B
    int* B = new int[N];
    int K = 0;  // Счетчик элементов массива B
    for (int i = 0; i < N; i++) {
        int max_element = Z[i][0];  // Инициализация максимального элемента строки
        for (int j = 1; j < M; j++) {
            if (Z[i][j] > max_element) {
                max_element = Z[i][j];
            }
        }
        // Сохранение первого элемента строки в массив B, если он не равен нулю
        if (Z[i][0] != 0) {
            B[K] = Z[i][0];
            K++;
        }
        // Замена первого элемента строки на максимальный элемент
        Z[i][0] = max_element;
    }
    // Вывод массива Z
    cout << "\nМассив Z после замены:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Z[i][j] << " ";
        }
        cout << endl;
    }
    // Вывод массива B
    if (K > 0) {
        cout << "\nМассив B:" << endl;
        for (int i = 0; i < K; i++) { // i < K, чтобы не выводить нули
            cout << B[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "\nМассив B пуст." << endl;
    }
    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        delete[] Z[i];
    }
    delete[] Z;
    delete[] B;
    return 0;
}