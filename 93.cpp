//returns square
/*
    double sq(double x){
        return x*x;
    }
    //calculates y according to x using line equation
    double calcY(double x, tuple<int,int,int>l){
        return -1*(double(get<2>(l) + (double)(get<0>(l)*x))/get<1>(l));
    }
    //calculates sum of distances between selected x and y
    //and the list of points given
    double calcDist(double x, double y, vector<pair<int,int>> p, int n){
        double dist = 0;
        for(int i=0; i<n; i++){
            dist += sqrt(sq((double)p[i].first-x)+sq((double)p[i].second-y));
        }
        return dist;
    }
    public:
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    //Write your code here
	    if(get<1>(l) == 0)
	        return (double)1/0;
	    double low = -1000;
	    double high = 1000;
	    double ans = INT_MAX;
	    //O(logn) for binary search
	    while(high-low >= 0.000001){
	        double midX = low +(high-low)/2;
	        double midY = calcY(midX,l);
	        //O(n) for calcDist
	        double tmpAns = calcDist(midX,midY,p,n);
	        ans = min(ans,tmpAns);
	        //decide where to go next
	        //one point has the min value so deviation from that point
	        //increases the distance sum
	        //therefore the distace sum is first decreasing
	        //reaches minimum
	        //and then increases on the x-scale
	        //so take a point after selected x and y
	        //if dist increases, we need to reduce x
	        //else increase x
	        double newMidX = midX+0.001;
	        double newMidY = calcY(newMidX,l);
	        double newtmpAns = calcDist(newMidX,newMidY,p,n);
	        
	        if(newtmpAns > tmpAns){
	            high = midX;
	        }else{
	            low = midX;
	        }
	    }
	    return ans;
    }

};

        */

//  C/C++ program to find optimum location and total cost
#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x) * (x))
#define EPS 1e-6
#define N 5

//  structure defining a point
struct point {
    int x, y;
    point() {}
    point(int x, int y)
        : x(x)
        , y(y)
    {
    }
};

//  structure defining a line of ax + by + c = 0 form
struct line {
    int a, b, c;
    line(int a, int b, int c)
        : a(a)
        , b(b)
        , c(c)
    {
    }
};

//  method to get distance of point (x, y) from point p
double dist(double x, double y, point p)
{
    return sqrt(sq(x - p.x) + sq(y - p.y));
}

/*  Utility method to compute total distance all points
    when choose point on given line has x-coordinate
    value as X   */
double compute(point p[], int n, line l, double X)
{
    double res = 0;

    //  calculating Y of chosen point by line equation
    double Y = -1 * (l.c + l.a * X) / l.b;
    for (int i = 0; i < n; i++)
        res += dist(X, Y, p[i]);

    return res;
}

//  Utility method to find minimum total distance
double findOptimumCostUtil(point p[], int n, line l)
{
    double low = -1e6;
    double high = 1e6;

    // loop until difference between low and high
    // become less than EPS
    while ((high - low) > EPS) {
        // mid1 and mid2 are representative x co-ordiantes
        // of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        //
        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);

        // if mid2 point gives more total distance,
        // skip third part
        if (dist1 < dist2)
            high = mid2;

        // if mid1 point gives more total distance,
        // skip first part
        else
            low = mid1;
    }

    // compute optimum distance cost by sending average
    // of low and high as X
    return compute(p, n, l, (low + high) / 2);
}

//  method to find optimum cost
double findOptimumCost(int points[N][2], line l)
{
    point p[N];

    //  converting 2D array input to point array
    for (int i = 0; i < N; i++)
        p[i] = point(points[i][0], points[i][1]);

    return findOptimumCostUtil(p, N, l);
}

//  Driver code to test above method
int main()
{
    line l(1, -1, -3);
    int points[N][2] = {
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    cout << findOptimumCost(points, l) << endl;
    return 0;
}

