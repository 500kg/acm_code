#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n-2;i++)
    {
        if(a[i]+a[i+1]>a[i+2])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
}
