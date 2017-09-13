#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,a[10]={0},b[10]={0};
    int i;
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    for(i=0;i<6;i++)
    {scanf("%d",&x);a[x]++;}
    for(i=0;i<10;i++)
        b[a[i]]++;
    if((b[4]&&b[2])||b[6])printf("Elephant");
    else if(b[5]||b[4])printf("Bear");
    else printf("Alien");
}
