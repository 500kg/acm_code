#include<bits/stdc++.h>

using namespace std;
int a[52][52];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,p,q;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(a[i][j]!=1)
    {  int flag=0;
        for(p=0;p<n&&flag!=1;p++)
            for(q=0;q<n;q++)
            if(a[p][j]+a[i][q]==a[i][j])
        {
            flag=1;break;
        }
        if(!flag){printf("No");return 0;}
    }
printf("Yes");
}
