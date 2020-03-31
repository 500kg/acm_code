class Solution {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        fak(0, nums.size() - 1, nums);
        return nums;
    }

    void fak(int l, int r, vector<int> &nums){
    //    cout<<l <<' '<<r<<endl;
        if(l >= r) return;
        int mid = l + (r - l)/2;
        fak(l, mid, nums); fak(mid + 1, r, nums);
        int L = l, R = mid + 1, now = l;
        while(L <= mid && R <= r){
          //  cout<<L<<' '<<mid<<' '<<R<<' '<<now<<endl;
            if(nums[L] < nums[R])  tmp[now++] = nums[L++];
            else tmp[now++] = nums[R++];
        }
        while(L <= mid) tmp[now++] = nums[L++];
        while(R <= r) tmp[now++] = nums[R++];
        for(int i = l; i <= r; i++) nums[i] = tmp[i];
    }
};