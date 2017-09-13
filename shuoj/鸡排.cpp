#include<iostream>
#include<iomanip>
using namespace std;
double mypow(double x,int y){
    double ans = 1.0;
    for(int i=0;i<y;i++){
        ans *= x;
    }
    //cout << ans << endl;
    return ans;
}
long double func(int x,int y){
    long double ans = 1;
    long double d = 1;
    for(int i=0;i<y;i++){
        ans*=(x-i);
        d *= (i+1);
    }
    //cout << ans/d <<endl;
    return ans/d;
}
int main()
{
    int n,x;
    while(cin >> n >> x){
        int num;
        if(n%5 == 0)
            num = n/5;
        else num = n/5+1;
        double ans = 0;
        for(int i=0;i<num;i++){
            ans += mypow((99.0-x)*0.01,n-i-1) * mypow((1.0 - 0.01*(99.0-x)) , i) * func(n-1,i);
        }
        if(ans < 1e-6){
            cout << "Happy Yaoge!" << endl;
        }
        else cout << fixed << setprecision(6) << ans << endl;
    }
}
