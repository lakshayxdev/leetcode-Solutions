class Solution {
public:
// 1 --> RED
// 0 --> BLUE
// -1 --> NO COLOR
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
    if(color[i] == -1) {
        color[i] = 1;
        q.push(i);
    }
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            if(color[node]==-1) { // starting node
                color[node]= 1;
            }
           for(int neighbour: graph[node]) {
            if(color[neighbour]==-1) {      // if neighbour has no color
               if(color[node] == 1) {
                  color[neighbour] = 0;
              } 
              else {
                color[neighbour] = 1;
              }
              q.push(neighbour);
            }              
            else if (color[node]==color[neighbour]) {   // if neighbour has same color
            return false;
            }
           }
        }
        }
        
        return true;
    }
};