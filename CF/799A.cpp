#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[30];
    memset(a,0,sizeof(a));
    char ch[1500];
    int n;
    scanf("%s%d",ch,&n);
    int len=strlen(ch);
    if(n>len)
    {
        puts("impossible");
        return 0;
    }
    for(int i=0;i<len;i++)
        a[ch[i]-'a']++;
    int cnt=0;
    for(int i=0;i<30;i++)
        if(a[i])
            cnt++;
        if(cnt<n)
            printf("%d\n",n-cnt);
        else
            printf("0\n");
}
