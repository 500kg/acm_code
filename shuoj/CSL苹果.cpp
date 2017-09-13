#include<iostream>
#include<string>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;
int coun(int m, int n);
int main(){
    int m, n;
    while (scanf("%d%d",&m,&n)==2){

        int res = coun(m, n);
        printf("%d\n",res);
    }
    return 0;
}
int coun(int m, int n){
    if (m == 0 || n == 1)
        return 1;
    if (n > m)
    {
        printf("%d\n",coun(m,m));
        return coun(m, m);
    }

    else
     {
         printf("%d\n",coun(m, n - 1)+coun(m - n, n));
         return coun(m, n - 1) + coun(m - n, n);
     }
}
