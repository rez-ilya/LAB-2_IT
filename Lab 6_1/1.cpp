#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    unsigned short a, b;
    cout << "Введите целые числа a и b: ";
    cin >> a >> b;
    unsigned short* pa, * pb; //Инициализируем указатели  Ponamarev Daniil
    pa = &a; pb = &b; //"Направляем" указатели на переменные Reznov Ilya
    cout << "pa = " << pa << " *pa = " << *pa << endl;
    cout << "pb = " << pb << " *pb = " << *pb << endl;
    if (*pa > *pb) *pa *= 2; else *pb *= 2; //Увеличиваем значение максимальной переменной в 2 раза
    cout << "Увеличиваем значение максимальной переменной в 2 раза:\n";
    cout << "pa = " << pa << " *pa = " << *pa << endl;
    cout << "pb = " << pb << " *pb = " << *pb << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(*pa, *pb); // Меняем значения 
    cout << "Смена значений переменных через указатели:\n";
    cout << "pa = " << pa << " *pa = " << *pa << endl;
    cout << "pb = " << pb << " *pb = " << *pb << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b;
    return 0;
}