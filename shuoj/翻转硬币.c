#include<stdio.h>
#include<string.h>
int ans;
char ch[106],a[106];
void fan(int l)
{
    int i;
    for(i=0;i<=l;i++)
        if(ch[i]=='-')a[i]='+';
    else a[i]='-';
    for(i=0;i<=l;i++)
        ch[i]=a[l-i];
        ans++;
}
int main()
{
    int n,l,i;
    scanf("%d",&n);
    while(n--)
    {
        ans=0;
        scanf("%s",ch);
        l=strlen(ch);
        int last=l-1;
       while(last>=0)
        {
            if(ch[last]=='+'){last--;continue;}
            else if(ch[0]=='-') fan(last);
            else {for(i=0;ch[i]=='+'&&i<last;i++);
                 fan(i);fan(last);
            }
            last--;

        }

        printf("%d\n",ans);
    }
}
