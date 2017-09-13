#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
        for(int i=2;i<n;i++)
        if(n%i==0)printf("%d\n",i);
}
