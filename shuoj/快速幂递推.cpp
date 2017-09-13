#include<stdio.h>
#include<string.h>
#define mod 1000007
#define N 3
typedef long long LL;
struct Matrix
{
    LL mat[N][N];
};

Matrix unit_matrix =
{
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
}; //单位矩阵

Matrix mul(Matrix a, Matrix b) //矩阵相乘
{
    Matrix res;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            res.mat[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                res.mat[i][j] %= mod;
            }
        }
    return res;
}

Matrix pow_matrix(Matrix a, LL n)  //矩阵快速幂
{
    Matrix res = unit_matrix;
    while(n != 0)
    {
        if(n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int main()
{
    LL n, f1, f2, a, b, c, T;
    Matrix tmp, arr;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&f1, &f2, &a, &b, &c, &n);
        if(n == 0)
            printf("%lld\n",(f2-f1*b-c + mod)%mod);
        if(n == 1)
            printf("%lld\n",(f1+mod)%mod);
        else if(n == 2)
            printf("%lld\n",(f2+mod)%mod);
        else
        {
            memset(arr.mat, 0, sizeof(arr.mat));
            arr.mat[0][0] = f2;  arr.mat[1][0] = f1;  arr.mat[2][0] = 1;
            tmp.mat[0][0] = b;   tmp.mat[0][1] = a;   tmp.mat[0][2] = c;
            tmp.mat[1][0] = tmp.mat[2][2] = 1;
            tmp.mat[1][1] = tmp.mat[1][2] = tmp.mat[2][0] = tmp.mat[2][1] = 0;
            Matrix p = pow_matrix(tmp, n-2);
            p = mul(p, arr);
            LL ans = (p.mat[0][0] + mod) % mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
