#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> PII;
const int maxn = 5e6 + 5;
vector <int> v[maxn];
map<PII, int> acm;
/*nn的值只有500000500000，但坐标却有很多，而且坐标还有负的，
开数组显然是不合适的。考虑将坐标做一个映射（将每个不同的坐
标映射到一个整数），即map<PII, int>[1]。然后我们就可以对每
个坐标建立一个vector来存放题目。输入完之后排序即可。--fromCSL*/
int main()
{
    int n;
    scanf("%d", &n);
    int tot = 0;             //坐标总数
    while (n--)
    {
        int id, x, y;
        scanf("%d%d%d", &id, &x, &y);
        PII tmp = mp(x, y);
        if (!acm.count(tmp))           //对所有未保存过的坐标使总数+1
            acm[tmp] = tot++;
        v[acm[tmp]].pb(id);           //acm[tmp]里储存坐标x,y，，其本身值为此坐标的序号。
                                       //在v[序号]末尾插入id
    }
    for (int i = 0; i < tot; i++)
        sort(v[i].begin(), v[i].end());     //对每个坐标所含的id进行排序
    scanf("%d", &n);
    while (n--)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", v[acm[mp(x, y)]][k - 1]);    //v[序号]中第k-1个数
    }
    return 0;
}
