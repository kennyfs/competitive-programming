#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)
using namespace std;
array<int, 400004> tag;
array<array<int, 2>, 400004> S;
void pull(int p){
    S[p][0] = S[lc][0] + S[rc][0];
    S[p][1] = S[lc][1] + S[rc][1];
}
void push(int p){
    if(tag[p]) swap(S[lc][0], S[lc][1]);
    if(tag[p]) swap(S[rc][0], S[rc][1]);
    tag[lc] ^= tag[p], tag[rc] ^= tag[p];
    tag[p] = 0;
}
void build(int p, int l, int r){
    if(l == r){
        S[p][0] = 1;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pull(p);
}
void update(int p, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return;
    if(ql <= l && qr >= r){
        swap(S[p][0], S[p][1]);
        tag[p] ^= 1;
        return;
    }
    push(p);
    update(lc, l, mid, ql, qr);
    update(rc, mid + 1, r, ql, qr);
    pull(p);
}
int query(int p, int l, int r, int ql, int qr, int t){
    if(qr < l || ql > r) return 0;
    if(ql <= l && qr >= r) return S[p][t];
    push(p);
    return query(lc, l, mid, ql, qr, t) + query(rc, mid + 1, r, ql, qr, t);
}
signed main(){
    int n, q, t, l, r, i = 1;
    string s;
    cin >> n >> q >> s;
    build(1, 1, n);
    for(char c : s){
        if(c == '1') update(1, 1, n, i, i);
        i++;
    }
    while(q--){
        cin >> t >> l >> r;
        if(t == 1){
            update(1, 1, n, l, r);
        }else{
            cout << query(1, 1, n, l, r, 0) * query(1, 1, n, l, r, 1) << "\n";
        }
    }
    return 0;
}
//AC
