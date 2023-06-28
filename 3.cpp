class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int,  vector<int>, greater<int>> pq;
        for(int i=l; i<=r; i++){
            pq.push(arr[i]);
        }
        
        for(int i=l; i<k-1; i++){
            pq.pop();
        }
        
        return pq.top();
    }
};