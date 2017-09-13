#include<bits/stdc++.h>
using namespace std;

long long Exgcd(long long a,long long b,long long &x,long long &y ) {
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    long long d =  Exgcd(b, a%b, x, y), temp = x;
    x = y;
    y = temp-a/b*y;
    return d;
}
int main()
{
    long long x,y,m,n,L;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)==5){
          long long t,u;
          long long d=Exgcd(n-m,L, t, u);  //欧几里得算法，求整数t，u
                                  			//返回d：为最大公因数
          if((x-y)%d||m==n)
               printf("Impossible\n");
          else {

               long long s=L/d;
            //   printf("%lld %lld %lld\n",t,s,x-y);
               t=t*((x-y)/d);
            //   printf("%d\n", t);
            if(d<0)d=-d;s=L/d;      //  ----->d可能为负
               t=(t%s+s)%s;
               printf("%d\n", t);
          }
     }

}
