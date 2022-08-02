#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pb push_back
signed main(){
    int n; cin >> n;
    if(n & 1){
        cout << "-1\n";
        return 0;
    }
    vector<pii> ans;
    for(int i = 1; i <= n; i += 2){
            ans.pb(pii(i, i + 1));
        for(int j = i - 1; j >= 1; --j){
            ans.pb(pii(i, j));
        }
    }
    cout << ans.size() << '\n';
    for(auto [a, b]:ans) cout << a << ' ' << b << '\n';
}
