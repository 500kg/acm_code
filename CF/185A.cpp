#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
struct Ma
{
    long long int m[2][2];
};
Ma M,I;
Ma mul(Ma A,Ma B)
{
    Ma C;
    memset(C.m,0,sizeof(C.m));

    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++)
    C.m[i][j]+=(A.m[i][k]*B.m[k][j])%mod;
    return C;
}
void ini()
{

    M.m[0][0]=M.m[1][1]=3;
    M.m[1][0]=M.m[0][1]=1;
    I.m[0][0]=I.m[1][1]=1;
    I.m[1][0]=I.m[0][1]=0;
}
Ma qp(long long n)
{
    Ma m = M, b = I;
    while(n)
    {
        if(n & 1)
            b = mul(b,m);
        n = n >> 1;
        m = mul(m,m);
    }
    return b;
}
int main()
{
    ini();
    long long n;
    while(cin>>n)
    {
        Ma A=qp(n);
      //A=mul(M,M);
      /*  for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                cout<<A.m[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;*/
        cout<<A.m[0][0]%mod<<endl;
    }
}
