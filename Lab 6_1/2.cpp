#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Задайте константу N: ";
    cin >> N;
    int Z[N], digit; //Объявление массива
    cout << "Задайте массив Z: \n";
    for (int i = 0; i < N; i++){
        cout << "Введите число Z[" << i << "] : ";
        cin >> digit;
        Z[i] = digit; //{15, 16, 17, -10, -2, 45}
    }
    //Вычисляем длину массива Q
    int len_Q = 0;
    for (int i = 0; i < N; i++){
        if (!((-3 <= Z[i]) && (Z[i] <= 7))) len_Q += 1;
        else break;
    }
    // Переписываем элементы массива Z до остановочного элемента в массив Q
    int Q[len_Q];
    for (int i = 0; i < len_Q; i++){
        Q[i]= Z[i];
        if ((len_Q-i == 1) & (Z[i] < 0)) swap(Q[i], Z[N-1]); //Меняем местами элементы массивов
    }
    //Выводим массивы на экран
    cout << "Массив Z:\n";
    for (int i = 0; i < N; i++)
        cout << "Z[" << i << "] = " << Z[i] << endl;
        
    cout << "Массив Q:\n";
    for (int i = 0; i < len_Q; i++)
        cout << "Q[" << i << "] = " << Q[i] << endl;
        
    return 0;
}
