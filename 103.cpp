// C++ implementation of above approach
/*
#include <bits/stdc++.h>
using namespace std;

/* Function to print product array
for a given array arr[] of size n 
void productArray(int arr[], int n)
{

    // Base case
    if (n == 1) {
        cout << 0;
        return;
    }

    int i, temp = 1;

    /* Allocate memory for the product array 
    int* prod = new int[(sizeof(int) * n)];

    /* Initialize the product array as 1 
    memset(prod, 1, n);

    /* In this loop, temp variable contains product of
       elements on left side excluding arr[i] 
    for (i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }

    /* Initialize temp to 1
    for product on right side 
    temp = 1;

    /* In this loop, temp variable contains product of
       elements on right side excluding arr[i] 
    for (i = n - 1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }

    /* print the constructed prod array 
    for (i = 0; i < n; i++)
        cout << prod[i] << " ";

    return;
}

// Driver Code
int main()
{
    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);
}

// This code is contributed by rathbhupendra


*/


// C++ program for the above approach
#include <iostream>
using namespace std;

long* productExceptSelf(int a[], int n)
{
    long prod = 1;
    long flag = 0;

    // product of all elements
    for (int i = 0; i < n; i++) {
        // counting number of elements which have value 0
        if (a[i] == 0)
            flag++;
        else
            prod *= a[i];
    }

    // creating a new array of size n
    long* arr = new long[n];

    for (int i = 0; i < n; i++) {

        // if number of elements in array with value 0 is
        // more than 1 than each value in new array will be
        // equal to 0
        if (flag > 1)
            arr[i] = 0;

        // if no element having value 0 than we will insert
        // product/a[i] in new array
        else if (flag == 0)
            arr[i] = (prod / a[i]);

        // if 1 element of array having value 0 than all the
        // elements except that index value , will be equal
        // to 0
        else if (flag == 1 && a[i] != 0)
            arr[i] = 0;

        // if(flag == 1 && a[i] == 0)
        else
            arr[i] = prod;
    }
    return arr;
}

// Driver Code
int main()
{
    int n = 5;
    int array[] = { 10, 3, 5, 6, 2 };

    long* ans;
    ans = productExceptSelf(array, n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)