#include<bits/stdc++.h>
// BFS APPROACH
bool iscyclicBFS(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
   unordered_map<int,int> parent;
   parent[src] = -1;
   visited[src] = 1;
   queue<int> q;
   q.push(src);
   while(!q.empty()){
       int front = q.front();
       q.pop();
       
       for(auto neighbour: adj[front]){
           if(visited[neighbour] == true && neighbour != parent[front]){
               return true;
           }
           else if(!visited[neighbour]){
               q.push(neighbour);
               visited[neighbour] = true;
               parent[neighbour] = front;
           }
       }
   }
   return false;
   
}
// DFS APPROACH
bool iscyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
   visited[node] = true;
   for(auto neighbour : adj[node]){
       if(!visited[neighbour]){
           bool cycleDetected = iscyclicDFS(neighbour,node,visited,adj);
           if(cycleDetected)
               return true;
       }else if(neighbour != parent){
           return true;
       }
   }
   return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   // Write your code here.
   unordered_map<int,list<int>> adj;
   for(int i = 0;i<m;i++){
       int u = edges[i][0];
       int v = edges[i][1];
       
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   
   
//     conditon for checking all components of graph
   unordered_map<int,bool> visited;
   for (int i = 0;i<n;i++){
       if(!visited[i]){
           bool ans = iscyclicDFS(i,-1,visited,adj);
           if(ans == 1)
               return "Yes";
       }
   }
   return "No";
}