class Solution {
public:
void adjacency_list(unordered_map <int,list<int>> &adj, vector<vector<int>>& edges) {
    for(int i=0; i<edges.size(); i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int node, unordered_map <int,list<int>> &adj, unordered_map<int,bool> &visited, vector<int>& component) {
    visited[node]=true;
    component.push_back(node);
    for(int neighbour: adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour,adj,visited, component);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map <int,list<int>> adj;
        adjacency_list(adj,edges);
        unordered_map<int,bool> visited;
        int count=0;
        for(int i=0; i<n; i++) {
            vector<int> component;
            dfs(i,adj,visited,component);
            bool complete=true;
            for(int node:component) {
                if(adj[node].size() != component.size()-1) {
                    complete=false;
                    break;
                }
            }
            if(complete) {
                count++;
            }
        }
        return count;
    }
};