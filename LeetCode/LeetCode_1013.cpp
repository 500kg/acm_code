class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long long sum = 0;
        for(auto &v: A) sum += v;
        if(sum%3) return 0;
        int n = A.size();
        long long avg = sum/3;
        long long l = 0, sl = 0;
        while(l < n){
            sl += A[l];
            if(sl == avg) break;
            l++;
        }
        long long r = n - 1, sr = 0;
        while(r >= 0){
            sr += A[r];
            if(sr == avg) break;
            r--;
        }
//        cout << sum << ' '<<sl<<' '<<l<<' '<<sr<<' '<<r<<endl;
        return sl == avg && sr == avg && l + 1 < r;
    }
};