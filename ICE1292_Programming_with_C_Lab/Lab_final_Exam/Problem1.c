// ICE1292 - Programming with C Lab
// Exam - 2021

// Problem No: 1
// Solution by: Saifullah (ICE 21)

#include <stdio.h>

int main()
{
    int n; // variable to take input of number of circles
    printf("Enter the number of circles: ");
    scanf("%d", &n);
    
    double pi = 3.14159265; // declaring variable for the value of pi
    double totalArea = 0; // declaring a variable for total area
    for( int i = 0 ; i <= n ; i++ )
    {
        double area = pi*(2*i + 1)*(2*i + 1); // calculating nth circle's area
        totalArea = totalArea + area; // adding the area to total area;
    }

    printf("The total area is: %lf\n", totalArea);
    return 0;
}