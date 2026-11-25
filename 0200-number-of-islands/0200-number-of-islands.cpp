class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[r][c] = 1;
        int m = grid.size();
        int n = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int islands = 0;  
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(i, j, vis, grid);
                }
            }
        }
         return islands;
    }
};