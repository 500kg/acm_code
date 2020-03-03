class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>M;
        int ans = 0, ret = 0, l = 0;
        for(int i = 0; i < s.length(); i++){
            if(M[s[i]]){
                while(s[l] != s[i])
                    M[s[l++]]--, ret--;
                M[s[l++]]--, ret--;
            }
            M[s[i]] = 1, ret++;
            ans = max(ans, ret);
        }
        return ans;
    }
};