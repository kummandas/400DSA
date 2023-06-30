#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>distance(n+1,1e9);
    distance[src] = 0;
    for(int i=0;i<n-1;i++) {
        for(auto j: edges) {
            int u = j[0];
            int v = j[1];
            int wt = j[2];
            if(distance[u] + wt < distance[v] and distance[v] != distance[u])
                distance[v] = distance[u] + wt;
        }
    }
    return distance[dest];
}