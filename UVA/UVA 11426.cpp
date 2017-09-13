#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 4e6 + 50;
int eular[maxn];
long long ans[maxn];
void init()
{
    for (int i = 1; i < maxn; i++)
        eular[i] = i;
    for (int i = 2; i < maxn; i++)
        if (eular[i] == i)
            for (int j = i; j < maxn; j += i)
                eular[j] -= eular[j] / i;
    for (int i = 2; i < maxn; i++)
        for (int j = 1; j * i < maxn; j++)
            ans[i * j] += eular[i] * j;
    ans[0] = 0;
    for (int i = 1; i < maxn; i++)
        ans[i] += ans[i - 1];
}
int main()
{
    int n;
    init();
    while (scanf("%d", &n) == 1 && n)
    {
        printf("%lld\n", ans[n]);
    }
    return 0;
}