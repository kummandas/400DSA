/*
class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i;
        int index=-1;
        for(int i=N-2;i>=0;i--){ // piche se dekho increasing order pe hai array.
           if(arr[i]<arr[i+1]){   // pehle wo index dhundho jahape ye order break ho raha (BREAKPOINT).
               index=i;           // agar nehi mila index to index= -1 hi rahega.
               break;
           }
        }
        
        if(index==-1){    // EDGE CASE -:
            reverse(arr.begin(),arr.end()); // nehi mila matlab yeh last permutation 
            return arr;  // hai , so reverse karke rerurn kar diya. pehla permutaion
        }  // print ho jayega. kyu ki last ka next kya hoga? jo ekdam pehle aya, wo hoga
        
        for(int i=N-1;i>index;i--){ // ab piche se check karo konsa wala element just
            if(arr[i]>arr[index]){  // greater hai breakpoint wala element se. array
                swap(arr[i],arr[index]); // piche se increasing order main hai. so
                break;  // loop chalake easily find out kar liya konsa just greater hai.
            }  // ab dono element ko swap kardo. bas kam khatam almost.
        }
        reverse(arr.begin()+(index+1),arr.end()); // ab jaha pe array ka breakpoint
        return arr;// mila useke badke index se baki ka array sort ya reverse kar do. kahani khatam :)
    }
};





// C++ program to find the smallest number which greater than a given number
// and has same set of digits as given number
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Utility function to swap two digits
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Given a number as a char array number[], this function finds the
// next greater number.  It modifies the same array to store the result
void findNext(char number[], int n)
{
    int i, j;

    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;

    // If no such digit is found, then all digits are in descending order
    // means there cannot be a greater number with same set of digits
    if (i==0)
    {
        cout << "Next number is not possible";
        return;
    }

    // II) Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;

    // III) Swap the above found smallest digit with number[i-1]
    swap(&number[smallest], &number[i-1]);

    // IV) Sort the digits after (i-1) in ascending order
    sort(number + i, number + n);

    cout << "Next number with same set of digits is " << number;

    return;
}

// Driver program to test above function
int main()
{
    char digits[] = "534976";
    int n = strlen(digits);
    findNext(digits, n);
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int n, vector<int> arr)
{
    // If number of digits is 1 then just return the vector
    if (n == 1)
        return arr;

    // Start from the right most digit and find the first
    // digit that is
    // smaller than the digit next to it.
    int i = 0;
    for (i = n - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1])
            break;
    }

    // If there is a possibility of a next greater element
    if (i != 0) {
        // Find the smallest digit on right side of (i-1)'th
        // digit that is
        // greater than number[i-1]
        for (int j = n - 1; j >= i; j--) {
            if (arr[i - 1] < arr[j]) {
                // Swap the found smallest digit i.e. arr[j]
                // with arr[i-1]
                swap(arr[i - 1], arr[j]);
                break;
            }
        }
    }

    // Reverse the digits after (i-1) because the digits
    // after (i-1) are in decreasing order and thus we will
    // get the smallest element possible from these digits
    reverse(arr.begin() + i, arr.end());

    // If i is 0 that means elements are in decreasing order
    // Therefore, no greater element possible then we just
    // return the lowest possible
    // order/element formed from these digits by just
    // reversing the vector

    return arr;
}

int main()
{
    int n = 6;
    vector<int> v{ 5,3,4,9,7,6 };
    vector<int> res;
    res = nextPermutation(n, v);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}