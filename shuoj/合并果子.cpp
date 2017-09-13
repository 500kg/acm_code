#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,b,tem,ans;
    while(cin>>n)
    {
        ans=0;
        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            pq.push(a);
        }
        while(pq.size()>1)
        {
            a=pq.top();pq.pop();
            b=pq.top();pq.pop();
            tem=a+b;
            pq.push(tem);
            ans+=tem;

        }
cout<<ans<<endl;



    }
}
