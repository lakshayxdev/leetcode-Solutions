class Solution {
public:
void adjacency_list(unordered_map<int,list<int>> &adj, vector<vector<int>>& edges,vector<int> &indegree) {
    for(int i=0; i<edges.size(); i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        indegree[v]++;
    }
}

void check_zero_indegree(vector<int> &indegree, int n, vector<int> &ans) {
    for(int i=0; i<n; i++) {
        if(indegree[i]==0) {
            ans.push_back(i);
        }
    }
}
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        unordered_map<int,bool> visited;
        vector<int> ans;
        vector<int> indegree(n,0);
        stack<int> st;
        adjacency_list(adj,edges, indegree);
        check_zero_indegree(indegree,n,ans);
        return ans;
    }
};