#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int rows1, cols1, rows2, cols2;
    // Ввод размерностей матриц
    cout << "Введите количество строк и столбцов первой матрицы: ";
    cin >> rows1 >> cols1;
    cout << "Введите количество строк и столбцов второй матрицы: ";
    cin >> rows2 >> cols2;
    // Проверка возможности умножения матриц
    while (cols1 != rows2) {
        cout << "Умножение матриц невозможно: количество столбцов первой матрицы не равно количеству строк второй матрицы." << endl;
            cout << "Введите количество строк и столбцов первой матрицы: ";
        cin >> rows1 >> cols1;
        cout << "Введите количество строк и столбцов второй матрицы: ";
        cin >> rows2 >> cols2;
    }
    // Динамическое выделение памяти для матриц
    int** matrix1 = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = new int[cols1];
    }
    int** matrix2 = new int* [rows2];
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = new int[cols2];
    }
    int** result = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        result[i] = new int[cols2];
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Инициализация результата нулями
        }
    }
    // Ввод первой матрицы
    cout << "Введите элементы первой матрицы:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "Введите число matrix1[" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }
    // Ввод второй матрицы
    cout << "Введите элементы второй матрицы:" << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << "Введите число matrix2[" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }
    // Умножение матриц
    for (int i = 0; i < rows1; i++) { //строка первой матрицы
        for (int j = 0; j < cols2; j++) { //столбцы второй матрицы
            for (int k = 0; k < cols1; k++) { // Или rows2, так как cols1 == rows2; элементы
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // Вывод результата умножения матриц
    cout << "\nРезультат умножения матриц:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    // Освобождение памяти
    for (int i = 0; i < rows1; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    for (int i = 0; i < rows2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    for (int i = 0; i < rows1; i++) {
        delete[] result[i];
    }
    delete[] result;
    return 0;
}
