// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}

// A utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// Driver code
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}







#include <iostream>
using namespace std;

// Swap Function.
void swap(int &a,int &b){
int temp =a;
a=b;
b=temp;
}

// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
	int low =0,high = n-1;
	while(low<high){
	if(arr[low]<0){
		low++;
	}else if(arr[high]>0){
		high--;
	}else{
		swap(arr[low],arr[high]);
	}
	}
}
void displayArray(int arr[],int n){
for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
}
cout<<endl;
}
int main() {
	// Data
	int arr[] = {1, 2, -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	reArrange(arr,n);
	displayArray(arr,n);
	return 0;
}
