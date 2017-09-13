/*Nadeko's birthday is approaching! As she decorated the room for the party, a long garland of Dianthus-shaped paper pieces was placed on a prominent part of the wall. Brother Koyomi will like it!

Still unsatisfied with the garland, Nadeko decided to polish it again. The garland has n pieces numbered from 1 to n from left to right, and the i-th piece has a colour si, denoted by a lowercase English letter. Nadeko will repaint at most m of the pieces to give each of them an arbitrary new colour (still denoted by a lowercase English letter). After this work, she finds out all subsegments of the garland containing pieces of only colour c — Brother Koyomi's favourite one, and takes the length of the longest among them to be the Koyomity of the garland.

For instance, let's say the garland is represented by "kooomo", and Brother Koyomi's favourite colour is "o". Among all subsegments containing pieces of "o" only, "ooo" is the longest, with a length of 3. Thus the Koyomity of this garland equals 3.

But problem arises as Nadeko is unsure about Brother Koyomi's favourite colour, and has swaying ideas on the amount of work to do. She has q plans on this, each of which can be expressed as a pair of an integer mi and a lowercase letter ci, meanings of which are explained above. You are to find out the maximum Koyomity achievable after repainting the garland according to each plan.

Input
The first line of input contains a positive integer n (1 ≤ n ≤ 1 500) — the length of the garland.

The second line contains n lowercase English letters s1s2... sn as a string — the initial colours of paper pieces on the garland.

The third line contains a positive integer q (1 ≤ q ≤ 200 000) — the number of plans Nadeko has.

The next q lines describe one plan each: the i-th among them contains an integer mi (1 ≤ mi ≤ n) — the maximum amount of pieces to repaint, followed by a space, then by a lowercase English letter ci — Koyomi's possible favourite colour.

Output
Output q lines: for each work plan, output one line containing an integer — the largest Koyomity achievable after repainting the garland according to it.


*/



#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}
int main()
{
    int n,m,p;
	int lo,hi,ans,cnt;
	char s[1502];
	char a;
    scanf("%d%s%d",&n,s,&p);
    for(;p--;)
    {
        scanf("%d %c",&m,&a);
		lo=hi=ans=cnt=0;
		while(hi<n) {
			if(cnt<=m) {
				if(s[hi]!=a)
					cnt++;
				hi++;
			}
			if(cnt>m) {
				if(s[lo]!=a)
					cnt--;
				lo++;
			}
			ans=max(hi-lo,ans);
		}
		printf("%d\n",ans);
    }
}
