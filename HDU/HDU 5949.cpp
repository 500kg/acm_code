#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;cin>>T;while(T--)
    {
        string s;cin>>s;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='H')ans++;
            else if(s[i]=='O')ans+=16;
            else ans+=12;
        }
        printf("%d\n",ans);
    }
}