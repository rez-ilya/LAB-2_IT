#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int Q;
    cout << "������� ����� Q (Q >= 3): ";
    cin >> Q;
    while (Q < 3) {
        cout << "������: Q ������ ���� ������ ��� ����� 3." << endl;
        cout << "������� ����� Q (Q >= 3): ";
        cin >> Q;
    }
    // ������������ ��������� ������ ��� ������� Z
    int* Z = new int[Q];
    cout << "������� ������ Z: " << endl;
    for (int i = 0; i < Q; i++) {
        cout << "������� ����� *(Z + " << i << ") : ";
        cin >> *(Z + i); // ������ �������� � ������� ����������
    }
    // �������� �� ������� ��������� �������������� ����������
    int max_length = 0;
    int start_index = 0;
    int common_step = 0;
    for (int i = 0; i < Q - 2; i++) {
        int current_step = *(Z + i) - *(Z + i + 1);  // �������� ����� ������� � ��������� ���������(��� ������������������)
            int current_length = 2;
        for (int j = i + 1; j < Q - 1; j++) { //��� ������� Z[i] (����� ��������� ������������������) �������� ���-�� �� ������-��
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
