class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        int i = 0, cnt = 1;
        vector<int> ans(n, 0);
        while(c){
            int t = min(cnt, c);
            ans[i] += t;
            c -=t, cnt++;
            i = (i + 1)%n;
        }
        return ans;
    }
};