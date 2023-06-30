// C++ program to Find the repeating
// and missing elements

#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[], int size)
{
	int i;
	cout << "The repeating element is ";

	for (i = 0; i < size; i++) {
		if (arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		else
			cout << abs(arr[i]) << "\n";
	}

	cout << "and the missing element is ";
	for (i = 0; i < size; i++) {
		if (arr[i] > 0)
			cout << (i + 1);
	}
}

/* Driver code */
int main()
{
	int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElements(arr, n);
}

// This code is contributed by Shivi_Aggarwal


#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[], int n)
{
	int temp[n] = {}; // Creating temp array of size n with
					// initial values as 0.
	int repeatingNumber=-1;
	int missingNumber=-1;

	for (int i = 0; i < n; i++) {
		temp[arr[i]-1]++;
		if (temp[arr[i] - 1] > 1) {
			repeatingNumber = arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (temp[i] == 0) {
			missingNumber = i + 1;
			break;
		}
	}

	cout << "The repeating number is " << repeatingNumber<<"."
		<< endl;
	cout << "The missing number is " << missingNumber<<"."
		<< endl;

}

int main()
{

	int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElements(arr, n);
	return 0;
}
// This code is contributed by vivek1208






#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[], int n){\
// sorting the array
sort(arr,arr+n);
cout << "The repeating element is ";
for(int i=0;i<n-1;i++){
	if(arr[i]==arr[i+1]){
		cout<<arr[i]<<endl;
		break;
	}
}

cout << "and the missing element is ";
for(int i=1;i<=n;i++){
	if(i!=arr[i-1]){
		cout<<i<<endl;
		break;
	}
}

}

int main() {

	int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElements(arr, n);
	return 0;
}
//contributed by akashish__
