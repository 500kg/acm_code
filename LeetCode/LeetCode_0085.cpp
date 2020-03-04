class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        if(M.size() == 0 || M[0].size() == 0) return 0;
        int n = M.size(), m = M[0].size();
        vector<vector<int> > C(n, vector<int>(m));
        for(int i = 0; i < m; i++)
            C[n - 1][i] = M[n - 1][i] - '0';
        for(int i = n - 2; i >= 0; i--)
            for(int j = 0; j < m; j++) 
                C[i][j] = M[i][j] == '0' ? 0 : C[i + 1][j] + 1;
        int ans = 0;
        for(auto &v: C){
            ans = max(ans, maxArea(v));
        }
        return ans;
    }

    int maxArea(vector<int>& matrix) {
        stack<int> s;
        s.push(-1);
        int max_area = 0, height, width;
        for(int i = 0; i < matrix.size(); ++i) {
            while(s.top() != -1 && matrix[i] <= matrix[s.top()]) {
                height = matrix[s.top()];
                s.pop();
                width = i - s.top() - 1;
                max_area = max(max_area, height*width);
            }
            s.push(i);
        }
        while(s.top() != -1) {
            height = matrix[s.top()];
            s.pop();
            width = matrix.size() - s.top() - 1;
            max_area = max(max_area, height*width);
        }
        return max_area;
    }

};