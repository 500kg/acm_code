class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string ans(n*2, 0);
        vector<string> ret;
        if(n == 0) return ret;
        dfs(ret, ans, 0, n*2, 0);
        return ret;
    }

    void dfs(vector<string> &ret, string &ans, int pos, int len, int cnt){
        if(pos == len){
            ret.push_back(ans);
            return;
        }
        if(cnt > 0){
            ans[pos] = ')';
            dfs(ret, ans, pos + 1, len, cnt - 1);
        }
        if(cnt + pos < len){
            ans[pos] = '(';
            dfs(ret, ans, pos + 1, len, cnt + 1);
        }
        
    }
};