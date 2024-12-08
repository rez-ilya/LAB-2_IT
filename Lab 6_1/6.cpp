#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    // ���� ������������ �������
    cout << "������� ���������� ����� n: ";
    cin >> n;
    cout << "������� ���������� �������� m: ";
    cin >> m;
    // �������� ����������� n * m < 100
    while (n * m >= 100) {
        cout << "������: n * m ������ ���� ������ 100." << endl;
        cout << "������� ���������� ����� n: ";
        cin >> n;
        cout << "������� ���������� �������� m: ";
        cin >> m;
    }
    // ������������ ��������� ������ ��� ������� A
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }
    // ���������� ������� �� ����������
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
    // ����� ������� � �������� ��� ������� ��������
    cout << "\n���������� ������:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // ������ �������������� ��� ������� � 3 �������
            if (A[i][j] < 10) {
                cout << "  " << A[i][j] << " ";  // ������ ��� ����������� �����
            }
            else if (A[i][j] < 100) {
                cout << " " << A[i][j] << " ";   // ������ ��� ����������� �����
            }
            else {
                cout << A[i][j] << " ";          // ��� ������� ��� ����������� �����
            }
        }
        cout << endl;
    }
    // ������������ ������
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}