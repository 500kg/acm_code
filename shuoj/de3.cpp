#include<bits/stdc++.h>
using namespace std;
long long f[1005];


int ola(int mod)
{
    int res=mod,i;
    {for(i=2;i<=mod;i++)
        if(mod%i==0)
        {
             res=res*(1.0-1.0/i);
            // printf("res=%d  %d\n",res,i);
             mod/=i;
             while(mod%i==0)
                 mod/=i;
                 i=2;
        }
    }
     //   printf("res=%d\n",res);
    return res;
}

int pow1(int x,int n,int mod)  //¿ìËÙÃÝ
{    int m=1;
     for(int i=1;i<=n;++i){
        m*=x;
        m=m%mod;
     }
     return m;
}
int a(int n,int mod)
{
    if(n==0)return 1;
    else return pow1(3,a(n-1,ola(mod)),mod);
}

int main()
{
    int pp[10];
    pp[0]=1;pp[1]=3;pp[2]=27;pp[3]=356684;pp[4]=1010249;pp[5]=713667;
    int KKK;
    scanf("%d",&KKK);
    while(KKK--)
    {
        int n;
        scanf("%d",&n);
        if(n>=6){printf("525919\n");continue;}
        int mod=1071017;
        printf("%d\n",pp[n]);
    }
   /* int i=500,n=500;
    while(i--)
   {
       n++;
       mod=1071017;
   printf("%d\n",a(n,mod);
   }*/

}


