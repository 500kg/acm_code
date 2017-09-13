#include<stdio.h>

int main()
{
    int n,i,fla;
    int a1=0,a2=0,b1=0,b2=0,count=0,flag,flag2,j,k;
    int a[1002],b[1002],c[1002]={0},fl[1002]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    for(i=0;i<n;i++)
        scanf("%d",b+i);
    for(i=0;i<n;i++)
        if(a[i]==b[i]){c[i]=a[i];fl[a[i]]=1;}
    else
        {count++;if(a1==0){a1=a[i];b1=b[i];}
        else {a2=a[i];b2=b[i];}}
    if(count==1)
    {
        for(i=1;i<=n;i++)
            if(fl[i]==0)break;
        flag=i;
        for(i=0;i<n;i++)
            if(c[i]==0)
            c[i]=flag;
    }
    if(count==2)
    {
        for(i=1;i<=n;i++)
            if(fl[i]==0)break;
        flag=i;
        for(i++;i<=n;i++)
            if(fl[i]==0)break;
        flag2=i;
        for(i=0;i<n;i++)
            if(c[i]==0)break;j=i;
        for(;i<n;i++)
            if(c[i]==0)k=i;

        if(a1==flag&&b2==flag2){c[j]=flag;c[k]=flag2;}
      else  if(a1==flag2&&b2==flag){c[k]=flag;c[j]=flag2;}
    else     if(a2==flag&&b1==flag2){c[j]=flag2;c[k]=flag;}
    else     if(a2==flag2&&b1==flag){c[k]=flag2;c[j]=flag;}
    }


    for(i=0;i<n;i++)
            {printf("%d",c[i]);
            if(i<n-1)printf(" ");}
}
