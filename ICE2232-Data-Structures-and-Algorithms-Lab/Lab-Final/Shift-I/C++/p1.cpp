#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter row and column number: ";
    cin >> n >> m;
    srand(time(0));

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    cout << "The array:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    int choice = -1;
    while (choice != 0)
    {
        cout << "1. Search a value\n";
        cout << "0. End program!\n";
        cin >> choice;
        if (choice == 1)
        {
            int val;
            cin >> val;

            cout << "Indices: ";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if( arr[i][j] == val )
                    {
                        cout << i << j << " ";
                    }
                }
            }
            cout << "\n\n";
        }
        else if( choice != 0 )
        {
            cout << "Wrong input!\n\n";
        }
    }
    return 0;
}