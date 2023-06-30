class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(int i = 1; i < strs.size(); i++) {
            int j;
            for(j = 0; j < strs[i].size(); j++) {
                if(ans[j] != strs[i][j])
                    break;
            }
            ans = ans.substr(0, j);
            if(ans == "")
                return ans;
        }
        
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans;
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[0][i] != strs[j][i])
                {
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};