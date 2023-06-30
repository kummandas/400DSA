/*class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        //implementing MinHeap using priority queue.
        priority_queue<long long, vector<long long>, greater<long long> > pq(
            arr, arr + n);
    
        long long res = 0;
    
        //using a loop while there is more than one element in priority queue.
        while (pq.size() > 1) 
        {
            //storing the first and second numbers from priority queue.
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
    
            //adding their sum in result.
            res += first + second;
            
            //pushing the sum of first and second numbers in priority queue.
            pq.push(first + second);
        }
        //returning the result.
        return res;
    }
};*/







/*class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        multiset<long long> ms;
        for(int i=0;i<n;i++) {
            ms.insert(arr[i]);
        }
        long long ans=0;
        while(ms.size() > 1) {
            auto it = ms.begin();
            long long cost = *it;
            ms.erase(it);
            it = ms.begin();
            cost += *it;
            ms.erase(it);
            ms.insert(cost);
            ans += cost;
        }
        return ans;
    }
};*/