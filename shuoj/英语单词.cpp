#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,cas=1,i;
    char ch[65540];
    while(gets(ch)!=NULL)
    {

        n=strlen(ch);
        int cnt=0;
        if(ch[0]!=' ')cnt++;
        for(i=1;i<n;i++)
            if(ch[i-1]==' '&&ch[i]!=' ')cnt++;
        printf("Case %d: %d\n",cas++,cnt);
    }
}
