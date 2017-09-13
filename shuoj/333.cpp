#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long long a[51];
    int num;
    a[1]=1;a[2]=2;
    for(int i=3;i<=50;i++)
        a[i]=a[i-1]+a[i-2];
    while(scanf("%d",&num)==1)
    {
        cout<<a[num]<<endl;
    }
    return 0;
}
