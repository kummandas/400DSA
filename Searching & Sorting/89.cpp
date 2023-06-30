vector<int> find(int arr[], int n , int x )
{




    int first_occur = -1;
    int last_occur  = -1;
    int st = 0;
    int end = n-1;
    while(st<=end)
    {
        int mid =(end+st)/2;
        if(arr[mid]>x)
           end = mid-1;
           
        else if(arr[mid]<x)
             st = mid+1;
             
        else
        {
            if(arr[st] == x and arr[end] == x)
            {
                first_occur = st;
                last_occur  = end;
                break;
            }
            else if(arr[st] == x)
            {
                first_occur = st;
                end--;
            }    
            else
            {
                last_occur = end;
                st++;
            }    
        }
    }
    
    return {first_occur,last_occur};
    
}