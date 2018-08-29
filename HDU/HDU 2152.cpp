#include<bits/stdc++.h>
using namespace std;
int N, M, n1[200], n2[200], i, j, k, last, last2;
int a[200], b[200];
int main()
{
	while (scanf("%d%d", &N, &M) == 2)
	{
		for (i = 0; i<N; i++)
			cin >> n1[i] >> n2[i];
		a[0] = 1;
		last = 0;
		for (i = 0; i<N; i++)
		{
			last2 = min(last + n2[i], M);
			memset(b, 0, sizeof(int)*(last2 + 1));
			for (j = n1[i]; j <= n2[i] && j <= last2; j++)
				for (k = 0; k <= last&&k + j <= last2; k++)
					b[k + j] += a[k];
			memcpy(a, b, sizeof(int)*(last2 + 1));
			last = last2;
		}
		if (last >= M)
			cout << a[M] << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
