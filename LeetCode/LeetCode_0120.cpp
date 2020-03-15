class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        if(t.size() == 0 || t[0].size() == 0) return 0;
        int n = t.size();
        for(int i = 1; i < n; i++)
            t[i][0] += t[i - 1][0], t[i][i] += t[i - 1][i - 1];
        for(int i = 1; i < n; i++)
            for(int j = 1; j < i; j++)
                t[i][j] += min(t[i - 1][j - 1], t[i - 1][j]);
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < n; i++)
            ans  = min(ans, t[n - 1][i]);
   /*     for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++)
                cout<<t[i][j]<<' ';
                cout<<endl;
        }*/
        return ans;
    }
};