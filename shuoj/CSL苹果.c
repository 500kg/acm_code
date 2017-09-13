#include<stdio.h>

int coun(int m, int n){
    if (m == 0 || n == 1)
        return 1;
    if (n > m)
        return coun(m, m);
    else
        return coun(m, n - 1) + coun(m - n, n);}
int main()
{
    int m, n;
    while (scanf("%d",&m)==1){

        int res = coun(m, m);
        printf("%d\n",res);
    }
    return 0;
}

