#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
struct sol
{
    int p, s, r;
};
struct cmp
{
    bool operator()(sol a, sol b)
    {
        return a.s < b.s;
    }
};
array<int, 300004> vis;
array<pii, 300004> S;
array<sol, 300004> D;
bool comp(sol a, sol b)
{
    return a.r < b.r;
}
signed main()
{
    int n, rp = 0, sp = 0, ans = 0, p = 0, s, r;
    priority_queue<sol, vector<sol>, cmp> Q;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        ans += s;
        S[i] = {s, i};
        D[i].p = i;
        D[i].s = s;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> r;
        D[i].r = r;
    }
    sort(S.begin(), S.begin() + n);
    sort(D.begin(), D.begin() + n, comp);
    for(int k = 1; k <= n; k++)
    {
        while(rp < n && D[rp].r < k) Q.push(D[rp++]);
        if(!Q.empty() && p + sp < k)
        {
            if(!vis[Q.top().p]) p++;
            else ans += Q.top().s;
            vis[Q.top().p] = 2;
            Q.pop();
        }
        while(p + sp < k - 1)
        {
            if(vis[S[sp].ss] == 2) p--;
            sp++;
        }
        if(p + sp < k)
        {
            while(vis[S[sp].ss] == 2)
            {
                p--;
                sp++;
            }
            ans -= S[sp].ff;
            vis[S[sp].ss] = 1;
            sp++;
        }
        cout << ans;
        if(k < n) cout << " ";
    }
    cout << "\n";
    return 0;
}
