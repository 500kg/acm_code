#include<bits/stdc++.h>
using namespace std;
int ans;
int cmp(int a,int b)
{
    if(a<=b){ans++;return 1;}
    else{return 0;}
}
int main()
{
    int a[100];
    int n;
    while(cin>>n){ans=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        cout<<a[i];
    printf("\n");
    cout<<ans<<endl;
}
}
