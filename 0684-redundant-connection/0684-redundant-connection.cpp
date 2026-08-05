class Solution {
public:
int findUParent(int node, vector<int> &parent) {
    if(parent[node]==node) {
        return node;
    }
    return parent[node]=findUParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    int U=findUParent(u,parent);
    int V=findUParent(v,parent);
    if(rank[U]<rank[V]) {
        parent[U]=V;
    }
    else if(rank[V]<rank[U]) {
        parent[V]=U;
    }
    else {
        parent[V]=U;
        rank[U]++;
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        vector<int> ans;
        for(int i=0; i<n; i++) {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0; i<n; i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            if(findUParent(u,parent) != findUParent(v,parent)) {
                unionSet(u,v,parent,rank);
            }
            else if( findUParent(u,parent) == findUParent(v,parent) ) {
                ans.push_back(u);
                ans.push_back(v);
            }
        }
        return ans;
    }
};