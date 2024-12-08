#include <iostream>
using namespace std;
int five() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    cout << "������� ����� ������� (n): ";
    cin >> n;
    while (n < 3) {
        cout << "������: ������ ������ ��������� ������� 3 ��������." << endl;
        cout << "������� ����� ������� (n): ";
        cin >> n;
    }
    cout << "������� ����������� k: ";
    cin >> k;
    // ������������ ��������� ������ ��� ������� 
    double* arr = new double[n];
    cout << "������� " << n << " ������������ �����:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    // ������������� ������������ ��������
    double min_value = *(arr); // ������ �������� ����� ��� �����������
    // ���������� ����������� �������� ����� ���������, ����� ������
    for (int i = 1; i < n - 1; i++) {
        // ��������� ����������� ��������
        if (!((*(arr + i) < *(arr + i - 1)) &&
            (*(arr + i) < *(arr + i + 1))) &&
            *(arr + i) < min_value) min_value = *(arr + i);
    }
    if (*(arr + (n - 1)) < min_value) min_value = *(arr + (n - 1)); //��������� ��������� ������� �������

        // ������� ������� ������
        int dangerous_drops = 0;
    for (int i = 1; i < n - 1; i++) {
        if ((*(arr + i) < *(arr + i - 1)) &&
            (*(arr + i) < *(arr + i + 1)) &&
            (*(arr + i) <= min_value / k)) dangerous_drops++;
    }
    // ����� ����������
    cout << "���������� ������� ������: " << dangerous_drops << endl;
    // ������������ ������
    delete[] arr;
    return 0;
}