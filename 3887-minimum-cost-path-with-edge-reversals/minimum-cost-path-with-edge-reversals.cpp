class Solution {
public:

    typedef pair<int, int> P;

    int minCost(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<P>> adj;

        for(auto &edge : edges) {

            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt}); 
        }

        vector<int> res(n, INT_MAX);

        res[0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0}); 

        while(!pq.empty()) {

            int d = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();
            if(node == n-1)
                return res[node];

		    for(auto &p : adj[node]) {

                int adjNode = p.first;
                int dist = p.second;

                if(d + dist < res[adjNode]) {
                    res[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
		    }
        }

        return -1;
    }
};