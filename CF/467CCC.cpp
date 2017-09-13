
 #include <iostream>
using namespace std;

const int N = 5005;
long long p[N];
long long dp[N][N];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {cin >> p[i];p[i] += p[i-1];}

  for (int i = m; i <= n; i++)
    for (int j = 1; j <= k; j++)
      dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + p[i] - p[i-m]);
  cout << dp[n][k] << endl;
  return 0;
}
