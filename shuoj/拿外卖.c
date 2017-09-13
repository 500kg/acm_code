#include<stdio.h>
#include<math.h>

int n;
double xishu(int k)
{
    int i;double x=1;
    for(i=1;i<=k;i++)
        {x*=(n-i);
        x/=i;}

    return x;
}
int main()
{
    int x,i;
    while(scanf("%d%d",&n,&x)==2)
  {

    int k=n/5+1;
    if(n%5==0)k--;
    double c;
    c=pow((99-x)/100.0,n-1.0);
 //   printf("%f\n",c);
    for(i=1;i<k;i++)
      {
          c+=xishu(i)*pow((x+1)/100.0,i*1.0)*pow((99-x)/100.0,n-i*1.0-1);
          if(c<0.000001){printf("Happy Yaoge!\n");break;}
         // printf("%f %f %f\n",xishu(i),pow((x+1)/100.0,i*1.0),pow((99-x)/100.0,n-i*1.0-1));
      }


if(c<0.000001){continue;}

    printf("%f\n",c);
}

}
