#include<bits/stdc++.h>
using namespace std;

int a[105][105];
int vis[105];
int main(){
    int T, kase = 0; cin >> T; while(T--){
        printf("Case #%d: ", ++kase);
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        int k = 0, r = 0, c = 0;
        for(int i = 1; i <= n; i++) k += a[i][i];
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            for(int j = 1; j <= n; j++){
                if(vis[a[i][j]]){
                    r++; break;
                }
                vis[a[i][j]]++;
            }
        }
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            for(int j = 1; j <= n; j++){
                if(vis[a[j][i]]){
                    c++; break;
                }
                vis[a[j][i]]++;
            }
        }
        printf("%d %d %d\n", k, r, c);
    }

}