// A C++ program to find floor(sqrt(x)
/*
#include <bits/stdc++.h>
using namespace std;

// Returns floor of square root of x
int floorSqrt(int x)
{
	// Base cases
	if (x == 0 || x == 1)
		return x;

	// Starting from 1, try all numbers until
	// i*i is greater than or equal to x.
	int i = 1, result = 1;
	while (result <= x) {
		i++;
		result = i * i;
	}
	return i - 1;
}

// Driver program
int main()
{
	int x = 11;
	cout << floorSqrt(x) << endl;
	return 0;
}
Time Complexity: O(√X). Only one traversal of the solution is needed, so the time complexity is O(√X).
Auxiliary Space: O(1).


#include <iostream>

using namespace std;
int floorSqrt(int x)
{
	// Base cases
	if (x == 0 || x == 1)
		return x;

	// Do Binary Search for floor(sqrt(x))
	int start = 1, end = x / 2, ans;
	while (start <= end) {
		int mid = (start + end) / 2;

		// If x is a perfect square
		int sqr = mid * mid;
		if (sqr == x)
			return mid;

		// Since we need floor, we update answer when
		// mid*mid is smaller than x, and move closer to
		// sqrt(x)

		/*
		if(mid*mid<=x)
				{
						start = mid+1;
						ans = mid;
				}
			Here basically if we multiply mid with itself so
		there will be integer overflow which will throw
		tle for larger input so to overcome this
		situation we can use long or we can just divide
			the number by mid which is same as checking
		mid*mid < x

		*/
    /*
		if (sqr <= x) {
			start = mid + 1;
			ans = mid;
		}
		else // If mid*mid is greater than x
			end = mid - 1;
	}
	return ans;
}

// Driver program
int main()
{
	int x = 11;
	cout << floorSqrt(x) << endl;
	return 0;
}
Time Complexity: O(log(X)). 
Auxiliary Space: O(1).


#include <bits/stdc++.h>
using namespace std;
int countSquares(int x)
{
	int sqr = sqrt(x);
	int result = (int)(sqr);
	return result;
}
int main()
{

	int x = 9;
	cout << (countSquares(x));

	return 0;
}

// This code is contributed by Rajput-Ji
*/
// C++ code to implement the above approach
#include <iostream>
// header file for math functions
#include <cmath>

using namespace std;
int findSquareRoot(int x)
{
	// using exponential and logarithmic function to
	// calculate square root of x
	double result = exp(log(x) / 2);
	// floor function to get integer part of the result
	int floorResult = floor(result);

	// If the integer square of the floor result is equal to
	// the input x,
	// then x is a perfect square, and floor result is the
	// square root.
	if (floorResult * floorResult == x) {
		return floorResult;
	}
	else { // If not, then x is not a perfect square, and
		// floor result is the floor of the square root.
		return floorResult;
	}
}

// Driver code
int main()
{
	int x = 11;
	int squareRoot = findSquareRoot(
		x); // calling the findSquareRoot function to
			// calculate the square root

	cout << squareRoot << endl; // printing the result

	return 0;
}
/* This code is contributed by Veerendra_Singh_Rajpoot
Time Complexity: O(1), The time complexity of the given approach is O(1) since it uses only one mathematical formula exp(log(x) / 2) which is constant time, and a few arithmetic operations, comparisons, and function calls that take constant time as well. Therefore, the time complexity of this algorithm is constant or O(1).
Auxiliary Space: O(1), The space complexity of the given approach is O(1) as it only uses a constant amount of extra space. It declares two integer variables, result and floorResult, which each take constant space, and there is no dynamic memory allocation or recursive calls. Therefore, the space complexity of this algorithm is constant or O(1).
*/
