class Solution {
public:
    string stoneGameIII(vector<int>& V) {
        int n = V.size(),sum = 0;
        vector<int> dp(n + 1, -50000000);
        dp[n] = 0;
        for(int i = n  - 1; i >= 0; i--){
            sum += V[i];
            for(int j = i + 1; j <= i + 3 && j <= n; j++){
                dp[i] = max(dp[i], sum - dp[j]);
            }
        }
    //    for(int i = 0; i <= n; i++)cout<<dp[i]<<' ';cout<<endl;
        int a = dp[0], b = sum - dp[0];
        if(a == b) return "Tie";
        else if(a > b) return "Alice";
        else return "Bob";
    }
};