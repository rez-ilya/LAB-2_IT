#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    unsigned short a, b;
    cout << "������� ����� ����� a � b: ";
    cin >> a >> b;
    unsigned short* pa, * pb; //�������������� ���������  Ponamarev Daniil
    pa = &a; pb = &b; //"����������" ��������� �� ���������� Reznov Ilya
    cout << "pa = " << pa << " *pa = " << *pa << endl;
    cout << "pb = " << pb << " *pb = " << *pb << endl;
    if (*pa > *pb) *pa *= 2; else *pb *= 2; //����������� �������� ������������ ���������� � 2 ����
    cout << "����������� �������� ������������ ���������� � 2 ����:\n";
    cout << "pa = " << pa << " *pa = " << *pa << endl;
    cout << "pb = " << pb << " *pb = " << *pb << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(*pa, *pb); // ������ �������� 
    cout << "����� �������� ���������� ����� ���������:\n";
    cout << "pa = " << pa << " *pa = " << *pa << endl;
    cout << "pb = " << pb << " *pb = " << *pb << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b;
    return 0;
}