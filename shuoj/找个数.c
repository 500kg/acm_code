#include<stdio.h>
#include<stdlib.h>
int a[100005]={0},x,n;
int find1(int key)
{
    int L,R;
    L=0;R=n;
    while(L<R)
    {
        int mid=L+(R-L)/2;

         if(a[mid]<key&&a[mid+1]>=key)return mid;
         else if(a[mid]>=key)R=mid;
         else L=mid+1;


    }
 if(a[R]<key&&(a[R+1]>key||R==n))return R-1;
    return -2;

}
int find2(int key)
{
    int L,R;
    L=0;R=n;
    while(L<R)
    {
        int mid=L+(R-L)/2;
//printf("%d %d %d\n",L,R,mid);
         if(a[mid]<=key&&a[mid+1]>key)return mid;
         else if(a[mid]>key)R=mid;
         else L=mid+1;


    }
//printf("%d %d \n",L,R);
  // system("pause");
if(a[R]<=key&&(a[R+1]>key||R==n))return R-1;
    return -2;

}
int find3(int key)
{
    int L,R;
    L=0;R=n;
    while(L<R)
    {
        int mid=L+(R-L)/2;
   //    printf("%d %d %d\n",L,R,mid);
         if(a[mid]>key&&a[mid-1]<=key)return mid;
         else if(a[mid]> key)R=mid;
         else L=mid+1;


    }
   // printf("%d %d \n",L,R);
    if(a[R]>key)return R;
    return -2;

}
int find4(int key)
{
    int L,R;
    L=0;R=n;
    while(L<R)
    {
        int mid=L+(R-L)/2;

         if(a[mid]>=key&&a[mid-1]<key)return mid;
         else if(a[mid]<key)L=mid+1;
         else R=mid;


    }
    if(a[R]>=key&&a[R-1]<key)return R;
    return -2;

}
int main()
{
    int m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(m--)
    {

        scanf("%d",&x);
        printf("%d %d %d %d\n",find1(x)+1,find2(x)+1,find3(x)+1,find4(x)+1);
    }
    return 0;
}
