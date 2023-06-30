/*class Solution {
private:
    bool isValid(string s) {
        int sum = 0;
        for(char &c : s) {
            if(c == '(') ++sum;
            else if(c == ')') --sum;
            if(sum < 0) return false;
        }
        return sum == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int num1 = 0, num2 = 0;
        for(char &c : s) {
            num1 += c == '(';
            if (num1 == 0) {
                num2 += c == ')';
            } else {
                num1 -= c == ')';
            }
        }
        vector<string> ret;
        dfs(s, 0, num1, num2, ret);
        return ret;
    }
    void dfs(string s, int beg, int num1, int num2, vector<string> &ret) {
        if(num1 == 0 && num2 == 0) {
            if(isValid(s))
                ret.push_back(s);
        } else {
            for(int i = beg; i < s.size(); ++i) {
                string tmp = s;
                if(num2 == 0 && num1 > 0 && tmp[i] == '(') {
                    if(i == beg || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, num1 - 1, num2, ret);
                    }
                }
                if(num2 > 0 && tmp[i] == ')') {
                    if(i == beg || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, num1, num2 - 1, ret);
                    }
                }
            }
        }
    }
};
*/










/*/*
    Time Complexity : |STR|*2^|STR|
    Space Complexity : |STR|*|STR|

    where |STR| is the length of the given string STR.


#include <queue>
#include <unordered_set>

bool isValid(string &s)
{
    int count = 0;

    // Iterate the string
    for (auto c : s)
    {
        // Increment count when '(' is encountered
        if (c == '(')
        {
            count++;
        }
        
        // Decrement count when ')' is encountered
        if (c == ')')
        {
            if (count > 0)
            {
                count--;
            }

            // If count becomes less than 0, string is invalid
            else
            {
                return false;
            }
        }
    }
    return !count;
}

vector<string> minRemovaltoMakeStringValid(string &str)
{
    // Initialize queue to store the strings
    queue<string> q;

    // Initialize hashmap to check duplicates
    unordered_set<string> hashTable;

    q.push(str);
    vector<string> answer;
    
    // Iterate while queue is not empty
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        
        // If current string is already processed, continue with next string
        if (hashTable.count(s))
        {
            continue;
        }
        
        // Otherwise insert the current string to hash map
        hashTable.insert(s);
        if (isValid(s))
        {
            answer.push_back(s);
        }

        // Generate strings by removing '(' or ')'
        else if (answer.empty())
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ')' || s[i] == '(')
                {
                    q.push(s.substr(0, i) + s.substr(i + 1));
                }
            }
        }
    }
    
    return answer;
}


*/






/*class Solution {
    int get_cor_len(string s,int &a){ // Function to get the correct required valid length of string 
        
        int l = 0,ml = 0; // l->left, ml->misplaced left
        int r = 0,mr = 0; // r->right, mr->misplaced right
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(isalpha(s[i])){
                a++;
                flag = 1;
            }
            else if(s[i]=='('){
                l++;
                ml++;
            }
            else{
                r++;
                if(ml>0){
                    ml--;
                }
                else{
                    mr++;
                }
            }
        }
        return (l-ml+r-mr+a);
    }
    
    string get_alpha(string s,int count){ // Function to get the alphabets from the given string
        int n = s.size();
        string alpha = "";
        int a = 0;
        for(char c:s){
            if(isalpha(c)){
                alpha.push_back(c);
                c++;
            }
            if(c==count)
                break;
        }
        return alpha;
    }
    
    void solve(vector<string> &result,string out,string s,
               int index,int left,int right,int cor_len,int n){ // Main backtracking function to get our result
        
        if(out.size()>cor_len){ //If output size is greater than the correct required length, then end the
            return;                    // currect function
        }
		/* If index comes to the end of the string, then validate the output size,
		open brackets and close brackets, and then check whether current output is
		present in the result vector or not, then store the output, if all the
		requirements met.. 
        if(index==n){
            if(out.size()==cor_len && left==right){ 
                if(find(result.begin(),result.end(),out)==result.end()){ 
                    result.push_back(out);  
                }
            }
            return;
        }
		/* If index is not at the end of the string, but output size matches the
		correct length, then check whether the current output is present in the 
		result vector or not, and if it is not present, then store it in the result
		and return...
        if(out.size()==cor_len && left==right){  
            if(find(result.begin(),result.end(),out)==result.end()){
                    result.push_back(out);
            }
            return;
        }
        if(out.size()+n-index>=cor_len){ //If output size plus the given string left to be checked is greater than or equal to the correct length
            if(left==right){  // If current output is balanced
                if(s[index]=='('){
                    solve(result,out+s[index],s,index+1,left+1,right,cor_len,n);
                    solve(result,out,s,index+1,left,right,cor_len,n);
                }
                else if(isalpha(s[index])){
                    solve(result,out+s[index],s,index+1,left,right,cor_len,n);
                }
                else{
                    solve(result,out,s,index+1,left,right,cor_len,n);
                }
            }
            else{  // If current output is not balanced
                if(s[index]=='('){
                    solve(result,out+s[index],s,index+1,left+1,right,cor_len,n);
                    solve(result,out,s,index+1,left,right,cor_len,n);
                }
                else if(isalpha(s[index])){
                    solve(result,out+s[index],s,index+1,left,right,cor_len,n);
                }
                else{
                    solve(result,out+s[index],s,index+1,left,right+1,cor_len,n);
                    solve(result,out,s,index+1,left,right,cor_len,n);
                }
            }
        }
        
        return;
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        string out;
        int alpha = 0;
        int cor_len = get_cor_len(s,alpha); //To get the correct required length
        
        if(cor_len==0) //If correct length is zero, then simply return the vector of empty string
            return {""};
        else if(cor_len==alpha){   // If all the parentheses is misplaced and alphabets are present in the 
            return {get_alpha(s,alpha)};  // given string, then return the string of alphabets
        }
        solve(result,out,s,0,0,0,cor_len,s.size()); // Backtracking starts here...
        return result;
    }
};*/