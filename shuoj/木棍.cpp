#include<bits/stdc++.h>
using namespace std;

struct node
{
    int l, w;
    bool flag;
    bool operator < (const node &a) const
    {
        if (l == a.l)
            return w < a.w;
        return l < a.l;
    }
} st[5005];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>st[i].l>>st[i].w;
            st[i].flag=0;
        }
        sort(st,st+n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
           int ll=0,ww=0,j;
           for(j=i;j<n;j++)
            if(st[j].flag==0)
           {
               st[j].flag=1;ll=st[j].l;ww=st[j].w;
               cnt++;break;
           }
           for(;j<n;j++)
            if(st[j].flag==0&&st[j].l>=ll&&st[j].w>=ww)
           {
               st[j].flag=1;ll=st[j].l;ww=st[j].w;
           }
        }
        cout<<cnt<<endl;
    }
}
