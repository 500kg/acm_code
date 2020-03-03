class Solution {
public:
//好多坑
    int myAtoi(string str) {
        bool flag = false;
        int i = 0;
        while(str[i] == ' ')i++;
        if(str[i] == '-') flag = 1, i++;
        else if(str[i] == '+') flag = 0, i++;
        long long ans = 0;
        for(;i < str.length(); i++){
            if(isdigit(str[i]))
                ans = ans*10 + str[i] - '0';
            else
                break;
            if(ans > (1LL<<32)) break;
        }
        ans = flag ? -ans : ans;
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;
        return ans;
    }
};