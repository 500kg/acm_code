#include<bits/stdc++.h>
using namespace std;
int num[105];
int main()
{
    int n,a,i;
    cin>>n;
    int p,q;
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>a;
        num[a]=1;
    }
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>a;
        num[a]=1;
    }
    for(i=1;i<=n;i++)
        if(num[i]==0)
    {

        puts("Oh, my keyboard!");return 0;
    }
    printf("I become the guy.");return 0;
}
