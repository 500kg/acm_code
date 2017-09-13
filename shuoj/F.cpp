#include <bits/stdc++.h>


int main()
{
    int n,tem,a[1005]={0},b[1005]={0};
    int w,s,sum,min1,i,j,k;
    while(scanf("%d",&n)==1)
    {
        sum=0,min1=0;
        for(k=0;k<n;k++)
        {

            scanf("%d%d",&w,&s);
            if(w>s){tem=w;w=s;s=tem;}
            for(i=0;;i++)
            {
                if(a[i]==0)
                {
                    a[i]=s;b[i]=w;break;
                }
                if(s<a[i])
                {
                    for(j=k;j>=i;j++)
                    {a[j+1]=a[j];b[j+1]=b[j];}
                    a[i]=s;b[i]=w;break;
                }

            }


        }
       for(i=0;i<n;i++)
        printf("%d %d\n",a[i],b[i]);
    }
}

        //    if(sum-s>min1)min1=sum-s;
         //   sum+=w;
