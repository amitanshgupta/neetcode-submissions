class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[r][c] = true;
        int dr[4] = {0, 1, -1, 0};
        int dc[4] = {1, 0, 0, -1};
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < grid.size() &&
   nc >= 0 && nc < grid[0].size() &&grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(nr, nc, grid, vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
