
class Solution{
public:
	int isPalindrome(string S)
	{

		for(int i = 0; i < S.size()/2; i++)
			if(S[i] != S[S.size() - i - 1])
				return 0;

		return 1;
	}

   
};


class Solution{
public:	
	
	

	  

int isPalindrome(string S)
	{
	    // Your code goes here
	    int s=0;
	    int e=S.size()-1;
	    while(s<e){
	        if(S[s]!=S[e]){
	            return false;
	        }else{
	            s++;
	            e--;
	        }
	    }
	    return true;
	}
	

};





	int isPalindrome(string s)
	{
	    // Your code goes here
	    string s1=s;
	    reverse(s.begin(),s.end());
	    if(s1==s)
	    return 1;
	    else
	    return 0;
	}