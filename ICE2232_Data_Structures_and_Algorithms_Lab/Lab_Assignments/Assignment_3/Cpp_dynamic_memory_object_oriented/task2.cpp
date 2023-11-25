#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct node
{
    T data;
    node *next;

    node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class stack
{
private:
    node<T> *tail;

public:
    stack() : tail(nullptr){};
    T pop()
    {
        T val;
        if (tail != nullptr)
        {
            node<T> *temp = tail->next;
            val = tail->data;
            delete tail;
            tail = temp;
        }
        else
        {
            cout << "The stack is already empty!\n\n";
        }
        return val;
    }
    void push(const T &val)
    {
        node<T> *newNode = new node(val);
        if (tail != nullptr)
            newNode->next = tail;
        tail = newNode;
    }
    T top()
    {
        return tail->data;
    }
    bool empty()
    {
        return tail == nullptr;
    }
};

// swap two elements in the array
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partition the array and returning the index of the pivot element
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

// quicksort using stack
void quicksort(int arr[], int low, int high, stack<int> &stc)
{
    // push initial values of low and high to the stack
    stc.push(low);
    stc.push(high);

    // continue popping from the stack until it is empty
    while (!stc.empty())
    {
        // pop high and low
        high = stc.pop();
        low = stc.pop();

        // partition the array
        int pivotIndex = partition(arr, low, high);

        // if there are elements on the left side of the pivot, push them to the stack
        if (pivotIndex > low)
        {
            stc.push(low);
            stc.push(pivotIndex - 1);
        }

        // if there are elements on the right side of the pivot, push them to the stack
        if (pivotIndex < high)
        {
            stc.push(pivotIndex + 1);
            stc.push(high);
        }
    }
}

// print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    printArray(arr, size);

    stack<int> stc;
    quicksort(arr, 0, size - 1, stc);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
