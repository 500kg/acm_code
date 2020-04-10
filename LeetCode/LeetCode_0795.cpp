class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int r = -1, result = 0;
        vector<int> dp(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                dp[i] = 0;
                r = i;
            } else if (A[i] < L) {
                if (!i) dp[i] = 0;
                else dp[i] = dp[i-1];
            } else {
                dp[i] = i - r;
            }
            result += dp[i];
        }
        return result;
    }
};
