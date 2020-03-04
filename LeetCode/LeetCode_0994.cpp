int fx[] = {-1, 0, 1, 0};
    int fy[] = {0, 1, 0, -1};
    class Solution {
struct node{
        int x, y, t;
        node(int _x, int _y, int _t){
            x = _x; y = _y; t = _t;
        }
};
public:
    int n, m;
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        n = grid.size(), m = grid[0].size();
        return bfs(grid);
    }

    
    bool ok(int x, int y){
        if(x < 0 || y < 0) return 0;
        if(x >= n || y >= m) return 0;
        return 1;
    }
    int bfs(vector<vector<int>>& g){
        queue<node> Q;
        int cnt = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[i].size(); j++){
                if(g[i][j] == 2)
                  Q.push(node{i, j, 0});
                if(g[i][j])
                    cnt++;
            }
        }
        if(cnt == 0)
            return 0;
        while(!Q.empty()){
            node t = Q.front(); Q.pop();
            cnt--;
            if(cnt == 0)
                return t.t;
            for(int i = 0; i < 4; i++){
                node p(t);
                p.x += fx[i], p.y += fy[i], p.t++;
                if(ok(p.x, p.y) && g[p.x][p.y] == 1){
                    g[p.x][p.y] = 2;
                    Q.push(p);
                }
                    
            }
        }
        return -1;
    }
};