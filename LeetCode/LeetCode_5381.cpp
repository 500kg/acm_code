class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> V(m + 1, 0);
        vector<int> ans;
        for(int i = 0; i < m; i++) V[i] = i + 1;
        for(auto &v: q){
            int pos = 0;
            while(V[pos] != v) pos++;
            
            ans.push_back(pos);
          
            for(int i = pos; i >= 1; i--) V[i] = V[i - 1];
            V[0] = v;
        }
        return ans;
    }
};