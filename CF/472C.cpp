#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
int n,a[maxN];
char c1[maxN][52],c2[maxN][52];
char now[52],mox[52],mon[52];
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%s%s",c1[i],c2[i]);
    for(i=0;i<n;i++)
        cin>>a[i];
    strcpy(now,strcmp(c1[a[0]],c2[a[0]])<0?c1[a[0]]:c2[a[0]]);
    //puts(now);
    for(i=1;i<n;i++)
    {
        if(strcmp(c1[a[i]],c2[a[i]])>0)
        {
            strcpy(mox,c1[a[i]]);
            strcpy(mon,c2[a[i]]);
        }else{
            strcpy(mox,c2[a[i]]);
            strcpy(mon,c1[a[i]]);
        }
        if(strcmp(now,mon)<0)
        {
            strcpy(now,mon);//printf("1%s\n",now);
            continue;
        }
        else if(strcmp(now,mox)<0)
        {
            strcpy(now,mox);//printf("2%s\n",now);continue;
        }
        else
        {
            //printf("WA %s\n",now);continue;
            puts("NO");return 0;
        }
    }
    puts("YES");return 0;
}
