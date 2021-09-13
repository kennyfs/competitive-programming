#include <bits/stdc++.h>
using namespace std;
array<array<int, 204>, 204> S;
array<int, 80012> BIT;
void update(int p, int v){
	for(; p < 80012; p += (p & -p)) BIT[p] = min(BIT[p], v);
}
int query(int p){
	int ans = 412;
	for(; p > 0; p -= p & -p) ans = min(ans, BIT[p]);
	return ans;
}
int solve(int n, int m){
	int ans = 0, sum;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			sum = 0;
			for(int k = 0; k < 80012; k++) BIT[k] = 412;
			for(int k = 1; k <= m; k++){
				sum += S[j][k] - S[i - 1][k];
				ans = max(ans, (j - i + 1) * (k - query(40004 + sum) + 1));
				update(40004 + sum, k);
			}
		}
	}
	return ans;
}
signed main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	int t, n, m, x;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> x;
				S[i][j] = S[i - 1][j] + (x? -1 : 1);
			}
		}
		cout << solve(n, m) << "\n";
	}
	return 0;
}
//WA
