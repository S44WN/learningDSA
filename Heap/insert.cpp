// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // lecture based
// void Insert(int A[], int n)
// {
//     int i = n;
//     int temp = A[n];

//     while (i > 0 && temp > A[i / 2])
//     {
//         A[i] = A[i / 2];
//         i = i / 2;
//     }
//     A[i] = temp;
// }

// // STL vector based
// // void InsertSTLVector(vector<int> &vec, int key)
// // {
// //     // insert key at end
// //     auto i = vec.size(); // i is index of last element
// //     vec.push_back(key);  // insert key at end

// //     // rearrange heap
// //     while (i > 0 && key > vec[i / 2])
// //     {
// //         vec[i] = vec[i / 2];
// //         i = i / 2;
// //     }
// //     vec[i] = key;
// // }

// // create
// void Create(int A[], int n)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         Insert(A, i);
//     }
// }

// // print vector

// void Print(vector<int> &vec)
// {
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }

// // delete

// int Delete(int a[], int n)
// {
//     int i, j, x, temp, val;

//     val = a[1]; // store the value of root node
//     x = a[n];   // store the value of last node

//     a[1] = a[n];
//     i = 1;
//     j = 2 * i;

//     while (j < n - 1)
//     {
//         if (a[j] < a[j + 1])
//         {
//             j = j + 1;
//         }
//         if (a[i] < a[j])
//         {
//             swap(a[i], a[j]);
//             i = j;
//             j = 2 * i;
//         }
//         else
//             break;
//     }
//     return val;
// }

// int main()
// {
//     // lecture based
//     int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
//     Create(A, sizeof(A) / sizeof(A[0]) - 1);

//     cout << "deleted element is " << Delete(A, 7) << endl;

//     for (int i = 1; i <= 7; i++)
//     {
//         cout << A[i] << " ";
//     }
//     cout << endl;

//     // STL vector based
//     // vector<int> vec = {10, 20, 30, 25, 5, 40, 35};
//     // for (int i = 1; i < vec.size(); i++)
//     // {
//     //     InsertSTLVector(vec, vec[i]);
//     // }
//     // Print(vec);

//     // return 0;
// }

#include <stdio.h>
#include <iostream>
using namespace std;

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int A[], int n)
{
    int i, j, x, temp, val;

    val = A[1];

    x = A[n];

    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;

    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;

        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40};
    int i;
    for (i = 2; i <= 7; i++)
        Insert(H, i);

    cout << "deleted element is " << Delete(H, 7) << endl;

    // //heap sort
    // for (i = 7; i > 1; i--)
    // {
    //     Delete(H, i);
    // }

    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}