#include<bits/stdc++.h>
using namespace std;
char ch[88];


int main()
{
    int T;
    while(gets(ch)!=NULL)
    {
        int n=strlen(ch);
        int mod=0;
        for(int i=0;i<n;i++)
        {
            mod+=(ch[i]-'0');
            mod=mod%11;
            mod*=10;
        }
        if(mod)printf("No\n");
        else printf("Yes\n");
    }
}

