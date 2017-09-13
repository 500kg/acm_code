#include<bits/stdc++.h>
using namespace std;
int  l[100005];
int fin(int i)
{
    int r=i;
    while(l[r]!=r)
        r=l[r];
    return r;
}
void he(int n,int m)
{
    int tn=fin(n);
    int tm=fin(m);
    if(tn!=tm)l[tm]=tn;
}
int main()
{
    int N,M;
    cin>>N>>M;
    int i;
    int a,b,c;
    for(i=1;i<=N;i++)
        l[i]=i;
    for(i=1;i<=M;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            he(b,c);
         //   printf("he%d %d\n");
        }
        else
        {
            if(fin(b)==fin(c))printf("Yes\n");
            else printf("No\n");


        }
    }

}
