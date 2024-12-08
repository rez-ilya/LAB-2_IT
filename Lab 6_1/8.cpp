#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int rows1, cols1, rows2, cols2;
    // ���� ������������ ������
    cout << "������� ���������� ����� � �������� ������ �������: ";
    cin >> rows1 >> cols1;
    cout << "������� ���������� ����� � �������� ������ �������: ";
    cin >> rows2 >> cols2;
    // �������� ����������� ��������� ������
    while (cols1 != rows2) {
        cout << "��������� ������ ����������: ���������� �������� ������ ������� �� ����� ���������� ����� ������ �������." << endl;
            cout << "������� ���������� ����� � �������� ������ �������: ";
        cin >> rows1 >> cols1;
        cout << "������� ���������� ����� � �������� ������ �������: ";
        cin >> rows2 >> cols2;
    }
    // ������������ ��������� ������ ��� ������
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
            result[i][j] = 0; // ������������� ���������� ������
        }
    }
    // ���� ������ �������
    cout << "������� �������� ������ �������:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "������� ����� matrix1[" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }
    // ���� ������ �������
    cout << "������� �������� ������ �������:" << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << "������� ����� matrix2[" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }
    // ��������� ������
    for (int i = 0; i < rows1; i++) { //������ ������ �������
        for (int j = 0; j < cols2; j++) { //������� ������ �������
            for (int k = 0; k < cols1; k++) { // ��� rows2, ��� ��� cols1 == rows2; ��������
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // ����� ���������� ��������� ������
    cout << "\n��������� ��������� ������:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    // ������������ ������
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
