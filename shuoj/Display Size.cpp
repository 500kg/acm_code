#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int i,b;
    cin>>n;
    for(i=sqrt(n*1.0);i>=1;i--)
    {
        if(n%i==0)
        {
            b=n/i;
            break;
        }
    }
    cout<<i<<' '<<b;
}
