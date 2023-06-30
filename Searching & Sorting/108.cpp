
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>&range){
    int n=range.size();
    vector<vector<int>>fin;
    for(int i=0;i<n-1;i++){
        if(range[i][1] >= range[i+1][0]){
            range[i+1][0]=min(range[i][0],range[i+1][0]);
            range[i+1][1]=max(range[i][1],range[i+1][1]);
        }
        else{
            fin.push_back(range[i]);
        }
    }
    fin.push_back(range[n-1]);
    return fin;
}

vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>queries){
    
    //sort the ranges
    sort(range.begin(),range.end());
    
    //merge the overlapping intervals 
    vector<vector<int>>merged=mergeIntervals(range);
    
    //set to store the cumulative sum of number of elements in each range
    //eg {1 4} {6 8} {9 10} would store {4 7 9} in set.
    set<int>s;
    int cumsum=0;
    for(auto cur_range:merged){
        int num_ele=cur_range[1]-cur_range[0]+1;
        cumsum+=num_ele;
        s.insert(cumsum);
    }
    
    //final vector to store the result of each query
    vector<int>fin;
    
    //for each query get the lower bound of required kth smallest element.
    // go to the index returned by lower_bound and get the required element
    for(auto q:queries){
        auto it=s.lower_bound(q);
        if(it==s.end())fin.push_back(-1);
        
        //if the required element is in first range
        else if(it==s.begin()){
            fin.push_back(merged[0][0]+q-1);
        }
        
        //if the required element is in ith range. then discard previous range elements
        // if previous elements are prevele. then look for k=q-prevele in the current range
        else{
            int prevele=*prev(it);
            int kth=q-prevele;
            int idx=distance(s.begin(),it);
            fin.push_back(merged[idx][0]+kth-1);
        }
            
    }
    
    return fin;
} 

 
// Driver\'s Function
int main()
{
    vector<vector<int>>range = {{1, 4}, {6, 8}}; 
    int n =range.size();
    vector<int>queries = {2, 6, 10};
    int q = queries.size();
 
    vector<int>ans=kthSmallestNum(range, queries);
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}