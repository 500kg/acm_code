#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    cin>>n>>a;
    int k=3;
    double an=(n-2)*180.0/n;
    double min1=abs(an-a);
    for(int i=4;i<=n;i++)
    {
        if(abs(an*(n-i+1)/(n-2)-a)<min1)
        {
            min1=abs((an*(n-i+1)/(n-2))-a);
            k=i;

        }
    }
    printf("1 2 %d",k);



}
