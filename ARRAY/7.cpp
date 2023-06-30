#include<iostream>
using namespace std;

void reverse(int*arr,int low,int high){
    while(low<high){
        swap(arr[low++],arr[high--]);
    }
}
void rotate(int arr[], int n)
{
    reverse(arr,0,n-1);
    reverse(arr,1,n-1);
    
}



