#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> PII;
const int maxn = 5e6 + 5;
vector <int> v[maxn];
map<PII, int> acm;
/*nn��ֵֻ��500000500000��������ȴ�кܶ࣬�������껹�и��ģ�
��������Ȼ�ǲ����ʵġ����ǽ�������һ��ӳ�䣨��ÿ����ͬ����
��ӳ�䵽һ������������map<PII, int>[1]��Ȼ�����ǾͿ��Զ�ÿ
�����꽨��һ��vector�������Ŀ��������֮�����򼴿ɡ�--fromCSL*/
int main()
{
    int n;
    scanf("%d", &n);
    int tot = 0;             //��������
    while (n--)
    {
        int id, x, y;
        scanf("%d%d%d", &id, &x, &y);
        PII tmp = mp(x, y);
        if (!acm.count(tmp))           //������δ�����������ʹ����+1
            acm[tmp] = tot++;
        v[acm[tmp]].pb(id);           //acm[tmp]�ﴢ������x,y�����䱾��ֵΪ���������š�
                                       //��v[���]ĩβ����id
    }
    for (int i = 0; i < tot; i++)
        sort(v[i].begin(), v[i].end());     //��ÿ������������id��������
    scanf("%d", &n);
    while (n--)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", v[acm[mp(x, y)]][k - 1]);    //v[���]�е�k-1����
    }
    return 0;
}
