class Solution {
public:
    void adjacency_list(unordered_map<int, list<pair<int,int>>> &adj,
                        vector<vector<int>>& flights) {

        for (auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int c = f[2];

            adj[u].push_back({v, c});
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, list<pair<int,int>>> adj;
        adjacency_list(adj, flights);

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // cost, node, edgesUsed
        pq.push({0, src, 0});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {

            auto [c, u, stop] = pq.top();
            pq.pop();

            if (u == dst) return c;

            for (auto [v, cost] : adj[u]) {

                int newStop = stop + 1;
                int newCost = c + cost;

                if (newStop <= k + 1 &&
                    newCost < dist[v][newStop]) {

                    dist[v][newStop] = newCost;
                    pq.push({newCost, v, newStop});
                }
            }
        }

        return -1;
    }
};