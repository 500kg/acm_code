class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<int, long long> M;
        std::mt19937 rand(time(0));
        for(int i = 0; i < 26; i++){
            M[i] = rand();
     
        }
	    vector<pair<long long, string> > V;
        for(auto &v : strs){
            long long tmp = 0;
            for(int i = 0; i < v.length(); i++)
                tmp += M[v[i] - 'a'];
            V.push_back(make_pair(tmp, v));
        }
        sort(V.begin(), V.end());
        long long pre = V[0].first;
        vector<string> tmp;
        tmp.push_back(V[0].second);
        for(int i = 1; i < V.size(); i++){
      //      cout<<V[i].first<<' '<<V[i].second<<endl;
            if(V[i].first == pre)
                tmp.push_back(V[i].second);
            else{
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(V[i].second);
                pre = V[i].first;
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};