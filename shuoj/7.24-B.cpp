#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int find(int n)
{
    int max=-1e9,now=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            now=i;
        }
    }
    return now;
}
int main()
{
    int x;
    while(cin>>x)
    {
        int now=1;
        a[now]=x;
        while(getchar()!='\n')
              cin>>a[++now];
              for(int i=1;i<now;i++)
                cout<<a[i]<<' ';
        cout<<a[now]<<endl;
        int si=now,step=0;
        while(si>0)
        {
            int m=find(si);
            if(m==si)
            {
                si--;
                continue;
            }
            else
            {
                if(m==1) {step++;cout<<now-si+1<<' ';}
                else
                {
                    step+=2;
                    cout<<now-m+1<<' '<<now-si+1<<' ';
                }
                for(int i=1;i<=si;i++)
                    b[i]=a[i];
                    for(int i=1;i<=m;i++)
                    a[i]=b[m-i+1];
                    for(int i=1;i<=si;i++)
                        b[i]=a[i];
                    for(int i=1;i<=si;i++)
                        a[i]=b[si-i+1];
                    si--;
            }
        }
        cout<<'0'<<endl;

    }
}
