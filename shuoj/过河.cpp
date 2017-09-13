#include<bits/stdc++.h>
using namespace std;

int a[1005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        long long ans=0;
        while(n)
        {
            if(n==1){ans+=a[0];break;}
            else if(n==2){ans+=a[1];break;}
            else if(n==3){ans+=(a[0]+a[1]+a[2]);break;}
            else{ans+=min(2*a[0]+a[n-1]+a[n-2],2*a[1]+a[0]+a[n-1]);n-=2;}
        }
        cout<<ans<<endl;

    }
}
