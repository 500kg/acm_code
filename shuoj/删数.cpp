#include<bits/stdc++.h>
using namespace std;
char ch[245];
int k;
void del()
{
    for(int i=0;i<strlen(ch);i++)
        if(ch[i]>ch[i+1])
    {
        for (int j=i;j<strlen(ch);j++)
                ch[j]=ch[j+1];
        break;
    }
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        cin>>ch>>k;
        while(k--)
            del();
        int i,flag=0;
        for(i=0;ch[i]=='0';i++);
        for(;i<strlen(ch);i++)
           {
                printf("%c",ch[i]);
                flag=1;
           }
           if(flag==0)printf("0");
        printf("\n");
    }
}
