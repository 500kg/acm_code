#include<bits/stdc++.h>
#include<string.h>
using namespace std;
stack<char>g;
int main()
{
    int T;
    cin>>T;getchar();
    while(T--)
    {
        char c,t;
        int flag=0;
        while(!g.empty())
            g.pop();
        while((c=getchar())!='\n')
        {
            if(c=='(')g.push(c);
            else if(c=='[')g.push(c);
            else if(c==']'){
               if(!g.empty()&&g.top()=='[')
                    g.pop();
                else    flag=1;
            }
            else if(c==')'){

                if(!g.empty()&&g.top()=='(')
                    g.pop();
                else    flag=1;
            }
        }
        if(flag||!g.empty())puts("NO");
        else puts("YES");
    }
}
