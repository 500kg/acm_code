#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
 cin >> n;
    if(n<=3)printf("NO\n");
    else {printf("YES\n");
        if(n%2==0){
            printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
            for(i=6;i<=n;i+=2)
                printf("%d - %d = %d\n24 * 1 = 24\n",i,i-1,1);
    }
    else {
        printf("1 + 2 = 3\n3 * 4 = 12\n5 - 3 = 2\n12 * 2 = 24\n");
        for(i=7;i<=n;i+=2)
            printf("%d - %d = %d\n24 * 1 = 24\n",i,i-1,1);
    }

}
}
