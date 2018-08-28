//自己乘自己减西格玛儿子乘儿子/2

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int sz[maxn], dep[maxn];
int vis[maxn];
vector<int>G[maxn];
int sn, rt, rt_size;
typedef long long ll;
ll ans = 0;
int d[maxn], tot;
int maxi;
ll num[maxn];
ll cnt[maxn];
int v[maxn], p[maxn];
int Plen;
void initP()
{
	Plen = 0;
	for (int i = 2; i <= 200000; i++)
	{
		if (vis[i])continue;
		p[Plen++] = i;
		for (int j = i; j <= 200000; j += i)vis[j] = 1;
	}
}
const double PI = acos(-1.0);
//复数结构体
struct Complex
{
	double x, y; //实部和虚部 x+yi
	Complex(double tx = 0.0, double ty = 0.0)
	{
		x = tx;
		y = ty;
	}
	Complex operator-(const Complex &b) const
	{
		return Complex(x - b.x, y - b.y);
	}
	Complex operator+(const Complex &b) const
	{
		return Complex(x + b.x, y + b.y);
	}
	Complex operator*(const Complex &b) const
	{
		return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
	}
};
/*
* 进行FFT和IFFT前的反转变换。
* 位置i和 （i二进制反转后位置）互换
* len必须取2的幂
*/
Complex A[maxn * 2];
void change(Complex y[], int len)
{
	int i, j, k;
	for (i = 1, j = len / 2; i < len - 1; i++)
	{
		if (i < j)
			swap(y[i], y[j]);
		//交换互为小标反转的元素，i<j保证交换一次
		//i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
		k = len / 2;
		while (j >= k)
		{
			j -= k;
			k /= 2;
		}
		if (j < k)
			j += k;
	}
}
/*
* 做FFT
* len必须为2^k形式，
* on==1时是DFT，on==-1时是IDFT
*/
void fft(Complex y[], int len, int on)
{
	change(y, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for (int j = 0; j < len; j += h)
		{
			Complex w(1, 0);
			for (int k = j; k < j + h / 2; k++)
			{
				Complex u = y[k];
				Complex t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (on == -1)
		for (int i = 0; i < len; i++)
			y[i].x /= len;
}
void getroot(int pos, int fa)
{
	sz[pos] = 1;
	int rua = 0;
	for (int i = 0; i < G[pos].size(); i++)
	{
		int v = G[pos][i];
		if (v == fa || vis[v])continue;
		getroot(v, pos);
		sz[pos] += sz[v];
		rua = max(rua, sz[v]);
	}
	rua = max(rua, sn - sz[pos]);
	if (rua < rt_size)rt_size = rua, rt = pos;
}
//fft
//cal(u,num)
//gitdis
void getdis(int pos, int fa, int dis)
{
	d[tot++] = dis;
	maxi = max(dis, maxi);
	for (int i = 0; i < G[pos].size(); i++)
	{
		int v = G[pos][i];
		if (vis[v] || v == fa)continue;
		getdis(v, pos, dis + 1);
	}
}
ll cal(int pos, int dis)
{
	tot = 0, maxi = 0;
	getdis(pos, -1, dis);
	for (int i = 0; i < tot; i++)
	{
		num[d[i]]++;
	}
	int len = 1;
	maxi++;
	while (len < maxi * 2)len <<= 1;
	for (int i = 0; i < len; i++)
	{
		A[i] = Complex(num[i], 0);
	}
	fft(A, len, 1);
	for (int i = 0; i < len; i++)
		A[i] = A[i] * A[i];
	fft(A, len, -1);
	for (int i = 0; i < len; i++)
		cnt[i] = (ll)(A[i].x + 0.5);
	for (int i = 0; i < tot; i++)cnt[d[i] + d[i]]--;
	for (int i = 0; i < len; i++)cnt[i] /= 2;
	ll ret = 0;
	for (int i = 0; p[i] < len; i++)ret += cnt[p[i]];
	for (int i = 0; i < tot; i++)num[d[i]]--;
	//	for (int i = 0; i < len; i++)cout << i << ' ' << cnt[i] << endl;
	//	cout << endl;
	return ret;
}
void dfs(int pos)
{

	ans += cal(pos, 0);
	vis[pos] = 1;
	for (int i = 0; i < G[pos].size(); i++)
	{
		int v = G[pos][i];
		if (vis[v])continue;
		ans -= cal(v, 1);
		rt = 0, rt_size = sz[v];
		sn = sz[v];
		getroot(v, -1);
		dfs(rt);

	}

}


int main()
{
	initP();
	int n;
	cin >> n;
	ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(num, 0, sizeof(num));
	//	for (int i = 0; i <= n; i++)G[i].clear();
	for (int i = 1, u, v; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rt = 0, rt_size = 10000000;
	sn = n;
	getroot(1, -1); dfs(rt);
	ll ret = n*(n - 1);
	double ANS = 2.0*ans / ret;
	printf("%.10f\n", ANS);
	//	cout << ans << endl;
	return 0;
}