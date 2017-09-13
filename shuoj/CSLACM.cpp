#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;

int main()
{
    int n,t,m,c;
    while(scanf("%d%d%d%d",&n,&t,&m,&c)==4)
    {
        int k=(n/m+(n%m!=0));
        int t1=k*t;
        if((t1-1-c)>=t)printf("yes\n");
        else printf("no\n");

    }
}
