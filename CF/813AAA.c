#include <stdio.h>
int main()
{
	int n,m,sum,a,l,r;
	scanf("%d",&n);
	sum = 0;
	while (n--) {
		scanf("%d",&a);
		sum+=a;
	}
	scanf("%d",&m);
	while (m--) {
		scanf("%d%d",&l,&r);
		if (sum<=r) {
			printf("%d\n",sum>l?sum:l);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
