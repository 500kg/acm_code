class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.empty() || p.empty() || s.size() < p.size()) return ans;
        string need(26, 0);
        string have(26, 0);
        
        int l = 0, r = 0, fak = 0;
        while(r < p.length()) have[s[r] - 'a']++, need[p[r++] - 'a']++; r--;
        
        while(r + 1 < s.length()){
            if(need == have)
                ans.push_back(l);
            have[s[++r] - 'a']++;
            have[s[l++] - 'a']--;
        }
        if(need == have)
            ans.push_back(l);
        return ans;
    }
};