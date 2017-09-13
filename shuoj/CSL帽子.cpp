#include<bits/stdc++.h>
using namespace std;
int k[100005];
int main()
{
    int n,m;
    while(cin>>n>>m){
    int i;
    memset(k,0,sizeof(k));
    for(i=0;i<n;i++)
        cin>>k[i];
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(k[a]==k[b]&&k[a]!=0)printf("yes\n");
        else printf("no\n");
    }
    }
}
