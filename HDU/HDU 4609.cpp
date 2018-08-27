#include<bits/stdc++.h>
using namespace std;

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

typedef long long ll;
const int maxn = 400010;
Complex a[maxn], b[maxn], c[maxn];
ll x[maxn];
ll sum[maxn];
ll num[maxn];
ll rua[maxn];
void solve()
{
	ll n; scanf("%lld", &n);
	memset(num, 0, sizeof(num));
	memset(rua, 0, sizeof(sum));
	for (int i = 0; i < n; i++)scanf("%lld", &x[i]), num[x[i]]++;
	sort(x, x + n);
	int len1 = x[n - 1]+1, len = 1;
	while (len < 2*len1+5)len <<= 1;
	for (int i = 0; i < len1; i++)a[i] = Complex(num[i], 0);
	for (int i = len1; i < len; i++)a[i] = Complex(0, 0);
	fft(a, len, 1);
	for (int i = 0; i < len; i++)a[i] = a[i] * a[i];
	fft(a, len, -1);
	for (int i = 0; i < len; i++)rua[i] = (ll)(a[i].x + 0.5);
	for (int i = 0; i < n; i++)rua[x[i] + x[i]]--;
	for (int i = 0; i < len; i++)rua[i] /= 2;
	for (int i = 1; i <= len; i++)sum[i] = sum[i - 1] + rua[i];
//	for (int i = 0; i < len; i++)cout << sum[i] << ' '; cout << endl;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += sum[len] - sum[x[i]];
		ans -= 1LL * (n - i - 1)*i;
		ans -= 1LL * (n - i - 1)*(n - i - 2) / 2;
		ans -= (n - 1);
	}
	ll tot = 1LL*n*(n - 1)*(n - 2) / 6;
	printf("%.7lf\n", ans*1.0 / tot);
}
int main()
{
	int T; cin >> T; while (T--)
	{
		solve();
	}
}