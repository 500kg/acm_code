class Solution {
public:
    int romanToInt(string s) {
        map<char, int>M;
        int ans = 0;
        M['I'] = 1;
        M['V'] = 5;
        M['X'] = 10;
        M['L'] = 50;
        M['C'] = 100;
        M['D'] = 500;
        M['M'] = 1000;
        for(int i = 0;i < s.length() - 1; i++){
            if(M[s[i]] < M[s[i + 1]])
                ans -= M[s[i]];
            else 
                ans += M[s[i]];
        }
        ans += M[s[s.length() - 1]];
        return ans;
    }
};