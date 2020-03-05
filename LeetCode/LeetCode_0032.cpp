class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ans = 0;
        if(n == 0) return 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < s.length(); i++){
            if(s[i] == ')'){
                int j = i - dp[i - 1] - 1;
                if(j >= 0 && s[j] == '(')
                    dp[i] = i - j + 1 + ((j - 1) >= 0 ? dp[j - 1] : 0);
            }
            else 
                dp[i] = 0;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};