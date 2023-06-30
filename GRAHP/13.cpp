#include <bits/stdc++.h> 

void topologicalSortUtil(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk, int src) {
    // Mark current vertex visited
    visited[src] = true;  
    // Iterating over adjacent vertices.
    for(int node : adj[src]) {
        if(!visited[node]) {
            topologicalSortUtil(adj, visited, stk, node);
        }
    }
    // Push vertex in stack after pushing all its adjacent (and their adjacent and so on) verices.
    stk.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
     // Creating adjacency list.
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    } 
     vector<bool> visited(v);
    stack<int> stk;

        for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            topologicalSortUtil(adj, visited, stk, i);
        }
    }
        vector<int> result;
    while(!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}


















//kanh
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int, list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
        q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return ans;
}








#include <bits/stdc++.h>
void dfs(int node , unordered_map<int,set<int>>&adj , vector<bool>&visited , stack<int>&s){
    visited[node]=true;
    for(auto neighbour :adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,adj,visited,s);
          }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,set<int>>adj;
    vector<bool>visited(v);
     //creating adjacency List from edges vector
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].insert(v);
    }
    
    //calling dfs function to detect cylce
    stack<int>s;
    for(int i=0;i<v;i++){
       if(!visited[i]){
            dfs(i,adj,visited,s);
       }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}