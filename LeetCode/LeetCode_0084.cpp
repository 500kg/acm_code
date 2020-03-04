class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int ans = 0;
        s.push(-1);
        for(int i = 0; i < h.size(); i++){
            while(s.top() != -1 && h[s.top()] >= h[i]){
                int t = s.top();
                s.pop();
                ans = max(ans, h[t]*(i - s.top() - 1));
            }
            s.push(i);
        }
        while(s.top() != -1){
            int t = s.top();
            s.pop();
            ans = max(ans, (int)(h[t] * (h.size() - 1 - s.top())));
        }
        return ans;
    }
};