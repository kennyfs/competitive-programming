#include <iostream>
#include<vector>
#include<map>
using namespace std;
vector<bool> vd;
map<int,vector<int> > mp;
void mark(int p){
    if(!vd[p])return;
    vd[p]=false;
    for(auto x:mp[p]){
        mark(x);
    }
}
int main(){
    int n,m,l,q;
    cin >> n >> m >> l >> q;
    for(int i=0;i<n;i++){
    	vd.push_back(true);
	}
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
    }
    for(int i=0;i<l;i++){
        int p;
        cin>>p;
        mark(p);
    }
    for(int i=0;i<q;i++){
        int see;
        cin>>see;
        if(vd[see]){
            cout<<"YA~~"<<endl;
        }else{
            cout<<"TUIHUOOOOOO"<<endl;
        }
    }
}
//WA，待解決
