#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<21;
char s[maxn];

typedef long long LL;
const LL mod = 1e9 + 7; LL b[maxn];
const LL rev2 = (mod + 1) >> 1;
LL num[maxn];
LL A[maxn];
void FWT(LL a[], int n) {
	for (int d = 1; d < n; d <<= 1) {
		for (int m = d << 1, i = 0; i < n; i += m) {
			for (int j = 0; j < d; j++) {
				LL x = a[i + j], y = a[i + j + d];
				//xor;
				a[i + j] = (x + y), a[i + j + d] = (x - y );
				//and
				//a[i+j]=x+y;
				//or
				//a[i+j+d]=x+y;
			}
		}
	}
}
void UFWT(LL a[], int n) {
	for (int d = 1; d < n; d <<= 1) {
		for (int m = d << 1, i = 0; i < n; i += m) {
			for (int j = 0; j < d; j++) {
				LL x = a[i + j], y = a[i + j + d];
				//xor
				a[i + j] = 1LL * (x + y)/2, a[i + j + d] = 1LL * (x - y)/2;
				//and
				//a[i+j] = x-y;
				//or
				//a[i+j+d] = y-x;
			}
		}
	}
}
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			b[j] = (b[j] << 1) + s[j] - '0';
	}
	for (int i = 0; i < m; i++)
		num[b[i]]++;
	LL len = 1LL << n;
	for (int i = 0; i < len; i++)
	{
		A[i] = A[i >> 1] + (i & 1);
	}
	for (int i = 0; i < len; i++)
		A[i] = min(A[i], n - A[i]);
	FWT(num, len); FWT(A, len);
	for (int i = 0; i < len; i++)A[i] = A[i] * num[i];
	UFWT(A, len);
	LL ans = A[0];
	for (int i = 0; i < len; i++)
		ans = min(ans, A[i]);
	cout << ans << endl;
}