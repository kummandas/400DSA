// C++ program to print common elements in three arrays
#include <bits/stdc++.h>
using namespace std;

// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1,
                int n2, int n3)
{
    // Initialize starting indexes for ar1[], ar2[] and
    // ar3[]
    int i = 0, j = 0, k = 0;

    // Iterate through three arrays while all arrays have
    // elements
    while (i < n1 && j < n2 && k < n3) {
        // If x = y and y = z, print any of them and move
        // ahead in all arrays
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
            cout << ar1[i] << " ";
            i++;
            j++;
            k++;
        }

        // x < y
        else if (ar1[i] < ar2[j])
            i++;

        // y < z
        else if (ar2[j] < ar3[k])
            j++;

        // We reach here when x > y and z < y, i.e., z is
        // smallest
        else
            k++;
    }
}

// Driver code
int main()
{
    int ar1[] = { 1, 5, 10, 20, 40, 80 };
    int ar2[] = { 6, 7, 20, 80, 100 };
    int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)










#include <bits/stdc++.h>
using namespace std;

bool binary_search(int arr[], int n, int element)
{
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] == element) {
            return true;
        }
        else if (arr[mid] > element) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return false;
}
void findCommon(int a[], int b[], int c[], int n1, int n2,
                int n3)
{
    // Iterate on first array
    for (int j = 0; j < n1; j++) {
        if (j != 0 && a[j] == a[j - 1]) {
            continue;
        }
        // check if the element is present in 2nd and 3rd
        // array.
        if (binary_search(b, n2, a[j])
            && binary_search(c, n3, a[j])) {
            cout << a[j] << " ";
        }
    }
}

// Driver code
int main()
{
    int ar1[] = { 1, 5, 10, 20, 40, 80 };
    int ar2[] = { 6, 7, 20, 80, 100 };
    int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    cout << "Common Elements are " << endl;
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}

// This code is contributed by Anchal Agarwal