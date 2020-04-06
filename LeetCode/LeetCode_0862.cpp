class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        deque<int> Q;
        vector<int> V(n + 1);
        for(int i = 0; i < n; i++)
            V[i + 1] = V[i] + A[i];

        int ans = n + 1;
        for(int i = 0; i <= n; i++){
            while(!Q.empty() && V[i] <= V[Q.back()])
                Q.pop_back();
            while(!Q.empty() && V[i] >= V[Q.front()] + K){
                ans = min(ans, i - Q.front());
                Q.pop_front();
            }
            Q.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};