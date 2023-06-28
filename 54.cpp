class Solution {
	public:
	    int t[1001][1001]; // Declare the cache memory for fast response
	    
	    int helper(string &s1, string &s2, int m, int n){
	        // if any or both of the string is empry, then there'll be no subsequence, hence return 0
	        if(m == 0 || n == 0) return 0;
	        
	        // if Subproblem is already calculated then return from there
	        if(t[m][n] != -1) return t[m][n];
	        
	        // if current element is valid and its not repeating then add '1' and proceed next element
	        if(s1[m-1] == s2[n-1] && m != n){
	            return t[m][n] = 1 + helper(s1, s2, m-1, n-1);
	        }
	        // else calculate for both the string by reducing one by one.
	        else{
	            return t[m][n] = max(helper(s1, s2, m, n-1), helper(s1, s2, m-1, n));
	        }
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Initializing our cache matrix with all '-1' value.
		    memset(t, -1, sizeof(t));
		    
		    int n = str.size();
		    return helper(str, str, n, n);
		}





        class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    int t[n+1][n+1];
		    
		    for(int i=0;i<n+1;i++) t[i][0] = 0;
		    for(int j=0;j<n+1;j++) t[0][j] = 0;
		    
		    for(int i=1;i<n+1;i++){
		        for(int j=1;j<n+1;j++){
		            if(str[i-1] == str[j-1] && i != j){
		                t[i][j] = 1 + t[i-1][j-1];
		            }
		            else{
		                t[i][j] = max(t[i][j-1], t[i-1][j]);
		            }
		        }
		    }
		    return t[n][n];
		}
};
};