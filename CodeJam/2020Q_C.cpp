#include<bits/stdc++.h>
using namespace std;

int a[105][105];
int vis[105];
int main(){
    int T, kase = 0; cin >> T; while(T--){
        printf("Case #%d: ", ++kase);
        int C = -1, J = -1;
        int n; cin >> n;
        vector<pair<pair<int, int>, int> > v;
        for(int i = 0, x, y; i < n; i++){
            scanf("%d%d", &x, &y);
            v.push_back(make_pair( make_pair(x, y), i));
        }
        bool flag = true;
        string ans(n, 0);
        sort(v.begin(), v.end());
        for(auto &a: v){
            int t = a.second, l = a.first.first, R = a.first.second;
            if(l >= C) C = R, ans[t] = 'C';
            else if(l >= J) J = R, ans[t] = 'J';
            else flag = 0;
        }
        if(flag) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

}
