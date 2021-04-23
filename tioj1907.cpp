#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
 
bool cmp(pii x, pii y){
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}
int t, n, w, h;
vector <pii> v;
vector <int> lis;
 
int main() {
    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        lis.clear();
        for (int i = 0; i < n; i++){
            cin >> w >> h;
            v.push_back({w, h});
        }
        sort(v.begin(), v.end(), cmp);
        for (pii i:v){
            if (lis.empty() || i.second > *(lis.end()-1)) lis.push_back(i.second);
            else {
                *lower_bound(lis.begin(), lis.end(), i.second) = i.second;
            }
        }
        cout << lis.size() << "\n";
    }
}
