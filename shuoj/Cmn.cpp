#include <stdio.h>
const int M = 10007;
int ff[M+5];  //�����¼n!�������ظ�����

//���������
int gcd(int a,int b)
{
    if(b==0)
 return a;
 else
 return gcd(b,a%b);
}

//������ͬ�෽�̣���չŷ����¶���
int x,y;
void Extended_gcd(int a,int b)
{
    if(b==0)
    {
       x=1;
       y=0;
    }
    else
    {
       Extended_gcd(b,a%b);
       long t=x;
       x=y;
       y=t-(a/b)*y;
    }
}

//���㲻���C(n,m)
int C(int a,int b)
{
    if(b>a)
 return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}

//Lucas����
int Combination(int n, int m)
{
        int ans=1;
 int a,b;
 while(m||n)
 {
         a=n%M;
 b=m%M;
 n/=M;
 m/=M;
 ans=(ans*C(a,b))%M;
 }
 return ans;
}

int main(void)
{
        int i,m,n;
 ff[0]=1;
 for(i=1;i<=M;i++)  //Ԥ����n!
 ff[i]=(ff[i-1]*i)%M;

 scanf("%d%d",&n, &m);
 printf("%d\n",Combination(n,m));

 return 0;
}
