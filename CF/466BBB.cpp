#include <bits/stdc++.h>

using namespace std;

//1000000000 1 1
#define int long long

int n, a, b, ra = 1e9+20, rb = 1e9+20;
bool s;

int32_t main(){
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b; if (a > b) s = 1, swap(a, b);
	if (a*b >= 6*n) ra = a, rb = b;
	for (int A = a; A*A <= 6*n; A ++){
	 	int B = max(b, (6*n + A-1) / A);
		if (A*B < ra*rb) ra = A, rb = B;
	}
	if (s) swap(ra, rb);
	cout << ra * rb << '\n' << ra << ' ' << rb << '\n';
}
