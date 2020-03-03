#include<bits/stdc++.h>
using namespace std;
const double Pi=acos(-1.0);
int main()
{
    int n,t;
   while( cin>>n>>t)
   {
 double ans=0;
    int x;
//    cout<<sin(Pi)<<endl;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        x/=2;
        ans+=1.0*t*t*sin(1.0*x/180*Pi)*cos(1.0*x/180*Pi);//cout<<ans<<endl;
    }
    printf("%.3f\n",ans);
   }


}