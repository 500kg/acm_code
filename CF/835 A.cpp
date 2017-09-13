#include<bits/stdc++.h>
using namespace std;

int main()
{
	int s, v1, v2, p1, p2;
	cin >> s >> v1 >> v2 >> p1 >> p2;
	int t1 = s*v1 + 2 * p1;
	int t2 = s*v2 + 2 * p2;
	if (t1 > t2)puts("Second");
	else if (t1 == t2)puts("Friendship");
	else puts("First");
}