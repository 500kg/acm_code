#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int i,j,k;
int f()
{
    i=100/a;
    for(;i>=1;i--)
        {
            j=(100-i*a)/b;
            for(;j>=1;j--)
            {
                k=(100-i*a-j*b)/c*3;
                if((i+j+k)==100)
                    return 1;
            }
        }
        return 0;
}
int main()
{
    int num=1;

    while(cin>>a>>b>>c)
    {
        printf("Case %d:\n",num);
        num++;
        if(f())
            printf("%d %d %d\n",i,j,k);
        else
            printf("Impossible\n");

    }
}
