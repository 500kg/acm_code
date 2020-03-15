class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.length();
        vector<long long> v(n + 5, 0);
        v[0] = 1;
        for(int i = 0; i < s.length(); i++){
            for(int j = n - 1; j >= 0; j--){
                if(s[i] == t[j]){
                    v[j + 1] += v[j];
                //    cout<<i<<' '<<j<<' '<<v[j + 1]<<endl;
                }
                    
            }
        }
        return v[n];
    }
};