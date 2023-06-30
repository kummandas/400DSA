#include<iostream>
using namespace std;


struct Pair
{
    int min ;
    int max ;
};

Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i ;


    if (n== 1)
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }

    if(arr[0]>arr[1]){
        minmax.min =  arr[1];
        minmax.max = arr[0];
            }

            else
            {
                minmax.max= arr[0];
                minmax.min= arr[1];
            }

            for(i = 2; i < n; i++)
            {
                if(arr[i] > minmax.max)
                minmax.max = arr[i];

                else if (arr[i] < minmax.min)
                {
                    minmax.min = arr[i];
                }
            }
            return minmax;
}

int main()
{
    int arr[] = { 1000, 11, 445, 
                  1, 330, 3000 };
    int arr_size = 6;
      
    struct Pair minmax = getMinMax(arr, arr_size);
      
    cout << "Minimum element is " 
         << minmax.min << endl;
    cout << "Maximum element is " 
         << minmax.max;
           
    return 0;
} 



 /*
    Time Complexity: O(N). 
    Space Complexity: O(1).

    Where N is the size of the array "arr".
*/

int sumOfMaxMin(int arr[], int n) {

    int maximum, minimum;

    maximum = minimum = arr[0];

    for (int i = 1; i < n; i++) {

        // If arr[i] > maximum, then make maximum = arr[i].
        if (arr[i] > maximum) {
            maximum = arr[i];
        }

        // Else If arr[i] < minimum, then make minimum = arr[i].
        else if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return maximum + minimum;
} 