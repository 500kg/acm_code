class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.empty()) return ans;
        int len = INT_MAX;
        for(auto &v : strs)
            len = min(len, (int)v.length());
        for(int i = 0; i < len; i++){
            bool flag = true;
            for(int j = 1; j < strs.size(); j++)
                if(strs[j][i] != strs[0][i])
                    flag = false;
            if(flag) ans += strs[0][i];
            else break;
        }
        return ans;
    }
};