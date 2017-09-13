#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,c;
    while(cin>>n>>a>>b>>c){
    int mox=-5;
    for(int i=0;i<=4000;i++)
        for(int j=0;j<=4000;j++)
    {
        if(a*i+b*j>n)break;
        else if((n-a*i-b*j)%c==0)
            mox=max(mox,i+j+(n-a*i-b*j)/c);
    }
    cout<<mox<<endl;}
}
