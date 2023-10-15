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

int Insert(struct Array *arr, int index, int item)
{
    if (index <= 0 || index > arr->length)
    {
        return -1;
    }
    else if (arr->length == arr->size)
    {
        return -1;
    }
    else
    {
        // shift items to the right
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        // insert item at index
        arr->A[index] = item;
        // increment length
        arr->length++;
    }

    return 0;
}

int Delete(struct Array *arr, int index)
{
    int x;

    if (index >= 0 && index < arr->length)
    {
        // item to be deleted
        x = arr->A[index];

        // shift items to the left
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        // decrement length
        arr->length--;

        return x;
    }
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i <= arr->length; i++)
    {
        if (key == arr->A[i])
        {
            // swap(&arr->A[i], &arr->A[i - 1]); // tranposition to improve linear search
            swap(&arr->A[i], &arr->A[0]); // moving to front/head
            return i;                     // returns index at which item is found
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int key)
{
    // define low = 0 and high = length -1
    int low = 0;
    int high = arr->length - 1;

    while (low <= high) // low has to be less or eqaul to high
    {
        int mid = (low + high) / 2; // getting mid

        if (key == arr->A[mid])
        {
            return mid;
        }
        else if (key > arr->A[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // not found
}

int RecursiveBS(int a[], int low, int high, int key)
{
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key > a[mid])
        {
            return RecursiveBS(a, mid + 1, high, key);
        }
        else
        {
            return RecursiveBS(a, low, mid - 1, key);
        }
    }
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

// with auxiliary array
void Reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = new int[arr->length]; // creating auxiliary array

    // revesing array
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    // copying reversed array to original array
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
};

// without auxiliary array - with swapping

void ReverseWSwapping(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
};

// inserting in an sorted array

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return;
    }
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // Insert(&arr, 0, 1);
    // Append(&arr, 10);
    // Delete(&arr, 2);
    // LinearSearch(&arr, 6);
    // BinarySearch(&arr, 6);
    Display(arr);
    return 0;
}