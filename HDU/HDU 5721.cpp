#include<bits/stdc++.h>
using namespace std;
struct P
{
	int x, y, id;
	bool operator <(const P& B)const { return x < B.x; }
	P() {}P(int _x, int _y)
	{
		x = _x, y = _y;
	}
}p[100050];
typedef long long ll;
ll dis(P &A, P &B) { return 1LL * (A.x - B.x)*(A.x - B.x) + 1LL * (A.y - B.y)*(A.y - B.y); }
P Q[100050];
typedef pair<P, P> PII;
PII Divide(int l, int r)
{
	if (l == r) return make_pair(P(-1e9, -1e9), P(1e9, 1e9));
	int mid = (l + r) >> 1, tx = p[mid].x, tot = 0;
	PII d1 = Divide(l, mid), d2 = Divide(mid + 1, r);
	ll D1 = dis(d1.first, d1.second), D2 = dis(d2.first, d2.second);
	PII d;
	if (D1 < D2)
		d = d1;
	else
		d = d2;
	ll D = dis(d.first, d.second);
	for (int i = l, j = mid + 1; (i <= mid || j <= r); i++)
	{
		while (j <= r && (p[i].y > p[j].y || i > mid)) Q[tot++] = p[j], j++; //归并按y排序
		if (abs(p[i].x - tx) < D && i <= mid)  //选择中间符合要求的点
		{
			for (int k = j - 1; k > mid && j - k < 3; k--)
			{
				if (dis(p[i], p[k]) < D)
					D = dis(p[i], p[k]), d = make_pair(p[i], p[k]);
			}
			for (int k = j; k <= r && k - j < 2; k++)
			{
				if (dis(p[i], p[k]) < D)
					D = dis(p[i], p[k]), d = make_pair(p[i], p[k]);
			}
		}
		if (i <= mid) Q[tot++] = p[i];
	}
	for (int i = l, j = 0; i <= r; i++, j++) p[i] = Q[j];
	return d;
}

void go()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	sort(p + 1, p + 1 + n);
	//	for (int i = 1; i <= n; i++)p[i].id = i;
	PII Pi = Divide(1, n);
	long long ans = dis(Pi.first, Pi.second);
	ans = ans * (n - 2);
	//	cout << ans << endl;
	P L = Pi.first, R = Pi.second;
	ll rua = L.x, gua = L.y;
	for (int i = 1; i <= n; i++)
	{
		if (p[i].x == L.x&&p[i].y == L.y)
		{
			p[i].x = 10000000, p[i].y = 10000000;
			break;
		}
		//	cout << p[i].x << ' ' << p[i].y << endl;
	}
	sort(p + 1, p + 1 + n);
	PII Q = Divide(1, n);
	ll m = dis(Q.first, Q.second);
	ans += m;
	//	cout << m << endl;
	//	cout << Q.first.x << ' ' << Q.first.y << ' ' << Q.second.x << ' ' << Q.second.y << endl;
	for (int i = 1; i <= n; i++)
	{
		if (p[i].x == 10000000 && p[i].y == 10000000)
			p[i].x = rua, p[i].y = gua;

		//		cout << p[i].x << ' ' << p[i].y << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		if (p[i].x == R.x&&p[i].y == R.y)
		{
			p[i].x = 100000000, p[i].y = 100000000;
			break;
		}
	}
	sort(p + 1, p + 1 + n);
	Q = Divide(1, n);
	m = dis(Q.first, Q.second);
	ans += m;
	//	cout << m << endl;
	cout << ans << endl;
}
int main()
{
	int T; cin >> T; while (T--)
		go();
}//