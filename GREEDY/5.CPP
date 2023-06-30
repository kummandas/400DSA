/*class Solution
{
    public:
    static bool comp(Item i1,Item i2){
        double r1=(double)i1.value/(double)i1.weight;
        double r2=(double)i2.value/(double)i2.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans=0.0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=w){
                w=w-arr[i].weight;
                ans=ans+arr[i].value;  
            }
            else{
               ans=ans+(double)w*((double)arr[i].value/(double)arr[i].weight); 
               break;
            }
        }
        return ans;
    }
        
};*/

// C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
    int value, weight;

    // Constructor
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

// Comparison function to sort Item according to val/weight
// ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    //    sorting Item on basis of ratio
    sort(arr, arr + N, cmp);

    double finalvalue = 0.0; // Result (value in Knapsack)

    // Looping through all Items
    for (int i = 0; i < N; i++) {
        // If adding Item won't overflow, add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item, add fractional part
        // of it
        else {
            finalvalue
                += arr[i].value
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

// Driver's code
int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, N);
    return 0;
}










/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(1)

    where N is the number of items.
*/


#include <algorithm>


// Comparator to sort items.
bool compare(pair<int, int>& a, pair<int, int>& b)
{
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}


double maximumValue(vector<pair<int,int>>& items, int n, int w)
{
    // Sort items according to value/weight.
    sort(items.begin(), items.end(), compare);

    double maxValue = 0;
    int currWeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].first <= w)
        {
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else
        {
            int remainingWeight = w - currWeight;

            // Pick a fraction of current item.
            maxValue += items[i].second * ((double)remainingWeight / items[i].first);
            break;
        }
    }

    return maxValue;
}