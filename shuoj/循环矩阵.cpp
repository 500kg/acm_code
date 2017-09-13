#include<bits/stdc++.h>
using namespace std;
void f(int i,int n)
{
    printf("%d",i);i++;
    if(i>n)i=1;
    int t;
    for(t=2;t<=n;t++)
        {
            printf(" %d",i);
            i++;
            if(i>n)i=1;
        }
    printf("\n");
}
int main()
{
    int n;
    while(cin>>n)
    {
        int i;
        printf("n=%d\n",n);
        for(i=1;i<=n;i++)
            f(i,n);
    }
    return 0;
}
