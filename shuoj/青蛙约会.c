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
	while(cin>>x>>y>>m>>n>>L){
          long long t,u;
          long long d=exgcd(n-m,L, t, u);  //ŷ������㷨��������t��u
                                  			//����d��Ϊ�������
          if((x-y)%d||m==n)
               printf("Impossible\n");
          else {
               long long s=L/d;
               t=t*((x-y)/d);
               t=(t%s+s)%s;
               printf("%d\n", t);
          }
     }

}
