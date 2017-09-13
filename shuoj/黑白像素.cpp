#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int cnt=0;
        int t=n*m,x;
        while(t--)
        {
            cin>>x;
            if(x==0)cnt++;
        }
        cout<<cnt<<endl;
    }
}
