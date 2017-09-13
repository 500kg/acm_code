#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
//0110;
int a[25],b[25];
int numA,numB,len,flag;
void solveA()//第一张牌不翻转
{   int  i,num=0;
   for(i=1;i<len;i++)
    {   if(a[i-1]==1)
        {     a[i-1]^=1;
              a[i]^=1;
              if(i!=len-1)
              {   a[i+1]^=1;
			  }

			num++;
		}

	}
	if(a[len-1]==0)
	 {   	numA=num;
	       flag=1;
	 }

}
void solveB()//第一张牌翻转
{    int i, num=0;
     b[0]^=1;
     b[1]^=1;
     num++;
     for(i=1;i<len;i++)
     {    if(b[i-1]==1)
           {    b[i-1]^=1;
                b[i]^=1;
                if(i!=len-1)
                 b[i+1]^=1;
                num++;
		   }
	 }
	 if(b[len-1]==0)
	 {    numB=num;
	      flag=1;
	 }
	 return ;
}
int main()
{    char s[25];
     int i;
     while(scanf("%s",s)!=EOF)
     {    flag=0;
          numA=numB=0xfffffff;
	      len=strlen(s);
	     for(i=0;i<len;i++)
          {    a[i]=b[i]=s[i]-'0';
		  }
		  solveA();
		  solveB();
		  if(flag==0)
		    printf("NO\n");
		  else
		    {   int ans=min(numA,numB);
		        printf("%d\n",ans);
			}

	 }
	 return 0;
}
