#include <bits/stdc++.h>

using namespace std;


long long n, a, b, ra = 1e9+20, rb = 1e9+20;

bool s=0;
int main()
{



    cin >>n>>a>>b;

    if(a>b)s=1,swap(a,b);
    if(a*b>=6*n)ra=a,rb=b;
    for(long long int A=a;A*A<=6*n;A++)
    {
        long long int B=max(b,(6*n+A-1)/A);
        if(A*B<ra*rb)ra=A,rb=B;
    }
    if(s)swap(ra,rb);
    cout << ra * rb << '\n' << ra << ' ' << rb << '\n';
    return 0;
}

