#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        scanf("%d",&n);
        scanf("%d",&x);
        int mox=x,sum=x;
     //   cout<<mox<<endl;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&x);
            if(sum<0)sum=x;
            else sum+=x;
            mox=max(mox,sum);
        }
        cout<<mox<<endl;
    }
}
