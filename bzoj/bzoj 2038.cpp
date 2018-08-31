#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
int a[maxn];
int cnt[maxn];
ll ans1[maxn], ans2[maxn];
struct node
{
	int l, r, id, be;
}Q[maxn];
bool cmp(node a, node b)
{
	if (a.be == b.be)return a.r < b.r;
	return a.be < b.be;
}
ll remove(int R)
{
	ll ret = cnt[R] * cnt[R];
	cnt[R]--;
	ret -= cnt[R] * cnt[R];
	return ret;
}
ll add(int R)
{
	ll ret = -cnt[R] * cnt[R];
	cnt[R]++;
	ret += cnt[R] * cnt[R];
	return ret;
}
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
int main()
{
	int n, m;
	cin >> n >> m;
	int size = sqrt(n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].id = i, Q[i].be = Q[i].l / size;
//	cout << "RUA" << ' ' << m << endl;
	sort(Q, Q + m, cmp);
	int l = 0, r = 0;
	ll ret = -1;
	for (int i = 0; i < m; i++)
	{
		if (Q[i].l == Q[i].r)
		{
			ans1[Q[i].id] = 0, ans2[Q[i].id] = 1;
			continue;
		}
		while (r < Q[i].r)
		{
			ret += add(a[++r]);
		}
		while (r > Q[i].r)
		{
			ret -= remove(a[r]);
			r--;
		}
		while (l < Q[i].l)
		{
			ret -= remove(a[l]);
			l++;
		}
		while (l > Q[i].l)
		{
			ret += add(a[--l]);
		}
		
//		cout <<l<<' '<<r<<' '<< ret << endl;
		ans1[Q[i].id] = ret - (r - l + 1);
		ans2[Q[i].id] = 1LL*(r - l + 1)*(r - l);
		ll G = gcd(ans1[Q[i].id], ans2[Q[i].id]);
		ans1[Q[i].id] /= G;
		ans2[Q[i].id] /= G;
	}
	for (int i = 0; i < m; i++)
		printf("%lld/%lld\n", ans1[i], ans2[i]);
}
