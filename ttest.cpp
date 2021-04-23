#include <bits/stdc++.h>
using namespace std;
long long dp[100];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    dp[0] = 1;
    for (int i = 0 ; i < n ; ++i)
        dp[i + 1] = dp[i] << 1;
    for (int i = n ; i < m ; ++i)
        for (int j = i ; j > i - n - 1 ; --j)
            dp[i + 1] += dp[j];
    printf("%lld\n", dp[m]);
}
