#include<bits/stdc++.h>
using namespace std;
int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}
int main()
{
    int m[9],b[9];
    while(scanf("%d%d%d%d%d%d%d%d",m+1,m+2,m+3,m+4,m+5,m+6,m+7,m+8)==8)
    {
        int i,j,temp,min,t;
    for(i=1;i<=8;i++){
            min=100;
       for(j=i;j<=8;j++)
           if(min>m[j]){min=m[j];t=j;}
        if(t==i)continue;
        else {  temp=m[t];m[t]=m[i];m[i]=temp;
                printf("%d 0\n%d %d\n0 %d\n",i,t,i,t);}
     }
printf("-1\n");
    }
}
