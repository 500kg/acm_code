#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        for(int i=1;i<=x/2;i++)
        {
            for(int j=1;j<i;j++)
                printf(" ");
            printf("X");
            for(int j=1;j<=x-2*i;j++)
                printf(" ");
            printf("X\n");
        }
        for(int i=1;i<=x/2;i++)
            printf(" ");
        printf("X\n");
        for(int i=x/2;i>=1;i--)
        {
            for(int j=1;j<i;j++)
                printf(" ");
            printf("X");
            for(int j=1;j<=x-2*i;j++)
                printf(" ");
            printf("X\n");
        }
        printf("\n");
    }
}
