#include <iostream>
#include <iomanip>
//#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    double a, b; // ������� ������� [a,b]
    cout << "������� ����� �: ";
    cin >> a;
    cout << "������� ����� �: ";
    cin >> b;

    double matrix[10][10]; // ������� ��������� �����

    // ������������� ���������� ������� ���������� �������
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            matrix[counter_rows][counter_columns] = (double(rand()) / RAND_MAX) * (b - a) + a; // ��������� ��������� ������������� ����� ���������� ������������� �� ������� [a,b]

    cout << "\n��������������� ������ ������������ �����" << endl;
    // ����� ���������������� �������
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
    {
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            cout << setw(7) << fixed << setprecision(3) << matrix[counter_rows][counter_columns];
        cout << endl;
    }

    double min = matrix[0][0]; // ����������, ��� �������� ������������ ��������
    int nom; // ���������� ����� ������ � ����������� ���������

    // ����� ������������ �������� � �������
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
    {
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
        {
            if (matrix[counter_rows][counter_columns] < min)
            {
                min = matrix[counter_rows][counter_columns]; // ��������� �������� ������������ ��������
                nom = counter_rows; // ���������� ����� ������
            }
        }
    }

    cout << "\n����� ������ � ����������� ���������: " << (nom + 1) << endl;
    cout << "����������� �������: " << min << endl;
    // ������������ �����
    if (nom != 0) // ���� ����������� ������� �� ���������� � ������ ������
    {
        double temp[10]; // ��������� ������ ��� �������� ������ ������
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            temp[counter_columns] = matrix[0][counter_columns]; // ��������� �������� ������ ������ �� ��������� ������

        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            matrix[0][counter_columns] = matrix[nom][counter_columns]; // ��������� �������� ������ � ����������� ��������� � ����� ������ ���������� ��������

        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            matrix[nom][counter_columns] = temp[counter_columns]; // ���������� �������� �� ���������� ������� �� ����� ������ � ��� ���������

    // ����� ������� � ����������������� ��������
        cout << "\n������ � ����������������� ��������" << endl;
        for (int counter_rows = 0; counter_rows < 10; counter_rows++)
        {
            for (int counter_columns = 0; counter_columns < 10; counter_columns++)
                cout << setw(7) << fixed << setprecision(3) << matrix[counter_rows][counter_columns];
            cout << endl;
        }

    } // ����� if

    return 0;
}