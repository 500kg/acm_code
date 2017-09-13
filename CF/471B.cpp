#include<bits/stdc++.h>
using namespace std;
int num[2005];
struct aa
{
    int n;
    int id;
}a[2005];
bool cmp(struct aa aaaa,struct aa bbbb)
{
    if(aaaa.n<bbbb.n)return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>a[i].n;
    a[i].id=i+1;
    num[a[i].n]++;
    }
    int k=1;
    for(int i = 0; i < n; i++)
        k*=num[i]==0?1:num[i];
    if(k<3){puts("NO");return 0;}
     else puts("YES");
    sort(a,a+n,cmp);
   for(int i=0;i<n;i++)
        cout<<a[i].n<<a[i].id<<endl;
        int flag;
    for(int i=0;i<n-1;i++)
    if(a[i].n==a[i+1].n){swap(a[i].n,a[i+1].n);swap(a[i].id,a[i+1].id);flag=i;return 0;}
    for(int i=0;i<n;i++)
        cout<<a[i].n<<a[i].id<<endl;





}
