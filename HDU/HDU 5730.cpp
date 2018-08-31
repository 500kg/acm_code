#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
* on == 1时是DFT，on == -1时是IDFT
* a[i]=complex(a[i],0)  /  complex(0,0)
fft(a,len,1)fft(b,len,1)
for(int i=0;i<t;i++)c[i]=a[i]*b[i]
fft(c,len,-1)
sum[i] = (int)(c[i].x + 0.5);
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

const int MAXN = 400010;
Complex x1[MAXN], x2[MAXN];
ll a[MAXN];
ll dp[MAXN];
const int MOD = 313;
void cdq(int l, int r)
{
	if (l == r)return;
	int mid = l + r >> 1;
	cdq(l, mid);
	int len = 1;
	while (len <= (r - l + 1) * 2)len <<= 1;
	for (int i = 0; i < len; i++)
	{
		if (l + i <= mid)x1[i] = Complex(dp[i + l], 0);
		else x1[i] = Complex(0, 0);
		if (l + i < r)x2[i] = Complex(a[i + 1], 0);
		else x2[i] = Complex(0, 0);
	}
	fft(x1, len, 1); fft(x2, len, 1);
	for (int i = 0; i < len; i++)x1[i] = x1[i] * x2[i];
	fft(x1, len, -1);
	for (int i = mid + 1; i <= r; i++)dp[i] = (dp[i] + (ll)(x1[i - l - 1].x + 0.5)) % MOD;
	cdq(mid + 1, r);
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (!n)return 0;
		a[0] = 0;
		for (int i = 1; i <= n; i++)scanf("%lld", &a[i]), a[i] %= MOD;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		cdq(0, n);
	//	for (int i = 1; i <= n; i++)cout << dp[i] << endl;
		printf("%lld\n", dp[n]);
	}
}