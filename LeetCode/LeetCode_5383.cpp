class Solution {
public:
    long long dp[5005][15];
    bool ma[13][13];
    
    const int MOD = 1e9 + 7;
    int numOfWays(int n) {
        vector<string>s(13, "");
        s[1] = "121"; s[2] = "212"; s[3] = "312";
        s[4] = "123"; s[5] = "213"; s[6] = "313";
        s[7] = "131"; s[8] = "231"; s[9] = "321";
        s[10] ="132"; s[11] = "232";s[12] ="323";
    //    cout<<"FF"<<endl;
        for(int i = 1; i <= 12; i++)
            for(int j = 1; j <= 12; j++){
                ma[i][j] = 1;
                for(int k = 0; k <= 2; k++)
                    if(s[i][k] == s[j][k]) ma[i][j] = 0;
            }
   //     cout<<"DD"<<endl;
        for(int i = 1; i <= 12; i++) dp[1][i] = 1;
        for(int i = 2; i <= n; i++){
            for(int k = 1; k <= 12; k++)
                for(int j = 1; j <= 12; j++)
                    if(ma[j][k])
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) %MOD;
            
        }
        int ans = 0;
        for(int i = 1;  i <= 12; i++) ans = (ans + dp[n][i]) %MOD;
        return ans;
    }
};