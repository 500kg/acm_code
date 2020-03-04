class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int res = a[0] + a[1] + a[2];
        for(int i = 0; i < a.size() - 2; i++){
            int l = i + 1, r = a.size() - 1;
            while(l < r){
                int tmp = a[i] + a[l] + a[r];
                if(abs(target - tmp) < abs(target - res)) res = tmp;
                if(tmp < target)
                    l++;
                else if(tmp > target)
                    r--;
                else
                    return res;
            }
        }
        return res;
    }
};