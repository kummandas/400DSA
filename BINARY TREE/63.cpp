// A C++ Program to check whether a graph is tree or not
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array for adjacency lists
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isTree(); // returns true if graph is tree
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Add v to w’s list.
}

// A recursive function that uses visited[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		// If an adjacent is not visited, then recur for
		// that adjacent
		if (!visited[*i])
		{
		if (isCyclicUtil(*i, visited, v))
			return true;
		}

		// If an adjacent is visited and not parent of current
		// vertex, then there is a cycle.
		else if (*i != parent)
		return true;
	}
	return false;
}

// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
	// Mark all the vertices as not visited and not part of
	// recursion stack
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// The call to isCyclicUtil serves multiple purposes.
	// It returns true if graph reachable from vertex 0
	// is cyclic. It also marks all vertices reachable
	// from 0.
	if (isCyclicUtil(0, visited, -1))
			return false;

	// If we find a vertex which is not reachable from 0
	// (not marked by isCyclicUtil(), then we return false
	for (int u = 0; u < V; u++)
		if (!visited[u])
		return false;

	return true;
}

// Driver program to test above functions
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isTree()? cout << "Graph is Tree\n":
				cout << "Graph is not Tree\n";

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.isTree()? cout << "Graph is Tree\n":
				cout << "Graph is not Tree\n";

	return 0;
}













 /*
    Time Complexity  : O(N + M)
    Space Complexity : O(N + M)

    Where N is the total number of nodes and M is the total number of edges in the graph.
*/

#include <queue>

// BFS function to detect cycle in graph
bool bfs(vector<vector<int>> &graph, vector<bool> &visited)
{
    int n = graph.size();
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (q.empty() == false)
    {
        int curNode = q.front();
        q.pop();

        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int neighbour = graph[curNode][i];
            if (visited[neighbour] == true)
            {
                if (parent[curNode] != neighbour)
                {
                    return true;
                }
            }
            else
            {
                parent[neighbour] = curNode;
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return false;
}

bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    bool answer = 1;

    // Build adjacency list graph
    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0], v = edgeList[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Check for presence of cycle using bfs
    if (bfs(graph, visited) == true)
    {
        answer = false;
    }

    // Check for multiple connected components
    for (int node = 0; node < n; node++)
    {
        if (visited[node] == false)
        {
            answer = false;
            break;
        }
    }

    return answer;
} 