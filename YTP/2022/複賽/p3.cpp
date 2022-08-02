#include <bits/stdc++.h>
#define pb push_back
using namespace std;
array<int, 2000004> A, BIT;
void update(int p, int x){
    for(; p < 2000004; p += p & -p) BIT[p] = min(BIT[p], x);
}
int query(int p){
    int ans = 2 << 20;
    for(; p; p -= p & -p) ans = min(ans, BIT[p]);
    return ans;
}
void crepe(int n, array<int, 2000004> & S){
    int p = 0, l = 2 << 20;
    vector<pair<int, int>> L;
    for(int i = 1; i <= n; i++) L.pb({S[i], i});
    sort(L.begin(), L.end());
    for(auto [x, c] : L){
        if(x != l) p++, l = c;
        S[c] = p;
    }
}
signed main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, r, len = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        A[i] += n - i;
        A[i + n] = n - i;
    }
    crepe(n << 1, A);
    for(int &b : BIT) b = n + 1;
    for(int i = n; i; i--){
        len = max(len, query(A[i + n]) - i);
        update(A[i], i);
    }
    cout << len << "\n";
    return 0;
}
//AC
