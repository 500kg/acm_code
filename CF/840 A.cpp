#include<bits/stdc++.h>
using namespace std;  
#define N 200005  
  
int a[N],ans[N];  
struct node{  
    int num;  
    int i;  
}b[N];   
  
int cmp(node a, node b){  
    return a.num > b.num;  
}  
  
int main()  
{  
    int n;  
    cin >> n;  
    for(int i = 0;i < n; ++i)  
        cin >> a[i];  
      
    for(int i = 0;i < n; ++i){  
        b[i].i = i;  
        cin >> b[i].num;  
    }  
      
    sort(a,a+n);  
      
    sort(b,b+n,cmp);  
          
    for(int i = 0;i < n; ++i)  
        ans[b[i].i] = a[i];  
    for(int i = 0;i < n; ++i)  
        cout << ans[i] << " ";  
    return 0;  
}  