#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 1000002;
int ne[N];
char S[N], T[N];
int slen, tlen;

int len;
void getNext()
{
	int j, k;
	j = 0; k = -1; 
	ne[0] = -1;
	tlen = strlen(T);
	while (j < tlen)
		if (k == -1 || T[j] == T[k])
			ne[++j] = ++k;
		else
			k = ne[k];
	len = j;
}

int main()
{
	while (cin >> T)
	{
		getNext();
		vector<int>ans;
		int t = ne[len - 1];
		while (t != -1) {
			if (T[t] == T[len - 1])
				ans.push_back(t + 1);
			t = ne[t];
		}
		ans.push_back(len);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
		}
	}
}