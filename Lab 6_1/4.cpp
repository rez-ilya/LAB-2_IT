#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "������� ����� N (N >= 3): ";
    cin >> N;
    while (N < 3) {
        cout << "������: N ������ ���� ������ ��� ����� 3." << endl;
        cout << "������� ����� N (N >= 3): ";
        cin >> N;
    }
    // ������������ ��������� ������ ��� ������� Z
    int* Z = new int[N];
    cout << "������� ������ Z: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "������� ����� *(Z + " << i << ") : ";
        cin >> *(Z + i); // ������ �������� � ������� ����������
    }
    // �������� �� ������� ��������� �������������� ����������
    int max_length = 0;
    int start_index = 0;
    int common_step = 0;
    for (int i = 0; i < N - 2; i++) {
        int current_step = *(Z + i) - *(Z + i + 1);  // �������� ����� ������� � ��������� ���������(��� ������������������)
            int current_length = 2;
        for (int j = i + 1; j < N - 1; j++) { //��� ������� Z[i] (����� ��������� ������������������) �������� ���-�� �� ������-��
            if (*(Z + j) - *(Z + j + 1) == current_step) {
                current_length++;
            }
            else {
                break;
            }
        }
        if ((current_step > 0) && (current_length > 2) && (current_length >
            max_length)) { // ���� ��� > 0, �� ���������� - ��������� 
            max_length = current_length;
            start_index = i;
            common_step = current_step;
        }
    }
    // ����� ����������
    if (max_length > 2) {
        cout << "��������� �������������� ���������� �������." << endl;
        cout << "����� ����������: " << max_length << endl;
        cout << "����� ������� ��������: " << start_index + 1 << endl;
        cout << "����������: ";
        for (int i = 0; i < max_length; i++) {
            cout << *(Z + start_index + i) << " ";
        }
    }
    else {
        cout << "��������� �������������� ���������� �� �������.";
    }
    // ������������ ������
    delete[] Z;
    return 0;
}
