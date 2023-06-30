/*
    Time Complexity: O(N^4)
    Space Complexity: O(N^2),

    where N is the number of nodes.


#include <cmath>

int findDeterminant(vector<vector<int>> Matrix)
{
    // Variable to store the determinant value
    int det = 0;
    if (Matrix.size() == 1)
    {
        return Matrix[0][0];
    }

    else if (Matrix.size() == 2)
    {
        det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
        return det;
    }

    else
    {

        for (int p = 0; p < Matrix[0].size(); p++)
        {
            vector<vector<int>> tempMatrix;
            for (int i = 1; i < Matrix.size(); i++)
            {
                vector<int> row;
                for (int j = 0; j < Matrix[i].size(); j++)
                {
                    if (j != p)
                    {
                        row.push_back(Matrix[i][j]);
                    }

                }

                if (row.size() > 0)
                {
                    tempMatrix.push_back(row);
                }

            }

            det = det + Matrix[0][p] * pow(-1, p) * findDeterminant(tempMatrix);

        }

        return det;
    }

}




int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m)
{

    // Degree of each node will be stored in this
    int degree[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                // Calculating degree of each node
                degree[i]++;
            }

        }

    }

    // Updating the values of primary diagonal with degree of the node
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i][i] = degree[i];
    }

    // Replacing all 1 in the matrix which are not present on primary diagonal with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i != j) and adjMatrix[i][j] == 1)
            {
                adjMatrix[i][j] = -1;
            }

        }

    }

    // Submatrix of size (n-1)*(n-1) in which 1st row and 1st column values will not be there
    vector<vector<int>>submatrix(n - 1, vector<int>(n - 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            submatrix[i - 1][j - 1] = adjMatrix[i][j];
        }

    }

    // This will be the answer as (-1)^(1+1) will be equal to 1 only
    return  findDeterminant(submatrix);
}

*/


#include<bits/stdc++.h>
using namespace std;

// C++ program to find number of spanning
// trees in a graph using Matrix
// Chain Multiplication
#define MAX 100
#define MOD 1000000007

// Matrix Multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;	
}

// Function to find Nth power of A
void power(int A[MAX][MAX], int N, int result[MAX][MAX])
{
	int temp[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			result[i][j] = (i == j);

	while (N>0)
	{
		if (N%2 == 1)
		{
			multiply(A, result, temp);
			for (int i=0; i<MAX; i++)
				for (int j=0; j<MAX; j++)
					result[i][j] = temp[i][j];
		}

		N = N/2;
		multiply(A, A, temp);
		for (int i=0; i<MAX; i++)
			for (int j=0; j<MAX; j++)
				A[i][j] = temp[i][j];
	}
}

// Function to find number of Spanning
// Trees in a Graph using Matrix Chain
// Multiplication.
int numOfSpanningTree(int graph[][MAX], int V)
{
	int result[MAX][MAX] = {0};
	int temp[MAX][MAX] = {0};

	// Create a copy of graph as the
	// Adjacency matrix will be changed
	// during the process
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			temp[i][j] = graph[i][j];

	// Find (V-2)th power of Adjacency
	// matrix
	power(temp, V-2, result);

	int ans = 0;

	// Find sum of all elements in (V-2)th
	// power
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			ans = (ans + result[i][j])%MOD;

	return ans;
}



// Driver program
int main()
{
	// Let us create the following graph
	// 2 <-> 3
	// | |
	// 0 <-1-> 1
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	int graph[][MAX] = {
						{0, 1, 1, 1},
						{1, 0, 1, 1},
						{1, 1, 0, 1},
						{1, 1, 1, 0}
					};

	cout << numOfSpanningTree(graph, V);

	return 0;
}
