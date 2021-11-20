#include <bits/stdc++.h>
#define int long long
#define N 200005
#define pii pair<int,int>
#define INF 5e18
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,a[N];

signed main(){
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n/2;i++)ans += a[i];
    cout<<ans<<"\n";
}
