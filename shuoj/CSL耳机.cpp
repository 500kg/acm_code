#include<bits/stdc++.h>

using namespace std;
int f[2005];
int find(int i)
{
    while(i!=f[i])
        i=f[i];
    return f[i];
}
void unu(int n,int m)
{
    int tn=find(n);
    int tm=find(m);
    if(tn!=tm)f[tn]=tm;
}
void ini()
{
    for(int i=0;i<=205;i++)
        f[i]=i;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int flag=0;
        ini();
        int n,m;

        cin>>n>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            if(flag)continue;
            if(find(a)==find(b))
                flag=1;
            else
            {
                unu(a,b+n);
                unu(b,a+n);
            }
        }
        if(flag)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
