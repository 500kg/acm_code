#include<bits/stdc++.h>
using namespace std;
char cccc[10000];
bool vis[30];
int v[30];
void init()
{
	for (int i = 0; i <= 26; i++)
		v[i] = i + 1;
	memset(vis, 0, sizeof(vis));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%s", cccc);
		printf("Expression: %s\n", cccc);
		int flag = 1;
		int sum = 0;
		char ch[10000];
		int len = 0;
		for (int i = 0; cccc[i]!='\0'; i++)
		{
			if (cccc[i] == ' ')continue;
			ch[len++] = cccc[i];
		}
		for (int i = 0; i < len; i++)
		{
			if (ch[i] == '+' || ch[i] == '-')//运算符
			{
				if ((ch[i] == '+'&&ch[i + 1] == '+' || ch[i] == '-'&&ch[i + 1] == '-') && ch[i + 2] <= 'z'&&ch[i + 2] >= 'a')
				{
					vis[ch[i + 2] - 'a'] = 1;
					if (ch[i] == '+')
						v[ch[i + 2] - 'a']++;
					else
						v[ch[i + 2] - 'a']--;
					i++;
				}
				else
				{
					if (ch[i] == '+')
						flag = 1;
					else
						flag = -1;
				}
			}
			else//字符
			{
				sum += flag*v[ch[i]-'a'];
				int flag2 = 0;
				if (!vis[ch[i] - 'a'])
				{
					flag2 = 1;
					vis[ch[i] - 'a'] = 1;
				}
				if (flag2&&ch[i + 1] == ch[i + 2])
				{
					if (ch[i + 1] == '+')
						v[ch[i] - 'a']++;
					else if (ch[i + 1] == '-')
						v[ch[i] - 'a']--;
					i += 2;
				}
			}

		}
		printf("value = %d\n", sum);
		for (int i = 0; i <= 26; i++)
			if (vis[i])
				printf("%c = %d\n", i + 'a', v[i]);
	}
}