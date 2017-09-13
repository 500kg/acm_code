#include<bits/stdc++.h>

using namespace std;
int main()
{
    int a,b,ll,rr;
    cin>>a>>b>>ll>>rr;
    int rrr=rr%(a+b)==0?a+b:rr%(a+b);
    int l=ll%(a+b),r=rrr+(a+b)*(rr/(a+b)>=2);
    int ans=0;
    cout<<l<<r<<endl;
    if(l<=a)
    {
        if(r<=a)
        {printf("%d",r-l+1);return 0;}
        if(r<=a+b)
            {printf("%d",a-l+1);return 0;}
        if(r<2*a+b)
            {printf("%d",r-l+1-b);return 0;}  //
        else
            {printf("%d",a+1);return 0;}
    }
    if(l<=a+b)
    {
        if(r<=a+b)
            {printf("%d",1);return 0;}
        if(r<=2*a+b)
            {printf("%d",r-a-b+1);return 0;}
        else {printf("%d",a);return 0;}
    }
}
