class Solution {
public:
    int n, m;
    bool isValid(int x, int y){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& vis, vector<vector<int>>& heights){
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        while(!q.empty()){
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr, nc) && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> visP(n, vector<bool>(m, false)), visA(n, vector<bool>(m, false));
        queue<pair<int, int>> qp, qa;

        for(int i = 0; i<n; i++){
            qp.push({i, 0});
            visP[i][0] = true;
            qa.push({i, m-1});
            visA[i][m-1] = true;
        }
        for(int j = 0; j<m; j++){
            qp.push({0, j});
            visP[0][j] = true;
            qa.push({n-1, j});
            visA[n-1][j] = true;
        }

        bfs(qp, visP, heights);
        bfs(qa, visA, heights);

        vector<vector<int>> res;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(visA[i][j] && visP[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
