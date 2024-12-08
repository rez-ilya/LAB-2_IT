#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int Q;
    cout << "Введите число Q (Q >= 3): ";
    cin >> Q;
    while (Q < 3) {
        cout << "Ошибка: Q должно быть больше или равно 3." << endl;
        cout << "Введите число Q (Q >= 3): ";
        cin >> Q;
    }
    // Динамическое выделение памяти для массива Z
    int* Z = new int[Q];
    cout << "Задайте массив Z: " << endl;
    for (int i = 0; i < Q; i++) {
        cout << "Введите число *(Z + " << i << ") : ";
        cin >> *(Z + i); // Вводим элементы с помощью указателей
    }
    // Проверка на наличие убывающей арифметической прогрессии
    int max_length = 0;
    int start_index = 0;
    int common_step = 0;
    for (int i = 0; i < Q - 2; i++) {
        int current_step = *(Z + i) - *(Z + i + 1);  // Разность между текущим и следующим элементом(шаг последовательности)
            int current_length = 2;
        for (int j = i + 1; j < Q - 1; j++) { //Для каждого Z[i] (старт возможной последовательности) проверяю сущ-ет ли послед-ть
            if (*(Z + j) - *(Z + j + 1) == current_step) {
                current_length++;
            }
            else {
                break;
            }
        }
        if ((current_step > 0) && (current_length > 2) && (current_length >
            max_length)) { // Если шаг > 0, то прогрессия - убывающая 
            max_length = current_length;
            start_index = i;
            common_step = current_step;
        }
    }
    // Вывод результата
    if (max_length > 2) {
        cout << "Убывающая арифметическая прогрессия найдена." << endl;
        cout << "Длина прогрессии: " << max_length << endl;
        cout << "Номер первого элемента: " << start_index + 1 << endl;
        cout << "Прогрессия: ";
        for (int i = 0; i < max_length; i++) {
            cout << *(Z + start_index + i) << " ";
        }
    }
    else {
        cout << "Убывающей арифметической прогрессии не найдено.";
    }
    // Освобождение памяти
    delete[] Z;
    return 0;
}
