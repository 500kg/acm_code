#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k,i,a[2500],ans=0;
    cin >> n >> m >> k;
    for(i=0;i<=m;i++)
        cin >> a[i];
    for(i=0;i<m;i++)
        if(__builtin_popcount(a[i]^a[m])<=k)ans++;
    printf("%d",ans);
}
