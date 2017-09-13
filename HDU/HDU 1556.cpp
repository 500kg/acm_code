#include<bits/stdc++.h>
using namespace std;
int tree[100010], n;
void init() {
	memset(tree, 0, sizeof(tree));
}

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int num) {
	while (x <= n)
	{
		tree[x] += num;
		x += lowbit(x);
	}
}

int getsum(int x) {
	int sum = 0;
	while (x>0) {
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}

int main() {
	while (~scanf("%d", &n) && n) {
		init();
		for (int i = 1; i <= n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			update(a, 1);
			update(b + 1, -1);
		}
		for (int i = 1; i <= n - 1; i++)
			printf("%d ", getsum(i));
		printf("%d\n", getsum(n));
		//for (int i = 1; i <= n; i++) cout << tree[i] << endl;
	}
}