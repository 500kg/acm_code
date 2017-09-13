#include<bits/stdc++.h>
using namespace std;

int n,a[1100];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int i,j,ans=0,x;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=0;i<1050;i++)
    {
        int cnt=0;
        for(int j=0;j<1050;j++)
            if(a[j])
        {
            cnt++;
            a[j]--;
        }
        if(cnt<=1)break;
        cnt--;
        ans+=cnt;
    }
    cout<<ans;


}
