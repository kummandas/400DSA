/*class Solution
{   
    priority_queue<double> first;
    priority_queue<double, vector<double>, greater<double>> second;
    
    public:
    void insertHeap(int &x) {
        // make sure that first will take only small elements 
        // and if this will create unbalanced sizes then balanceHeaps() will
        // take care of this and send the smallest element from second heap to 
        // first and thus both heaps will have equal/mid elements and there 
        // top will give the medians :)
        
        if(first.size() == 0 || first.top() > x) first.push(x);
        else second.push(x);
        
        balanceHeaps();
    }
    
    void balanceHeaps() {
        if(first.size() > second.size() + 1) {
            second.push(first.top()); first.pop();
            
        } else if(second.size() > first.size()) {
            first.push(second.top()); second.pop();
        }
    }
    
    //Function to return Median.
    double getMedian() {
        double median;
        
        if(first.size() == second.size()) {
            median = (first.top() + second.top()) / 2.0;
        } else {
            median = first.top();
        }
        
        return median;
    }
};
 */











// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of stream of data
void streamMed(int A[], int n)
{
	// Declared two max heap
	priority_queue<int> g, s;

	for (int i = 0; i < n; i++) {
		s.push(A[i]);
		int temp = s.top();
		s.pop();
	
		// Negation for treating it as min heap
		g.push(-1 * temp);
		if (g.size() > s.size()) {
			temp = g.top();
			g.pop();
			s.push(-1 * temp);
		}
		if (g.size() != s.size())
			cout << (double)s.top() << "\n";
		else
			cout << (double)((s.top() * 1.0
							- g.top() * 1.0)
							/ 2)
				<< "\n";
	}
}

// Driver code
int main()
{
	int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int N = sizeof(A) / sizeof(A[0]);

	// Function call
	streamMed(A, N);
	return 0;
}
