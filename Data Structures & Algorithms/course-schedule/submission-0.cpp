class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //how about we use kahn's ( toposort using bfs)
        vector<vector<int>> adj(n);
         
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> topo;

        vector<int> inDegree(n, 0);

        for(int i =0; i<n; i++)
            for(auto it: adj[i])
                inDegree[it]++;
        
        queue<int> q;
        for(int i =0; i<n; i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                if(--inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo.size() == n;
    }
};
