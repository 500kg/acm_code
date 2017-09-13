#include<bits/stdc++.h>
using namespace std;
float f(float a)
{
    return (int)(a*10+0.5)/10.0;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int t,a,b;
      //  double m;cin>>m;
        cin>>t>>a>>b;
       double m=a*t/100.0+b*(1-t/100.0);
        printf("%.1f\n",f(m));
    }
}
