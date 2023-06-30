#include<algorithm>  
class Solution {
public:
     int PalinArray(int a[], int n)

    {   

        string s = to_string(a[0]);

        for(int i=0; i<n; i++) {

            if(i > 0) s = to_string(a[i]); 

            reverse(s.begin(), s.end());

            if(a[i] == stoi(s)) continue;

            else return 0;

        }

        return 1;

    }

};