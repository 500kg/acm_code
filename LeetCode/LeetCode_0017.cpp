class Solution {
public:
    char ch[10][5] = {{},{},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()) return ans;
        string tmp;
        dfs(0, ans, tmp, digits);
        return ans;
    }

    void dfs(int pos, vector<string> &ans, string tmp, string &digits){
        if(pos == digits.length()){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; ch[digits[pos] - '0'][i]; i++){
            dfs(pos + 1, ans, tmp + ch[digits[pos] - '0'][i], digits);
        }
    }
};