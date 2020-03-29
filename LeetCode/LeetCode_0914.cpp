class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> M;
        for(auto &v : deck)
            M[v]++;
        int fir = 1, ans;
        for(auto &v: M){
            if(fir) ans = v.second, fir = 0;
            else ans = __gcd(ans, v.second);
        }
        return ans >= 2;
    }
};