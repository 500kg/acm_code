#include<bits/stdc++.h>
using namespace std;

int a[105][105];
int vis[105];
int main(){
    int T, kase = 0; cin >> T; while(T--){
        printf("Case #%d: ", ++kase);
        string s, ans;
        cin >> s;
        int t = 0;
        for(int i = 0; i < s.length(); i++){
            while(t < s[i] - '0') ans += '(', t++;
            while(t > s[i] - '0') ans += ')', t--;
            ans += s[i];
        }
        while(t) ans += ')', t--;
        cout<<ans<<endl;
    }

}
