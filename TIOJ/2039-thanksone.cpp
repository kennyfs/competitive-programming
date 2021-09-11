#include <bits/stdc++.h>
#define int long long
using namespace std;
struct pii{
	int ff, ss;
	pii(){}
	pii(int f, int s){
		ff = f, ss = s;
	}
	pii operator+(pii p){
		return pii(ff + p.ff, ss + p.ss);
	}
};
int n, k;
array<int, 2000004> A;
array<array<pii, 2>, 2000004> dp;
pii max(pii a, pii b){
	if(a.ff != b.ff) return a.ff > b.ff? a : b;
	return a.ss > b.ss? a : b;
}
pii DP(int p){
	for(int i = 1; i <= n; i++){
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + pii(A[i], 0));
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + pii(p - A[i], 1));
	}
	return dp[n][0];
}
int BIS(){
	int l = -1e7, r = 0, mid;
	while(l != r){
		mid = (l + r) >> 1;
		if(DP(mid).ss < k) l = mid + 1;
		else r = mid;
	}
	return DP(l).ff - l * k;
}
signed main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	dp[0][0] = {0, 0};
	dp[0][1] = {-(1ll << 62), 0};
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	cout << BIS();
	return 0;
}
