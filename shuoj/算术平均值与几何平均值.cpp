#include<bits/stdc++.h>
using namespace std;


int main()
{
    double a,t[15];int i=0;
    char ch,cas=1;
    while(scanf("%lf",&a)==1)
    {
        if(scanf("%c",&ch)!=1)break;
        int flag=0,bo=1;
        t[i++]=a;
        int j;
        double m1=0,m2=1;
    if(ch=='\n')
    {
        for(int j=0;j<i;j++)
        {
            m1+=t[j];m2*=t[j];
        }
        m1/=i;if(m2<0&&i%2==0)flag=1;
              else if(m2<0)bo=-1,m2=-m2;
                m2=pow(m2,1.0/i)*bo;

    i=0;
    if(flag)printf("Case %d: %.1f, None\n",cas++,m1);
    else printf("Case %d: %.1f, %.1f\n",cas++,m1,m2);}
    }
}
