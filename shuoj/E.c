#include<stdio.h>
#include<string.h>
int is(char ch[])
{
    int i=0;
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='1')continue;
        else if(ch[i-1]=='1'&&ch[i]=='8'&&(ch[i+1]=='1'||ch[i+1]=='8'||ch[i+1]=='\0'))continue;
        else if(ch[i-2]=='1'&&ch[i-1]=='8'&&ch[i]=='8')continue;
        return 0;
    }
    return 1;
}
int main()
{
    int i,n,l;
    char ch[100];
    scanf("%d",&n);
    ch[0]=getchar();
    while(n--)
    {
        gets(ch);
        if(is(ch))printf("YES\n");
        else printf("NO\n");
    }
}
