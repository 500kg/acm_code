class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = (numRows - 1)*2;
        string ans;
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < s.length(); j+=n){
                ans += s[j];
                if(i > 0 && i < numRows - 1 && j + n - 2*i < s.length())
                    ans += s[j + n - 2*i];
            }
        }
        return ans;
    }
};