// Back-end complete function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        int d = (B - A);
        if(d == 0)
            return 1;
        if(d < 0){
            if(C >= 0)
                return 0;
            if(d%C == 0)
                return 1;
            return 0;
        }
        else{
            if(C <= 0)
                return 0;
            if(d%C == 0)
                return 1;
            return 0;
        }
        return 0;
    }
};







 /*
	Time Complexity: O(log(N))
	Space complexity: O(1)

	Where 'N' is the missing of elements in the given sequence.
*/

int missingNumber(vector<int> &arr, int n) 
{   
    /* 
      The first term and (n+1)th term of the AP will be arr[0] and arr[n-1].
      So using the formula the common difference d will be given by d = (arr[n-1] - arr[0]) / n
    */
    int a = arr[0];
    int d = (arr[n - 1] - arr[0]) / n;
    int l = 0, r = n - 1;
    int missing = -1;
    
    while (l <= r) 
    {
        long int mid = (l + r) / 2;
        
        // Check if the difference between the adjacent elements of the mid is same as the common difference or not
        if (mid + 1 < n && arr[mid + 1] - arr[mid] != d) 
        {
            missing = arr[mid] + d;
            break;
        }
        
        if (mid - 1 >= 0 && arr[mid] - arr[mid - 1] != d) 
        {
            missing = arr[mid - 1] + d;
            break;
        }

        // Check If the difference is not same as the common difference of the AP
        if (arr[mid] == a + mid * d) 
        {
            l = mid + 1;
        } 
        else 
        {
            r = mid - 1;
        }
    }

    // Return the missing number
    return missing;
}

