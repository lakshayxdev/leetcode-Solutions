class Solution {
public:
void adjacency_list(unordered_map <int,list<pair<int,int>>> &adj, vector<vector<int>>& edges) {
    for(int i=0; i<edges.size(); i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}

void runDijkstra(int src, vector<int> &dist, int distanceThreshold, int count, vector<int> &ans, unordered_map <int,list<pair<int,int>>> &adj) {
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()) {
        auto it=pq.top();
        pq.pop();
        int distance=it.first;
        int node=it.second;
       if(distance > dist[node]) continue; 
       for(auto it : adj[node])  { 
        int v = it.first;
         int d = it.second;
          int sum = distance + d;
           if(dist[v] > sum) {
             dist[v] = sum;
              pq.push({sum, v});
               } 
               }
    }
    for(int i=0; i<dist.size(); i++) {
        if(i!=src && dist[i]<=distanceThreshold) {
            count++;
        }
    }
    ans[src]=count;
}

int find_mini(vector<int> given, int mini) {
    for(int i=0; i<given.size(); i++) {
        mini=min(mini,given[i]);
    }
    return mini;
}

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map <int,list<pair<int,int>>> adj;
        vector<int> final_ans;
        vector<int> ans(n);
       adjacency_list(adj,edges); 
       for(int i=0; i<n; i++) {
        vector<int> dist(n,INT_MAX);
        runDijkstra(i,dist,distanceThreshold,0,ans,adj);
       }

       int mini=find_mini(ans,INT_MAX);

       for(int i=0; i<ans.size(); i++) {
        if(ans[i]==mini) {
           final_ans.push_back(i); 
        }
       }
       return final_ans.back();

    }
};