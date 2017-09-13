#include<bits/stdc++.h>

using namespace std;
char ch[25];
char ch2[25];
int flag,ans1,ans2,n;
void rev(int n)
{
    if(ch[n]=='1')ch[n]='0';
    else ch[n]='1';
}
void rev2(int n)
{
    if(ch2[n]=='1')ch2[n]='0';
    else ch2[n]='1';
}
void f1()
{
    int i;
    for(i=1;i<n;i++)
    {
        if(ch[i-1]=='1')
        {
            rev(i-1);rev(i);if(i!=(n-1))rev(i+1);
            ans1++;
        }
    }
    if(ch[n-1]=='0')
        flag=1;
    else ans1=100000;
}

void f2()
{
    int i;
    rev2(0);rev2(1);ans2++;
    for(i=1;i<n;i++)
    {
        if(ch2[i-1]=='1')
        {
            rev2(i-1);rev2(i);if(i!=(n-1))rev2(i+1);
            ans2++;
        }
    }
    if(ch2[n-1]=='0')
        flag=1;
    else ans2=100000;
}



int main(){
    while(gets(ch))
   {
      flag=ans1=ans2=0;
      n=strlen(ch);
      strcpy(ch2,ch);
      f1();f2();
      if(flag==0)
		    printf("NO\n");
      else
    {
		        printf("%d\n",min(ans1,ans2));
    }

   }
}
