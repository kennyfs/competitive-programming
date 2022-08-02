#include <bits/stdc++.h>
using namespace std;
const int N=15;
vector<int> a,wa;
int n;
double f(double x){
    double res=0,cur=1;
    for(int i=0;i<=n;++i){
        res+=a[i]*cur;
        cur*=x;
    }
    return res;
}
double wf(double x){
    double res=0,cur=1;
    for(int i=0;i<n;++i){
        res+=wa[i]*cur;
        cur*=x;
    }
    return res;
}
void test(){
    cout<<f(2./3.);
}
int main(){
    int in=1;
    while(cin>>in)a.push_back(in);
    reverse(a.begin(),a.end());
    n=a.size()-1;
    for(int i=1;i<=n;++i){
        wa.push_back(i*a[i]);
    }
    double x=0,rf,rwf;
    rf=f(x);
    rwf=wf(x);
    //cout<<rf<<' '<<rwf<<'\n';
    while(1){
        x=x-rf/rwf;
        //cout<<x<<'\n';
        rf=f(x);
        rwf=wf(x);
        //cout<<rf<<' '<<rwf<<'\n';
        if(abs(rf)<=0.0001)break;
    }
    cout<<fixed<<setprecision(2)<<x;
}
//AC
