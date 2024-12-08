#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int N, M;
    // ���� ������������ ������� Z
    cout << "������� ���������� ����� (N): ";
    cin >> N;
    cout << "������� ���������� �������� (M): ";
    cin >> M;
    while (N <= 0 || M <= 0) {
        cout << "������: ������� ������� ������ ���� ��������������." << endl;
        cout << "������� ���������� ����� (N): ";
        cin >> N;
        cout << "������� ���������� �������� (M): ";
        cin >> M;
    }
    // ������������ ��������� ������ ��� ������� Z
    int** Z = new int* [N];
    for (int i = 0; i < N; i++) {
        Z[i] = new int[M];
    }
    // ���� ��������� ������� Z
    cout << "������� �������� ������� Z[" << N << "][" << M << "]:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "������� ����� Z[" << i << "][" << j << "]: ";
            cin >> Z[i][j];
        }
    }
    // ������������ ��������� ������ ��� ������� B
    int* B = new int[N];
    int K = 0;  // ������� ��������� ������� B
    for (int i = 0; i < N; i++) {
        int max_element = Z[i][0];  // ������������� ������������� �������� ������
        for (int j = 1; j < M; j++) {
            if (Z[i][j] > max_element) {
                max_element = Z[i][j];
            }
        }
        // ���������� ������� �������� ������ � ������ B, ���� �� �� ����� ����
        if (Z[i][0] != 0) {
            B[K] = Z[i][0];
            K++;
        }
        // ������ ������� �������� ������ �� ������������ �������
        Z[i][0] = max_element;
    }
    // ����� ������� Z
    cout << "\n������ Z ����� ������:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Z[i][j] << " ";
        }
        cout << endl;
    }
    // ����� ������� B
    if (K > 0) {
        cout << "\n������ B:" << endl;
        for (int i = 0; i < K; i++) { // i < K, ����� �� �������� ����
            cout << B[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "\n������ B ����." << endl;
    }
    // ������������ ������
    for (int i = 0; i < N; i++) {
        delete[] Z[i];
    }
    delete[] Z;
    delete[] B;
    return 0;
}