#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>
using namespace std;
int n,m,a,b,flag;
char ch[300000]={0};

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        getchar();
        scanf("%s",ch);

        for(int i=1;i<=m;i++)
        {
            char c;
            scanf("%d%d",&a,&b);
            if(a>b)
                swap(a,b);
            if(ch[a-1]==ch[b-1]||ch[b-1]=='(')
            {
                printf("Yes\n");
                continue;
            }
                swap(ch[a-1],ch[b-1]);
            flag=0;
            for(int i = 0;i<n;i++)
                {
                    if(ch[i]=='(')
                        flag++;
                    if(ch[i]==')')
                        flag--;
                    if(flag<0)
                        break;
                }
            if(flag==0)
                    printf("Yes\n");
            else
                    printf("No\n");
            swap(ch[a-1],ch[b-1]);
        }
    }
    return 0;
}
