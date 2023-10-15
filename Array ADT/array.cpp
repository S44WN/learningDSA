#include <iostream>
using namespace std;

struct Array
{
    int A[20];
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

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    return 0;
}