#include<bits/stdc++.h>
using namespace std;
char n[10005];
int na[10005];
int main()
{
    int a,m,cas=1;
    while(scanf("%d%d",&a,&m)==2)
    {
        printf("Case %d: ",cas++);
        int p=0;
        while(a)
        {
            int k=a%m;
            a/=m;
           if(k<10)n[p++]=k+'0';
           else n[p++]=k+'A'-10;
        }
for(int i=p-1;i>=0;i--)
    putchar(n[i]);
printf("\n");
    }
}
