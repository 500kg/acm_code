class Solution {
public:
int tmp;
    int movingCount(int m, int n, int k) {
        int ans = 0;
        vector<vector<int> > v(n + 5, vector<int>(m + 5));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                v[i][j] = check(i, j, k); 
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(v[i][j]){
                    tmp = 0;
                    dfs(i, j, n, m, v);
                    ans = max(ans, tmp);
                }
                    
        return ans;
    }
    inline int check(int a, int b, int c){
        return a/10 + a%10 + b/10 + b%10 <= c;
    }

    void dfs(int x, int y, int n, int m, vector<vector<int> > &v){
        if(x < 0 || y < 0 || x >= n || y >= m || v[x][y] == 0) return;
        tmp++;
        v[x][y] = 0;
        dfs(x, y + 1, n, m, v);
        dfs(x + 1, y, n, m, v);
    }
};