#include<stdio.h>
int L=0,R=365,
a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void del(int MD,char ch[])
{
    int M=MD/100,D=MD%100,date=D,i;
    for(i=1;i<M;i++)
        date+=a[i];
       // printf(" %d %d  %d\n",M,D,date);
    if(ch[0]=='B')R=date>R?R:date;
    else L=date>L?date:L;
}
void date(int l)
{
    int d=l+1,i=0;
    while(d>0)
    {
        i++;d-=a[i];
    }
    d+=a[i];
    if(i<10)printf("0%d",i);
    else printf("%d",i);
    if(d<10)printf("0%d\n",d);
    else printf("%d\n",d);
}

int main()
{
    int m;
    int MD,M,D,t;
    char ch[7];
    scanf("%d",&m);
    for(t=1;t<=m;t++)
    {

        int n;L=0,R=365;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%s",&MD,ch);
            del(MD,ch);
        }
        printf("Case %d:\n",t);
        if(R-L==2)date(L);
        else if(R-L>2)printf("%d\n",R-L-1);
        else printf("Impossible\n");
    }
    return 0;
}
