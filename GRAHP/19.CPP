// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];

	// Key values used to pick minimum weight edge in cut
	int key[V];

	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first
	// vertex.
	key[0] = 0;

	// First node is always root of MST
	parent[0] = -1;

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent
			// vertices of m mstSet[v] is false for vertices
			// not yet included in MST Update the key only
			// if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// Print the constructed MST
	printMST(parent, graph);
}

// Driver's code
int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	primMST(graph);

	return 0;
}

// This code is contributed by rathbhupendra













#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creating adfjacency list with weights
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
     //creating key,parent,mst
      vector<int>key(n+1,INT_MAX);
      vector<bool>mst(n+1,false);
      vector<int>parent(n+1,-1);
      parent[1]=-1;
     key[1]=0;
      //creating n-1 edges
      for(int e=0;e<n-1;e++){
          int current;
          int mini=INT_MAX;
          //getting minimum node from n verices
          for(int i=1;i<=n;i++){
              if(mst[i]==false && key[i]<mini){
                  mini=key[i];
                  current=i;
              }
          }
              mst[current]=1;
              //checking its neighbours and add its to parent and keys
              for(auto neighbour : adj[current]){
                  int v=neighbour.first;
                  int w=neighbour.second;
                  
                  if(w<key[neighbour.first] && mst[v]==false){
                      parent[v]=current;
                      key[v]=w;
                  }
              }
          
      }
     //now parent array is ready
    vector<pair<pair<int, int>, int>> spanTree;
            for(int i=2;i<=n;i++){
                
                int w=key[i];
                spanTree.push_back({{parent[i],i},w});
            }
            return spanTree;
            
}












#include <bits/stdc++.h> 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{ 
    vector<pair<int, int>> adj[n+1];
    for(auto it: g){
        adj[it.first.first].push_back({it.first.second, it.second});
        adj[it.first.second].push_back({it.first.first, it.second});
    }
     priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
        vector<int> vist(n+1, 0);
        vector<pair<pair<int, int>, int>> mst;
        // {wt, node}
        pq.push({{0, 1}, -1}); 
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first.first;
            int node = it.first.second;
            int parent = it.second;
            
            if(vist[node] == 1) continue; // if already visisted
            vist[node] = 1; // else mark it visited only after popping out of the min-heap
            if(parent != -1) mst.push_back({{parent, node}, wt});
            // sum += wt; // add the edge weight to sum
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgwt = it.second;
                
                if(!vist[adjNode])
                    pq.push({{edgwt, adjNode}, node});
            }
        }
        
        return mst;
}