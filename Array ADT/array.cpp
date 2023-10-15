#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    cout << "\nThe elements of the array are: \n";
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

// int main()
// {
//     struct Array arr;
//     int n, i;
//     cout << "Enter the number of elements: ";
//     cin >> arr.size; // size of array in heap
//     arr.A = new int[arr.size];

//     cout << "Enter the length of the array: ";
//     cin >> arr.length;

//     cout << "Enter the elements of the array: ";
//     for (i = 0; i < arr.length; i++)
//     {
//         cin >> arr.A[i];
//     }

//     Display(arr);

//     return 0;
// }

int Append(struct Array *arr, int x)
{

    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x; // explanation: arr->length++ is post increment, so first the value of arr->length is used and then incremented
    }
    return 0;
};

// int Insert()
// {
// }

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr, 10);
    Display(arr);
    return 0;
}