#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int w[50000], v[50000];
int c[50000];
int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &w[i], &v[i]);
        for (int i = 0; i < n; i++)
            for (int j = m; j >= w[i]; j--)
                c[j] = max(c[j], c[j - w[i]] + v[i]);
        printf("%d\n", c[m]);
    }
}