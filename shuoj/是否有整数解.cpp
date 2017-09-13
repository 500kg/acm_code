#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int d=gcd(a,b);
        if(c%d==0)printf("Yes\n");
        else printf("No\n");
    }
}
