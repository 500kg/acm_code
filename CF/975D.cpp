#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+50;
#define mp make_pair
struct node
{
	long long x, y;
}A[N];
map<long long, int>M;
map<pair<long long, long long>, long long>P;
int main()
{
	long long n, a, b; cin >> n >> a >> b;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> b >> A[i].x >> A[i].y;
		ans += (M[A[i].x*a - A[i].y] - P[mp(A[i].x, A[i].y)]);
		M[A[i].x*a - A[i].y]++;
		P[mp(A[i].x, A[i].y)]++;
	}
	cout << ans * 2 << endl;

}
