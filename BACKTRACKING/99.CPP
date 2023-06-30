/*bool canColor (vector<vector<int>> &mat,vector<int>&paint , int n  , int color , int m , int node  ){
    
    //check if all relatives are not of color (color)
   
    for ( int i=0; i<n; i++){
        if(i!=node  and mat[node][i]==1 and paint[i]==color)return false;
    }
    //no error 
    return true;
    

 bool recur(vector<vector<int>> &mat, vector<int>& paint , int n , int m, int start){
     
     // when to break;
     if(start==n)return true;
     
     //try this node with  any possible color 
     
     for( int i=1; i<=m ; i++){
         //if possible to color 
         if( canColor( mat,paint ,n,i, m,start)){
             //paint that sh*t
             paint[start]=i;
             //check if others accept that rhythm
             if(recur ( mat, paint , n , m , start+1))return true;
             //else you painted the wrong bro, leave that unpaint
             paint[start]=0;
         }
         
       
        
     } 
       // no true return  in any color combination with any node :)
      return false;
 }
string graphColoring(vector<vector<int>> &mat, int m) {
//     if(m>=3)return "YES";
    int n = mat.size();
    int start=0;
    vector<int>paint(n,0);
    if(recur(mat,paint , n,m , start))return "YES";
    return "NO";
   
}

*/


/*class Solution{
public:
    bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
        // checking if the connected nodes to v have same colour as c.
        for (int i = 0; i < V; i++)
            if (graph[v][i] && c == color[i]) return false;
    
        // returning true if no connected node has same colour.
        return true;
    }
    
    bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v,
                           int V) {
        // if all vertices have been assigned colour then we return true.
        if (v == V) return true;
    
        for (int c = 1; c <= m; c++) {
            // checking if this colour can be given to a particular node.
            if (isSafe(v, graph, color, c, V)) {
                // assigning colour to the node.
                color[v] = c;
    
                // calling function recursively and checking if other nodes
                // can be assigned other colours.
                if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                    // returning true if the current allocation was successful.
                    return true;
    
                // if not true, we backtrack and remove the colour for that node.
                color[v] = 0;
            }
        }
        // if no colour can be assigned, we return false.
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int *color = new int[n];
        for (int i = 0; i < n; i++) color[i] = 0;
    
        // checking if colours can be assigned.
        if (graphColoringUtil(graph, m, color, 0, n) == false) {
            return false;
        }
    
        return true;
    }
};*/














// C++ program for solution of M
// Coloring problem using backtracking

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

/* A utility function to check if
the current color assignment
is safe for vertex v i.e. checks
whether the edge exists or not
(i.e, graph[v][i]==1). If exist
then checks whether the color to
be filled in the new vertex(c is
sent in the parameter) is already
used by its adjacent
vertices(i-->adj vertices) or
not (i.e, color[i]==c) */
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;

	return true;
}

/* A recursive utility function
to solve m coloring problem */
bool graphColoringUtil(bool graph[V][V], int m, int color[],
					int v)
{

	/* base case: If all vertices are
	assigned a color then return true */
	if (v == V)
		return true;

	/* Consider this vertex v and
	try different colors */
	for (int c = 1; c <= m; c++) {

		/* Check if assignment of color
		c to v is fine*/
		if (isSafe(v, graph, color, c)) {
			color[v] = c;

			/* recur to assign colors to
			rest of the vertices */
			if (graphColoringUtil(graph, m, color, v + 1)
				== true)
				return true;

			/* If assigning color c doesn't
			lead to a solution then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to
	this vertex then return false */
	return false;
}

/* This function solves the m Coloring
problem using Backtracking. It mainly
uses graphColoringUtil() to solve the
problem. It returns false if the m
colors cannot be assigned, otherwise
return true and prints assignments of
colors to all vertices. Please note
that there may be more than one solutions,
this function prints one of the
feasible solutions.*/
bool graphColoring(bool graph[V][V], int m)
{

	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	// Print the solution
	printSolution(color);
	return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for (int i = 0; i < V; i++)
		cout << " " << color[i] << " ";

	cout << "\n";
}

// Driver code
int main()
{

	/* Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};

	// Number of colors
	int m = 3;

	// Function call
	graphColoring(graph, m);
	return 0;
}

// This code is contributed by Shivani
