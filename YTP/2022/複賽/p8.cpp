#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)
using namespace std;
array<int, 800004> man, mix, tag, L, R, ltag, rtag, X;
void push(int p){
    if(tag[p]){
        mix[lc] = tag[p], tag[lc] = tag[p];
        mix[rc] = tag[p], tag[rc] = tag[p];
    }
    if(ltag[p]){
        L[lc] = ltag[p], ltag[lc] = ltag[p];
        L[rc] = ltag[p], ltag[rc] = ltag[p];
    }
    if(rtag[p]){
        R[lc] = rtag[p], rtag[lc] = rtag[p];
        R[rc] = rtag[p], rtag[rc] = rtag[p];
    }
    tag[p] = ltag[p] = rtag[p] = 0;
}
void pull(int p){
    man[p] = min(man[lc], man[rc]);
    mix[p] = max(mix[lc], mix[rc]);
}
void update(int p, int l, int r, int ql, int qr, int x, int t){
    if(ql > qr || qr < l || ql > r) return;
    if(ql <= l && qr >= r){
        if(t == 1){
            mix[p] = x;
            tag[p] = x;
        }else if(t == 2){
            L[p] = x;
            ltag[p] = x;
        }else if(t == 3){
            R[p] = x;
            rtag[p] = x;
        }else{
            man[p] = x;
        }
        return;
    }
    push(p);
    update(lc, l, mid, ql, qr, x, t);
    update(rc, mid + 1, r, ql, qr, x, t);
    pull(p);
}
int query(int p, int l, int r, int ql, int qr, int t){
        if(qr < l || ql > r) return (t? 0 : 1 << 30);
        if(ql <= l && qr >= r){
            if(t == 1){
                return mix[p];
            }else if(t == 2){
            return L[p];
            }else if(t == 3){
                return R[p];
            }else{
                return man[p];
            }
        }
        push(p);
        if(t) return max(query(lc, l, mid, ql, qr, t), query(rc, mid + 1, r, ql, qr, t));
        return min(query(lc, l, mid, ql, qr, t), query(rc, mid + 1, r, ql, qr, t));
}
signed main(){
    int n, x, ans, p, l, r;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> X[i];
        update(1, 1, n, i, i, X[i], 0);
    }
    update(1, 1, n, 1, n, X[query(1, 1, n, 1, n, 0)] * n, 1);
    ans = query(1, 1, n, 1, n, 1);
    for(int i = 0; i <= n; i++){
        p = query(1, 1, n, 1, n, 0);
        l = query(1, 1, n, p, p, 2);
        r = query(1, 1, n, p, p, 3);
        update(1, 1, n, p, p, 1 << 30, 0);
        update(1, 1, n, l, p - 1, (p - l) * X[query(1, 1, n, l, p - 1, 0)], 1);
        update(1, 1, n, p + 1, r, (r - p) * X[query(1, 1, n, p + 1, r, 0)], 1);
        update(1, 1, n, l, p - 1, p - 1, 3);
        update(1, 1, n, p + 1, r, p + 1, 2);
        ans = max(ans, query(1, 1, n, 1, n, 1));
    }
    cout << ans << "\n";
    return 0;
}
//0分，謝一在耍毒瘤
