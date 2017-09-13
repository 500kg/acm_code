#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void exGcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1; y=0;
        return ;
    }
    exGcd(b,a%b,x,y);
    int tmp=x;
    x=y;
    y=tmp-a/b*y;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c,d,i,flag=0;
        cin>>a>>b>>c>>d;
        if(c>a){swap(a,c);swap(b,d);}
        for(i=0;i<=b;i++)
        if((b+i*a)%b==d){printf("%d\n",b+i*a);flag=1;break;}
        if(flag==0)printf("-1\n");
    }
}
