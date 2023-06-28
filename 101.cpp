/*

    Time Complexity : O(MlogM), Sorting the array(nums1) costs O(MlogM). Where M is the size of the
    Array(nums1).

    Space Complexity : O(1), Constant Space. 

    Solved using Array + Sorting.




/***************************************** Approach 1 ****************************************

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};







    Time Complexity : O(N+M), Because we iterate N+M times for both the Array(nums1 and nums2). Where
    M is the number of elements in Array(nums1) and N is the number of elements in Array(nums2).

    Space Complexity : O(1), Constant Space. 

    Solved using Array + Two Pointers. 




**************************************** Approach 2 ****************************************

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }
            else{
                nums1[k] = nums2[j];
                j--; k--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};

*/

// C++ program to merge two sorted arrays/
#include<iostream>
using namespace std;

// Merge nums1[0..m-1] and nums2[0..n-1] into
// nums3[0..m+n-1]
void mergeArrays(int nums1[], int nums2[], int m,int n, int nums3[]){
    int i = 0;
    int j = 0;
    int k = 0;

    // Traverse both array
    while (i<m && j <n){
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (nums1[i] < nums2[j])
            nums3[k++] = nums1[i++];
        else
            nums3[k++] = nums2[j++];
    }

    // Store remaining elements of first array
    while (i < m)
        nums3[k++] = nums1[i++];

    // Store remaining elements of second array
    while (j < n)
        nums3[k++] = nums2[j++];
}

// Driver code
int main(){
    int nums1[] = {1, 3, 5, 7};
    int m = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {2, 4, 6, 8};
    int n = sizeof(nums2) / sizeof(nums2[0]);

    int nums3[m+n];
    mergeArrays(nums1, nums2, m, n, nums3);

    cout << "Array after merging" <<endl;
    for (int i=0; i < m+n; i++)
        cout << nums3[i] << " ";

    return 0;
}
