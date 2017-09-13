#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long cnt;
int vis[17] = { 0 };
char num[16];
char ans[16];
void ini()
{
	for (int i = 0; i <= 9; i++)
		num[i] = i + '0';
	for (int i = 10; i <= 15; i++)
		num[i] = i - 10 + 'A';
}
long long f(int n, int m)//¼ÆËãÅÅÁÐÊýA(n,m);  
{
	int res = 1;
	if (m == 0) return 1;
	while (m--) {
		res *= n;
		n--;
	}
	return res;
}
long long T(int n,int UNI)
{
	long long ans = 1;
	for (int i = n + 1; i <= 8; i++)
		ans *= (15 - UNI);
	return ans;
}
void solve()
{
	int flag = 0;
	int Ulen = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= 8; i++)
	{
		int now = 15;
		while (now )
		{
			if (!vis[now])
			{
				long long mox = T(i,Ulen);
				long long moo = f(15 - Ulen, 8 - i);
				if (moo < cnt)cnt -= moo;
				else {
					vis[now] = 1;
					break;
				}
			}
			now--;
		}
		ans[i] = num[now];
		if (ans[i] != '0') flag = 1;
		if (flag || ans[i] != '0') Ulen++;
		
	}
}
int main()
{
	ini();
	//for (int i = 0; i <= 15; i++)
	//	printf("%c", num[i]);
	while(scanf("%d",&cnt)==1)
	{
		solve();
		int flag = 0;
		for (int i = 1; i <= 8; i++) {
			if (flag || ans[i] != '0') {
				printf("%c", ans[i]);
				flag = 1;
			}

		}
		printf("\n");
	}
}