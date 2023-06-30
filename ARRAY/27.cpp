
#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{
    // Fix the first element as A[i] 
    for (int i = 0; i < arr_size - 2; i++)
    { 

        // Fix the second element as A[j] 
        for (int j = i + 1; j < arr_size - 1; j++)
        { 

            // Now look for the third number 
            for (int k = j + 1; k < arr_size; k++)
            { 
                if (A[i] + A[j] + A[k] == sum)
                { 
                    cout << "Triplet is " << A[i] <<
                        ", " << A[j] << ", " << A[k]; 
                    return true; 
                } 
            } 
        } 
    } 

    // If we reach here, then no triplet was found 
    return false; 
} 

/* Driver code */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
    find3Numbers(A, arr_size, sum); 
    return 0; 
} 

// This is code is contributed by rathbhupendra





// C++ program to find a triplet
#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    /* Sort the elements */
    sort(A, A + arr_size);
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) {

        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements
        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i], A[l],A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}

/* Driver program to test above function */
int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    find3Numbers(A, arr_size, sum);
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)