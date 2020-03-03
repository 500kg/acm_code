class Solution {
public:
    int reverse(long long x) {
        long long ans = 0;
        long long flag = 1;
        if(x<0)flag = -1, x = -x;
        while(x){
            ans=ans*10+x%10;
            x/=10;
        }
        ans*=flag;
        if(ans >= INT_MAX || ans <= INT_MIN) return 0;
        return ans;
    }
};