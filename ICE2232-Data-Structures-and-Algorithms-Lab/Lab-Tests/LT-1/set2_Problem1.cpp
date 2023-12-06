// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 1
// Set: 1
// Problem No: 1
// Solution by: Saifullah (ICE 21)

#include <iostream>
using namespace std;

bool check(int a, int b, char choice)
{
    if (choice == 'D' and a < b) // if user have chosen even integer and first element is less than second element
        return false;            // it is not in descending order
    if (choice == 'A' and a > b) // if user have chosen odd integer and first element is greater than second element
        return false;            // it is not in ascending order
    return true;                 // else they are in desired order
}
void swap(int &a, int &b)
{
    int c = a; // store a in c
    a = b;     // store b in a
    b = c;     // store c in b
    return;
}

void bubbleSort(int a[], int n, char choice)
{
    // initialising bubble sort algorithm
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // checking if adjecent elements are fulfilling the sorting requirment depending upon choice
            if (check(a[j], a[j + 1], choice) == false)
            {
                swap(a[j], a[j + 1]); // swap elements
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the arra: ";
    cin >> n;
    srand(time(0)); // making the random integer genarator dependent on current time
    int a[n];       // array declaring
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000; // limiting the genarated number between 0 and 999
        cout << a[i] << " ";  // printing it
    }
    cout << "\n";

    char choice;
    while (true) // untill correct input instruction is provided
    {
        cout << "\nEnter A for ascending and D for descending: "; // instruction to choose sorting option
        cin >> choice;
        if( choice == 'A' or choice == 'D' )
            break;
        cout << "Wrong input! please try again!";
    }

    bubbleSort(a, n, choice); // calling bubble sort function to sort the array in desired manner

    cout << "\nThe bubble sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}