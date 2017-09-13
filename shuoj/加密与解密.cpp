#include<bits/stdc++.h>
using namespace std;
char ch[100005];
char  c[100005];
void solve()
{
    int n=strlen(ch),i,t,j=0;
    reverse(ch,ch+n);
    //puts(ch);
    for(i=0;i<n;)
    {
        t=(ch[i]-'0')*10+(ch[i+1]-'0');i+=2;
        if(t<30)t=t*10+ch[i]-'0',i++;
        c[j++]=t;
    }
    c[j]='\0';
    puts(c);

}
void solve2()
{
    int n=strlen(ch),i,t,j=0;
    for(i=0;i<n;i++)
    {
        t=ch[i];
        if(t>=100)c[j++]=t/100+'0',t%=100;
        c[j++]=t/10+'0';
        c[j++]=t%10+'0';
    }
    c[j]='\0';
    reverse(c,c+j);
    puts(c);
}
int main()
{
    int T;
    cin>>T;getchar();
    while(T--)
    {
        gets(ch);
        if(ch[0]>='0'&&ch[0]<='9')solve();
        else solve2();
    }
}
