class Solution {
public:
void adjacency_list(vector<vector<int>>& prerequisites, unordered_map<int,list<int>> &adj) {
    for(int i=0; i<prerequisites.size(); i++) {
        int u=prerequisites[i][0];
        int v=prerequisites[i][1];
        adj[u].push_back(v);
    }
}

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,list<int>> adj;
        adjacency_list(prerequisites, adj);

         queue<int> q;
    vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
    for(int source=0; source<numCourses; source++) {
        vector<bool> visited(numCourses,false);
          visited[source]=true;
          q.push(source);
          isReachable[source][source]=true;
          while(!q.empty()) {
            int front=q.front();
            q.pop();
            for(int neighbour: adj[front]) {
                if(!visited[neighbour]) {
                    visited[neighbour]=true;
                    q.push(neighbour);
                    isReachable[source][neighbour]=true;
                }
            }
          }
    }
     vector<bool> ans;
          for(auto &query:queries) {
            ans.push_back(  isReachable[query[0]][ query[1]] );
          }
          return ans;
          
    }
   
};