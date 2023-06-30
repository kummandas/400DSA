#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.

    // create an adjacency list 
    unordered_map<int , list<pair<int ,int>>> adj;
    for(int i = 0 ; i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    } 

    // creation of distance array
    vector<int> dist(vertices);
    for(int i =0;i<vertices;i++){
        dist[i]= INT_MAX ;
    }
    // creation of set
    set<pair<int,int>> st;
    dist[source] =0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        auto top = *(st.begin());
        int nodedist = top.first;
        int topnode = top.second;
        st.erase(st.begin());

        // traverse all neighbours
        for(auto neighbour : adj[topnode]){
            if(nodedist+neighbour.second  < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first));
                if(record !=st.end()){
                    st.erase(record);
                }
                dist[neighbour.first] = nodedist + neighbour.second ;
                st.insert(make_pair(dist[neighbour.first] , neighbour.first));
            }
        }
    }
    return dist;
}