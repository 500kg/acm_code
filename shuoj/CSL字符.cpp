#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;


int main()
{
    int T;
  while(scanf("%d",&T)==1){
        char ch[100];
    int sum=0,n,TT,i;
    getchar();
    while(T--)
    {
        gets(ch);
        n=strlen(ch);
    for(i=2;i<n;i++)
        if(ch[i]=='+'&&ch[i-1]=='+'&&ch[i-2]=='X')
        {
            sum++;
        }
        else if(ch[i]=='X'&&ch[i-1]=='-'&&ch[i-2]=='-')\
        {
            sum--;ch[i]='A';
        }

    }
    printf("%d\n",sum);}
}
