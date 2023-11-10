// ICE1292 - Programming with C Lab
// Exam - 2021

// Problem No: 3
// Solution by: Saifullah (ICE 21)

// Problem Topics: charecter array, string, function, pointer

#include <stdio.h>

void deleteChar(char *str, char c)
{
    if (str == NULL) // if the first pointer of the string is NULL
    {
        printf("Invalid string!\n"); // that means the string is invalid
        return;
    }

    char *read = str; // read pointer is the current position's pointer which I am reading
    char *keep = str; // keep pointer is the current position's pointer which I am going to keep in the string

    while (*read != '\0') // untill we reach the end
    {
        if (*read != c) // if current position's charecter is not the charecter to be deleted
        {
            *keep = *read; // keeping the charecter in the string
            keep++; // moving keep pointer to next address or position
        }
        read++; // moving read pointer to next address or position
    }

    *keep = '\0'; // Terminate the string after deleting all the occurences
    return;
}

int main()
{
    char str[100]; // declaring a charecter string variable that can store upto 100 charecters
    char c; // declaring a charecter variable

    printf("Enter a string: ");
    gets(str); // taking input of the string

    printf("Enter the character to be deleted: ");
    scanf(" %c", &c); // taking input of the charecter to be deleted

    deleteChar(str, c); // calling the function to delete all occurences of the charecter

    printf("String after deleting all occurences of '%c' is : %s\n", c, str); // printing the final string

    return 0;
}
