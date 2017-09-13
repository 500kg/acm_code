#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int cas = 1;
	long long int Z, I, L, M;
	while (scanf("%lld%lld%lld%lld", &Z, &I, &M, &L) == 4)
	{
		if (Z == 0 && I == 0 & M == 0 & L == 0)break;
		int ans = 0;
		memset(a, 0, sizeof(a));
		while(1)
        {

            L=(Z*L+I)%M;
            a[L]++;ans++;
if(a[L]==2)break;
        }
		printf("Case %d: %d\n", cas++, ans-1);
	}
	return 0;
}
