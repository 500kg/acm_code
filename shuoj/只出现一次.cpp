#include<bits/stdc++.h>
using namespace std;
char ch[1005];
int a[300];
int n;
int f()
{
     for(int i=0;i<n;i++)
            if(a[ch[i]]==1)
        {
            printf("%c\n",ch[i]);
            return 0;
        }
        return 1;
}
int main()
{
    int T;
    cin>>T;
    getchar();
    while(T--)
    {
        gets(ch);
        memset(a,0,sizeof(a));
        n=strlen(ch);
        for(int i=0;i<n;i++)
            a[ch[i]]++;
        if(f())
            printf("*\n");




    }
}

