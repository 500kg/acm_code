class Solution {
public:
    int fx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int fy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0, cnt; j < m; j++){
                cnt = 0;
                for(int k = 0, tx, ty; k < 8; k++){
                    tx = i + fx[k];
                    ty = j + fy[k];
              //      cout<<i<<' '<<j<<' '<<tx<<' '<<ty<<endl;
                    if(ok(tx, ty, n, m))
                        cnt += board[tx][ty]&1;
                }
                if(cnt == 3 || (cnt == 2 && board[i][j]&1))
                    board[i][j] |= 2;
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (board[i][j] &= 2) >>= 1;
    }

    inline bool ok(int &x, int &y, int &n, int &m){
        if(x < 0 || y < 0) return 0;
        if(x >= n || y >= m) return 0;
        return 1;
    }
};