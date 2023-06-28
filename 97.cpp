/*bool findPair(int arr[], int size, int n)
{
    sort(arr,arr+size);
    int i = 0;  
    int j = 1;
 
    while (i<size && j<size)
    {
        if (i != j && arr[j]-arr[i] == n)
        {
            return true;
        }
        else if (arr[j]-arr[i] < n)
            j++;
        else
            i++;
    }
 
    return false;
}
*/

// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;

// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
	// Initialize positions of two elements
	int i = 0;
	int j = 1;

	// Search for a pair
	while (i < size && j < size)
	{
		if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
		{
			cout << "Pair Found: (" << arr[i] <<
						", " << arr[j] << ")";
			return true;
		}
		else if (arr[j]-arr[i] < n)
			j++;
		else
			i++;
	}

	cout << "No such pair";
	return false;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 8, 30, 40, 100};
	int size = sizeof(arr)/sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	return 0;
}

// This is code is contributed by rathbhupendra



bool bs(int arr[],int size,int target,int i){

    int low=0;

    int high=size-1;

    while(low<=high){

        int mid=low+(high-low)/2;

            

        if(arr[mid]==target&&mid!=i){

            return true;

        }else if(arr[mid]<target){

            low=mid+1;

        }else{

            high=mid-1;

        }

    }

    return false;

}

bool findPair(int arr[], int size, int n){

    bool f=false;

    sort(arr,arr+size);

   for(int i=0;i<size;i++){

      f= bs(arr,size,arr[i]+n,i);

      if(f==true){

          return true;

      }

   }

   return false;
}