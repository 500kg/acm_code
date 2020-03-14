class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> ans;
        if(k == 0) return ans;
        for(int i = 0; i < k; i++){
            while(!Q.empty() && nums[i] > nums[Q.back()])
                Q.pop_back();
            Q.push_back(i);
        }
        ans.push_back(nums[Q.front()]);
        for(int i = k, j = 0; i < nums.size(); i++, j++){
            if(!Q.empty() && Q.front() <= j) Q.pop_front();
            while(!Q.empty() && nums[i] > nums[Q.back()])
                Q.pop_back();
            
            Q.push_back(i);
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};