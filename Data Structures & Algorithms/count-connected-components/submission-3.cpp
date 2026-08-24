class DisjointSet{
public:
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n){
        parent.resize(n);
        rank.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findUParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUParent(parent[u]);
    }
    void unionbyrank(int u, int v){
        int parU = findUParent(u);
        int parV = findUParent(v);

        if(parU == parV) return;

        if(rank[parU] < rank[parV]){
            parent[parU] = parV;
        }else if(rank[parV] < rank[parU]){
            parent[parV] = parU;
        }else{
            parent[parV] = parU;
            rank[parU]++;
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto e: edges){
            ds.unionbyrank(e[0], e[1]);
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(ds.findUParent(i) == i) ans++;
        }
        return ans;

    }
};
