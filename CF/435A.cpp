#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x;
    cin>>n>>m;
    int now=m;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(now>=x){
            now-=x;
        }
        else{
            now=m;
            cnt++;
            now-=x;
        }

    }
    cout<<cnt;

}
