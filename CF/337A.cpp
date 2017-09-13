#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    int a[100];
    while(cin>>k>>n){
    int mon=10000;
    for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
    for(int i=0;i<n-k+1;i++)
        mon=min(mon,a[i+k-1]-a[i]);
    cout<<mon<<endl;}

}
