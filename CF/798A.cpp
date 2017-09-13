#include<bits/stdc++.h>
using namespace std;
char c[100];
int main()
{
    gets(c);
    int i=0,j=strlen(c)-1;
    int cnt=0;
    for(;i<j;i++,j--)
    {
        if(c[i]!=c[j])
            cnt++;
    }
    if(cnt==1||(cnt==0&&strlen(c)%2))
        puts("YES");
    else puts("NO");

}
