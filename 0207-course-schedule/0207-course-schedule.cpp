class Solution {
public:

void adjacency_list(unordered_map<int,list<int>> &adj, vector<vector<int>>& prerequisites, vector<int> &indegree) {
    for(int i=0; i<prerequisites.size(); i++) {
        int v=prerequisites[i][1];
        int u=prerequisites[i][0];
        adj[v].push_back(u);
        indegree[u]++;
    }
}

void topological(vector<int> &indegree, unordered_map<int,list<int>> &adj, queue<int> &q, vector<int> &ans) {
    for(int i=0; i<indegree.size(); i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(int neighbour:adj[front]) {
            indegree[neighbour]--;
            if(indegree[neighbour]==0) {
                q.push(neighbour);
            }
        }
    }
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        adjacency_list(adj,prerequisites, indegree);
        topological(indegree,adj,q,ans);
        return ans.size()==numCourses;
        
    }
};