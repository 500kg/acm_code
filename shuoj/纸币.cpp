#include<bits/stdc++.h>
using namespace std;
const int maxN = 1005;
int a[maxN];
int s[maxN];
int f(int n)
{
    for(int i=1;i<=n;i++)
           {
              s[i]=s[i-1]+a[i];
              if(a[i+1]>s[i]+1)
                 return s[i]+1;
           }
    return 0;
}

int ff(int n)
{
    for(int i=1;i<=n;i++)
        {
            if(a[i]==0)continue;
            else if(a[i]==1)return 0;
            else return 1;
        }
}
int main()
{
    int n;
    while(cin>>n)
    {
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
           cin>>a[i];

        sort(a+1,a+n+1);
        if(ff(n))
            {printf("1\n");continue;}

        if(f(n))
            printf("%d\n",f(n));
        else
           printf("%d\n",s[n]+1);

    }
}
