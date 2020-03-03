#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    int x;
    int T;cin>>T;while(T--)
    {
        scanf("%d",&x);
       while(x)
       {
           if(x%256==97)ans++;
           x/=256;
       }
    }
    cout<<ans<<endl;
}