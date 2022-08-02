#include <bits/stdc++.h>
#define pb push_back
using namespace std;
array<int, 200004> V;
array<array<int, 2>, 200004> dp;
array<vector<int>, 200004> G;
int DP(int u, int pre, int t){
    if(dp[u][t]) return dp[u][t];
    dp[u][t] += t * V[u];
    for(int v : G[u]){
        if(v == pre) continue;
        dp[u][t] += max(DP(v, u, t ^ 1), DP(v, u, 0));
    }
    return dp[u][t];
}
signed main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> V[i];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    cout << max(DP(1, 0, 0), DP(1, 0, 1)) << "\n";
    return 0;
}
//只做了6分部分分
