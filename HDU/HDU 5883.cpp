#include<bits/stdc++.h>
using namespace std;
const int maxN=100000+5;
int in[maxN], f[maxN],t[maxN];
int fin(int x)
{
	if(f[x]!=x)f[x]=fin(f[x]);
	return f[x];
}
void uni(int x, int y)
{
	int tx = fin(x);
	int ty = fin(y);
	if (tx != ty)f[tx] = ty;
}
void ini(int n)
{
	for (int i = 1; i <= n; i++)
		f[i] = i,in[i]=0;

}
int main()
{
	int n, l,T;
	cin >> T;while(T--)
	{

		scanf("%d%d",&n,&l);
		ini(n);
		int a, b;
		for (int i = 1; i <= n; i++)
			scanf("%d",&t[i]);
		for (int i = 1; i <= l; i++)
		{
			scanf("%d%d",&a,&b);
			uni(a, b);
			in[a]++, in[b]++;
		}
		int  flag1=0,flag2=0;
		for(int i=1;i<=n;i++)
        {
            if(fin(i)==i)flag1++;
            if(in[i]%2==1)flag2++;
        }
        if(flag1>1||flag2>2){puts("Impossible");continue;}
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int a=(in[i]+1)/2;
            if(a%2==1)res^=t[i];
        }
        int ma=0;
        if(flag2)ma=res;
        else {
            for(int i=1;i<=n;i++)
                if(in[i]%4==2)
                ma=max(ma,res^t[i]);
        }
        printf("%d\n",ma);
	}
	return 0;
}
