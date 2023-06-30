
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
       
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]==-1)matrix[i][j]=1e9;
                    if(i==j)matrix[i][j]=0;
                }
            }
        
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                }
            }
        }
        
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]==1e9)matrix[i][j]=-1;

                }
            }
        
	}









    #include<bits/stdc++.h>

int floydWarshall(int n,int m,int src,int dest,vector<vector<int>> &edges) {
    int matrix[n+1][n+1];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            matrix[i][j]=(i==j?0:INT_MAX);
        }
    }
    for(auto it:edges) {
        matrix[it[0]][it[1]]=it[2];
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i!=k && j!=k && matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX) {
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }
    return matrix[src][dest]==INT_MAX?1e9:matrix[src][dest];
}