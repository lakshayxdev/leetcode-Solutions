class Solution {
public:
void adjacency_list(vector<vector<int>>& roads, unordered_map <int,list<pair<int,int>>> &adj) {
    for(int i=0; i<roads.size(); i++) {
        int u=roads[i][0];
        int v=roads[i][1];
        int d=roads[i][2];
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
}
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,
               vector<pair<long long,int>>,
               greater<pair<long long,int>>> pq;
               unordered_map <int,list<pair<int,int>>> adj;
               adjacency_list(roads,adj);
               vector<long long> dist(n, LLONG_MAX);
               dist[0]=0;
               pq.push({0,0});
               vector<int> ways(n,0);
               ways[0]=1;
               while(!pq.empty()) {
                auto it=pq.top();
                pq.pop();
                long long curr_dist=it.first;
                int node=it.second;
                if(curr_dist>dist[node]) {
                    continue;
                }
                for(auto it:adj[node]) {
                    int v=it.first;
                    int d=it.second;
                    long long sum = curr_dist + d;
                    if(dist[v]>sum) {
                        pq.push({sum,v});
                        dist[v]=sum;
                        ways[v]=ways[node];
                    }
                    else if(dist[v]==sum) {
                        const int MOD = 1e9 + 7;
ways[v] = (ways[v] + ways[node]) % MOD;
                    }
                }
               }
               return ways[n-1];
    }
};