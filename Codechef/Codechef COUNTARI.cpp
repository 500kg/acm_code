#include<bits/stdc++.h>
using namespace std;
const int maxn = 100050;
typedef long long ll;
int a[maxn];
ll l[maxn], r[maxn];
int li[maxn], ri[maxn];

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

Complex A[maxn], B[maxn];
int main()
{
	int n;
	cin >> n;
	int maxi = 0, len = 1;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), r[a[i]]++, maxi = max(maxi, a[i]);
	int size = 2000;
	maxi = (maxi + 1) * 2;
	while (len <= maxi)len <<= 1;
	int m = n / size + ((n%size) ? 1 : 0);
	for (int i = 1; i <= m; i++)li[i] = ri[i - 1] + 1, ri[i] = ri[i - 1] + size; ri[m] = n;
//	for (int i = 1; i <= m; i++)cout << li[i] << ' ' << ri[i] << endl;
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = li[i]; j <= ri[i]; j++)r[a[j]]--;
		for (int j = 0; j < len; j++)A[j] = Complex(l[j], 0);
		for (int j = 0; j < len; j++)B[j] = Complex(r[j], 0);
		fft(A, len, 1); fft(B, len, 1);
		for (int j = 0; j < len; j++)A[j] = A[j] * B[j];
		fft(A, len, -1);
		for (int j = li[i]; j <= ri[i]; j++)ans += (ll)(A[2 * a[j]].x + 0.5);
	
		for (int j = li[i]; j <= ri[i]; j++)
		{	//cout << ans << endl;
	//	cout << l[a[j]] << ' ' << r[a[j]] << endl;
			for (int k = li[i]; k < j; k++)if (a[j] * 2 - a[k] >= 0)ans += r[a[j] * 2 - a[k]];
			for (int k = j+1; k <= ri[i]; k++)if (a[j] * 2 - a[k] >= 0)ans += l[a[j] * 2 - a[k]];
			l[a[j]]++;
		}
	}
	cout << ans << endl;
}
