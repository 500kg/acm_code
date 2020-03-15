class Solution {
public:
    int n, m;
    int fx[4] = {-1, 0, 1, 0}, fy[4] = {0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int ret = 0;
                    dfs(i, j, ret, grid);
                    ans = max(ans, ret);
                }
            }
        }
        return ans;
    }
    bool ok(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0) return 0;
        if(x >= n || y >= m) return 0;
        return grid[x][y];
    }

    void dfs(int x,int y, int &ans, vector<vector<int>>& grid){
        ans++;
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int tx = x + fx[i], ty = y + fy[i];
            if(ok(tx, ty, grid))
                dfs(tx, ty, ans, grid);
        }
    }
};