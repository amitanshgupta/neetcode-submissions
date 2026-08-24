class Solution {
public:
        void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(n-1 != m) return false;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0, adj, vis);

        for(int i = 0; i<n; i++){
            if(!vis[i])
                return false;
        }
        
        return true;
    }
};
