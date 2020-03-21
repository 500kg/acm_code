class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        if(k == 0) return vector<int>();
        return vector<int> (arr.begin(), arr.begin() + k);
    }
};