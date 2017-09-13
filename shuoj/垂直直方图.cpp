#include<bits/stdc++.h>
using namespace std;
char ch[1005];
int a[28];
int main()
{
    int T;
    cin>>T;getchar();
    while(T--)
    {
        memset(a,0,sizeof(a));
        gets(ch);
        int n=strlen(ch);
        for(int i=0;i<n;i++)
            if(ch[i]>='A'&&ch[i]<='Z')
            a[ch[i]-'A']++;
        for(int i=0;i<=26;i++)
            if(a[i])printf("%c:%d,",i+'A',a[i]);
        printf("\n");
    }
}
