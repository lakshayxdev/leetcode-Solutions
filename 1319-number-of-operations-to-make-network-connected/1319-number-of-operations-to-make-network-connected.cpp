class Solution {
public:
int findUParent (vector<int> &parent, int node) {
    if(parent[node]==node) {
        return node;
    }
    return findUParent(parent, parent[node]);
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    int U=findUParent(parent,u);
	int V=findUParent(parent,v);
	if(rank[U]<rank[V]) {
		parent[U]=V;
		
	}
	else if(rank[V]<rank[U]) {
		parent[V]=U;
		
	}
	else {
		parent[U]=V;
		rank[V]++;
	}
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n);
        int edge=0;
        int component=0;
        for(int i=0; i<n; i++) {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0; i<connections.size(); i++) {
            int u=connections[i][0];
            int v=connections[i][1];
            if(findUParent(parent,u) != findUParent(parent,v)) {
                unionset(u,v,parent,rank);
            }
            else if(findUParent(parent,u) == findUParent(parent,v)) {
                edge++;
            }
        }
        for(int i=0; i<n; i++) {
            if(parent[i]==i) {
                component++;
            }
        }
        if(edge < component-1) {
            return -1;
        }
        return component-1;
    }
};