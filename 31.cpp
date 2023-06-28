//Back-end complete function template for C++

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int n = array.size();
        //Using two pointers which help in finding the index with which
        //the elements need to be swapped if they are not in correct position. 
        int start = 0, end = n-1;
     
        for (int i=0; i<=end;)
        {
            //If current element is smaller than lower range, we swap 
            //it with value on next available smallest position. 
            if (array[i] < a)
                swap(array[i++], array[start++]);
     
            //If current element is greater than higher range, we swap 
            //it with value on next available greatest position. 
            else if (array[i] > b)
                swap(array[i], array[end--]);
            
            //Else we just move ahead in the array.
            else
                i++;
        }
    }
};