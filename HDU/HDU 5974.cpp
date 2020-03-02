#include<bits/stdc++.h>
using namespace std;
int a,b;
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
map<int,int>M;
int A[100];
int C[100];
int ans=0;
void dfs(int pos,int rua)
{
 //   cout<<pos<<' '<<rua<<endl;
    if(ans)return;
    if(pos==-1)
    {
        int l=rua,r=a-rua;
        if(r<=0)return;
     //   cout<<l<<' '<<r<<endl;
        if(lcm(l,r)==b)
        {
            ans=1;
            if(l>r)swap(l,r);
            printf("%d %d\n",l,r);

        }return;
    }
    for(int i=0;i<=C[pos];i++,rua*=A[pos])
        dfs(pos-1,rua);
}
int main()
{
    while(scanf("%d%d",&a,&b)==2)
    {
        M.clear();
        int B=b;
        int cnt=0;
        int t=0;
        ans=0;
        for(int i=2;i*i<=b;i++)
        {
            while(b%i==0)
            {
                if(M[i]==0)cnt++;
                M[i]++;
                b/=i;
            }
        }
        if(b!=1)M[b]++;
        b=B;
        for(auto &v:M)
        {
            A[t]=v.first;
            C[t++]=v.second;
        }
    //    for(int i=0;i<t;i++)
    //        cout<<A[i]<<' '<<C[i]<<endl;
        dfs(t-1,1);
        if(!ans)printf("No Solution\n");
    }
}