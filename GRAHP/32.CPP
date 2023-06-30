class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
        vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};










class Solution {
2
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
3
        Map<Integer, List<int[]>> adj = new HashMap<>();
4
        for (int[] i : flights)
5
            adj.computeIfAbsent(i[0], value -> new ArrayList<>()).add(new int[] { i[1], i[2] });
6
​
7
        int[] stops = new int[n];
8
        Arrays.fill(stops, Integer.MAX_VALUE);
9
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
10
        // {dist_from_src_node, node, number_of_stops_from_src_node}
11
        pq.offer(new int[] { 0, src, 0 });
12
​
13
        while (!pq.isEmpty()) {
14
            int[] temp = pq.poll();
15
            int dist = temp[0];
16
            int node = temp[1];
17
            int steps = temp[2];
18
            // We have already encountered a path with a lower cost and fewer stops,
19
            // or the number of stops exceeds the limit.
20
            if (steps > stops[node] || steps > k + 1)
21
                continue;
22
            stops[node] = steps;
23
            if (node == dst)
24
                return dist;
25
            if (!adj.containsKey(node))
26
                continue;
27
            for (int[] a : adj.get(node)) {
28
                pq.offer(new int[] { dist + a[1], a[0], steps + 1 });
29
            }
30
        }
31
        return -1;
32
    }
33
}