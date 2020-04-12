class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j) continue;
                if(words[i].find(words[j]) != words[i].npos)
                    ans.push_back(words[j]);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};