#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void sumf(int a[], int n, int& sum)
{
    for( int i = 0 ; i < n ; i++ )
    {
        sum += a[i];
    }
    cout << "Sum of the array is: " << sum << "\n\n";
    return;
}

void maxminf(int a[], int n, int& maxx, int& minn)
{
    for( int i = 0 ; i < n ; i++ )
    {
        if( minn > a[i] )
            minn = a[i];
        else if( maxx < a[i] )
            maxx = a[i];
    }
    cout << "Maximum element of array is: " << maxx << "\n";
    cout << "Minimum element of array is: " << minn << "\n\n";
    return;
}

void avgf(int a[], int n, int sum, double& avg)
{
    avg = (double)sum/n;
    cout << "The average of all elements of the array is: " << avg << "\n\n"; 
    return;
}

void printaf(int a[], int n)
{
    cout << "Current array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    return;
}

int main()
{
    int n = 20;
    int a[1000];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (rand() % 10000);
    }
    printaf(a, n);
    int exit = 0;
    int sum = 0, maxx = a[0], minn = a[0];
    double avg = 0;
    do
    {
        cout << "Select any following operation:\n";
        cout << "1. Calculate and print the sum of all elements in the array.\n";
        cout << "2. Find and print the maximum and minimum values in the array.\n";
        cout << "3. Calculate and print the average value of the elements.\n";
        int task;
        cin >> task;
        bool error = false;
        switch (task)
        {
        case 1:
            sumf(a, n, sum);
            break;
        case 2:
            maxminf(a, n, maxx, minn);
            break;
        case 3:
            avgf(a, n, sum, avg);
            break;
        default:
            error = true;
            break;
        }
        if (error)
        {
            cout << "Wrong input\n";
        }
        else
        {
            cout << "Do you want to do more operations?\nEnter 0 for NO anything else for YES\n";
            cin >> exit;
        }
    } while (exit != 0);
    cout << "THANK YOU!\n";
    return 0;
}