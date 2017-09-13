#include<bits/stdc++.h>
using namespace std;
#define max 0xffffffff
int main()
{
  //  cout<<max<<endl;
    long long a,bb,cas=1;
    while(scanf("%lld",&a)==1)
    {
        printf("Case %lld: %lld",cas++,a);
        long long b=a*a;
        for(int i=1;b<max&&i<5;i++,b*=a)
        printf(", %lld",b);
        printf("\n");
    }

}
