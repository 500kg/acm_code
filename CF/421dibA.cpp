#include<bits/stdc++.h>

using namespace std;
int main()
{
    int c,v0,v1,a,l;
    int d=2;
    cin>>c>>v0>>v1>>a>>l;
    int ak=v0;
    if(v0>=c){printf("1");return 0;}
    for(;;d++)
    {ak=ak+min(v0+(d-1)*a-l,v1-l);
    if(ak>=c)break;}
    printf("%d",d);
}

