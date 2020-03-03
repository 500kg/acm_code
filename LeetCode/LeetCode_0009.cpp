class Solution {
public:
    bool isPalindrome(long long x) {
        if(x < 0) return 0;
        long long b = x, c = 0;
        while(b){
            c = c*10 + b%10;
            b/=10;
        }
        return x == c;
    }
};