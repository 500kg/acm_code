#include<bits/stdc++.h>
using namespace std;
int a[100];
void ini()
{
    a[0]=a[1]=1;
    for(int i=2;i<100;i++)
        a[i]=a[i-1]+a[i-2];
    a[1]=1;a[0]=0;
}
int main()
{
    int T;
    ini();cin>>T;while(T--)
    {
        int n;
        cin>>n;
        cout<<a[n-1]<<endl;
    }
}
