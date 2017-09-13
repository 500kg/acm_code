#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int s[100006];

int main()
{
    int n,q,x,m,r;
    while(scanf("%d%d",&n,&q)==2)
    {
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
          {scanf("%d",&s[i]);s[i]+=s[i-1];}
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&m,&r);
            printf("%d\n",s[r]-s[m-1]);
        }

    }
}
