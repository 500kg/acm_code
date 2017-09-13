#include<stdio.h>

int main()
{
    int m[9],b[9];
    while(scanf("%d%d%d%d%d%d%d%d",m+1,m+2,m+3,m+4,m+5,m+6,m+7,m+8)==8)
    {
        int i,j,temp;
    for(i=1;i<8;i++){ //Ã°ÅÝÅÅÐò
       for(j=i;j<8;j++)
           if(m[j]>=m[j+1]) {
                 temp=m[j];
                 m[j]=m[j+1];
                 m[j+1]=temp;
                 printf("%d 0\n%d %d\n0 %d\n",m[j],m[j+1],m[j],m[j+1]);
            }
     }
printf("-1");
    }
}
