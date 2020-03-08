class Solution {
public:
    char ans[2000050];
    int k;
     bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0, r = s.length() - 1;
        while(l < r){
            while(!isalnum(s[l])) l++;
            while(!isalnum(s[r])) r--;
            if(s[l] != s[r])
                return false;
            l++, r--;
        }
         return true;
    }
};