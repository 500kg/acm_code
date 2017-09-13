#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cas=1;
    double n;
    while(scanf("%lf",&n)==1)
    {
        printf("Case %d: %.1f, ",cas++,n);
        n/=1000;
        int cnt=0;
        while(n<8844.43)
        {
            cnt++;
            n*=2;
        }
        printf("%d, %.1f\n",cnt,n);
    }
}
