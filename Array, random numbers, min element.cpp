#include <iostream>
#include <iomanip>
//#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    double a, b; //  [a,b]
    cout << "Ââåäèòå ÷èñëî à: ";
    cin >> a;
    cout << "Ââåäèòå ÷èñëî â: ";
    cin >> b;

    double matrix[10][10]; // 

    
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            matrix[counter_rows][counter_columns] = (double(rand()) / RAND_MAX) * (b - a) + a; ,b]

    cout << "\nÑãåíåðèðîâàííûé ìàññèâ âåùåñòâåííûõ ÷èñåë" << endl;
    // 
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
    {
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            cout << setw(7) << fixed << setprecision(3) << matrix[counter_rows][counter_columns];
        cout << endl;
    }

    double min = matrix[0][0]; // 
    int nom; 

    
    for (int counter_rows = 0; counter_rows < 10; counter_rows++)
    {
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
        {
            if (matrix[counter_rows][counter_columns] < min)
            {
                min = matrix[counter_rows][counter_columns]; // 
                nom = counter_rows; // 
            }
        }
    }

    cout << "\nÍîìåð ñòðîêè ñ ìèíèìàëüíûì ýëåìåíòîì: " << (nom + 1) << endl;
    cout << "Ìèíèìàëüíûé ýëåìåíò: " << min << endl;
    // ïåðåñòàíîâêà ñòðîê
    if (nom != 0) // 
    {
        double temp[10]; // 
        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            temp[counter_columns] = matrix[0][counter_columns]; // 

        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            matrix[0][counter_columns] = matrix[nom][counter_columns]; // 

        for (int counter_columns = 0; counter_columns < 10; counter_columns++)
            matrix[nom][counter_columns] = temp[counter_columns]; //

    // 
        cout << "\nÌàññèâ ñ ïåðåñòàíîâëåííûìè ñòðîêàìè" << endl;
        for (int counter_rows = 0; counter_rows < 10; counter_rows++)
        {
            for (int counter_columns = 0; counter_columns < 10; counter_columns++)
                cout << setw(7) << fixed << setprecision(3) << matrix[counter_rows][counter_columns];
            cout << endl;
        }

    } // êîíåö if

    return 0;
}
