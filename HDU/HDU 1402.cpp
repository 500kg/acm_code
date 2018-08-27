#include <bits/stdc++.h>
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

const int MAXN = 400010;
Complex a[MAXN], b[MAXN], c[MAXN];
int x[MAXN], y[MAXN];
int sum[MAXN];

int main()
{
	int n;
	string s1, s2;
	while (cin>>s1>>s2)
	{
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int t = 1;
		int len1 = s1.length();
		int len2 = s2.length();
		for (int i = 0; i < len1; i++)
			a[i] = Complex(s1[i]-'0', 0);
		for (int i = 0; i < len2; i++)
			b[i] = Complex(s2[i]-'0', 0);
		
		while (t < len1 * 2 || t < len2 * 2)
			t <<= 1;
		for (int i = len1; i < t; i++)
			a[i] = Complex(0, 0);
		for (int i = len2; i < t; i++)
			b[i] = Complex(0, 0);
		fft(a, t, 1);
		fft(b, t, 1);
		for (int i = 0; i < t; i++)
			c[i] = a[i] * b[i];
		fft(c, t, -1);
		for (int i = 0; i < t; i++)
			sum[i] = (int)(c[i].x + 0.5);
		

		for (int i = 0; i < t; i++)
		{
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
		int flag = 0;
		for (int i = t - 1; i >= 0; i--)
		{
			if (sum[i])printf("%d", sum[i]), flag = 1;
			else if (flag||i==0)printf("0");
		}cout << endl;
	}
	return 0;
}