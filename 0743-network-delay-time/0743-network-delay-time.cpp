class Solution {
public:
int max=INT_MIN;
void adjacency_list(unordered_map <int,list<pair<int,int>>> &adj, vector<vector<int>>& times) {
    for(int i=0; i<times.size(); i++) {
        int u=times[i][0];
        int v=times[i][1];
        int t=times[i][2];
        adj[u].push_back({v,t});
    }
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map <int,list<pair<int,int>>> adj;
        adjacency_list(adj,times);
        vector<int> dist(n+1,INT_MAX);
        set<pair<int,int>> st;
        st.insert({0,k});
        dist[k]=0;
        while(!st.empty()) {
            pair front=*st.begin();
            st.erase(st.begin());
            int node=front.second;
            int time=front.first;
            for(auto neighbour: adj[node]) {
                int v=neighbour.first;
                int t=neighbour.second;
                int sum=time+t;
                if(sum<dist[v]) {
                    if(dist[v]!=-1) {
                        st.erase({dist[v],v});
                    }
                    dist[v]=sum;
                    st.insert({dist[v],v});
                }
            }
        }
        for(int i = 1; i < dist.size(); i++) {
    if(dist[i] == INT_MAX) {
        return -1;
    }
    if(dist[i] > max) {
        max = dist[i];
    }
}

return max;
    }
};