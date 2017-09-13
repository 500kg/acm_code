#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i;
    int a[105],b[105];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);sort(b,b+m);
    int j=0,k=0;
    int cnt=0;
    while((j!=n)&&(k!=m))
    {
        int q=a[j]-b[k];
        if(q<-1)j++;
        else if(q>1)k++;
        else j++,k++,cnt++;
      //  printf("%d %d %d\n",j,k,cnt);
    }
    cout<<cnt;
}
