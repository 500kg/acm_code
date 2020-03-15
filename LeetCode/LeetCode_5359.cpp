class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> V;
        for(int i = 0; i < n; i++){
            V.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(V.begin(), V.end());
        priority_queue<int, vector<int>, greater<int> > Q;
        long long low = INT_MAX, sum = 0, ans = 0;
        for(int i = n - 1, j = 0; j < k; j++, i--){
       //     cout<<i<<endl;
            low = min(low, 1LL*V[i].first);
            sum += V[i].second;
            Q.push(V[i].second);
            ans = max(ans, low*sum);
        }
        for(int i = n - k - 1; i >= 0; i--){
      //       cout<<i<<endl;
            low = min(low, 1LL*V[i].first);
            if(Q.top() < V[i].second){
                sum += V[i].second - Q.top(); Q.pop();
                Q.push(V[i].second);
            }
            ans = max(ans, low*sum);
            
        }
        return ans%MOD;
    }
};