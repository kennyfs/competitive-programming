#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t;
bool r;
int n,k,p;
int main(){
	Hirasawa_Yui_My_Wife
    cin>>t;
    while(t--){
        cin>>n>>k;
        p=0;
        for(int i=0;i<=n;i++){
            cout<<(p^i)<<endl;
            cin>>r;
            if(r)break;
            p^=(p^i);
        }
    }
}
