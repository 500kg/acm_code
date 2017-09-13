#include<bits/stdc++.h>
using namespace std;
vector <int> s[100005];
int ma;
int dfs(int v,int fa,int d)
{
    int i;
    ma=max(ma,d);
    for(i=0;i<s[v].size();i++)
    {
        if(s[v][i]!=fa)
            dfs(s[v][i],v,d+1);
    }
}
void in(int n)
{
    ma=0;
    for(int i=0;i<n;i++)
        s[i].clear();
}
int main()
{
    int n;
    int i,a,b;
    while(cin>>n)
    {
        in(n);
       for(i=1;i<n;i++)
      {
           cin>>a>>b;
           s[a].push_back(b);
           s[b].push_back(a);
      }
        dfs(0,0,0);
        cout<<ma<<endl;
    }
}
