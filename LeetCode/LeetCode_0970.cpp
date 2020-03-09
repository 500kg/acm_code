class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        for(int i = 1; i <= bound; i*=x){
            for(int j = 1; j + i <= bound; j*=y){
                ans.push_back(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};