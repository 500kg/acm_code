#include<bits/stdc++.h>
using namespace std;



struct Node
{
	char str[33];
	int id;
	int sorted;
}a[300005];
bool cmpid(Node a, Node b)
{
    return a.id<b.id;
}
bool cmpstr(Node a, Node b)
{
    if(strcmp(a.str,b.str)<0)
        return true;
    else return false;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i].str);
        a[i].id=i;
    }
    sort(a,a+n,cmpstr);
    for(i=0;i<n;i++)
        a[i].sorted=i+1;
    sort(a,a+n,cmpid);
    for(i=0;i<n;i++)
        printf("%d\n",a[i].sorted);
}
