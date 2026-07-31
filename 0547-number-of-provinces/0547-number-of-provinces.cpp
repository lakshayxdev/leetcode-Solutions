class Solution {
public:

void adjacency_list(unordered_map <int,list<int>> &adj, vector<vector<int>>& isConnected) {
    for(int i = 0; i < isConnected.size(); i++) {
    for(int j = 0; j < isConnected.size(); j++) {
        if(i != j && isConnected[i][j] == 1) {
            adj[i].push_back(j);
        }
    }
}
}

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited) {
    visited[node]=true;
    for(int neighbour:adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour,adj,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>> adj;
        adjacency_list(adj,isConnected);
        unordered_map<int,bool> visited;
        int count=0;
        for(int i=0; i<isConnected.size(); i++) {
            if(!visited[i]) {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;

    }
};