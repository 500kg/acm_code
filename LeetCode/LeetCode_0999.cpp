class Solution {
public:
    int ans = 0;
    bool fak(char c){
        if(c == 'p') ans++;
        if(c == '.') return 0;
        return 1;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int x, y;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 'R')
                    x = i, y = j;
        int cnt = 0;
        for(int i = x - 1; i >= 0; i--){
            if(fak(board[i][y]))
                break;
        }
        for(int i = x + 1; i < n; i++){
            if(fak(board[i][y]))
                break;
        }
        for(int i = y - 1; i >= 0; i--){
            if(fak(board[x][i]))
                break;
        }
        for(int i = y + 1; i < m; i++){
            if(fak(board[x][i]))
                break;
        }
        return ans;
    }
};