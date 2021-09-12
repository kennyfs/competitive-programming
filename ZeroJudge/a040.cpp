#include <iostream>
#include <vector>
#define Hirasawa_Yui_my_wife ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
vector<int> degits;
int power(int a,int b,int cur){
    return (b==1)?cur:power(a,b-1,cur*a);
}
int main(){
    Hirasawa_Yui_my_wife
    int down,up,num;
    bool yes=0;
    cin>>down>>up;
    for(int i=down;i<=up;++i){
        degits.clear();
        num=i;
        while(num){
            degits.push_back(num%10);
            num/=10;
        }
        num=0;
        int sz=degits.size();
        for(int n:degits){
            num+=power(n,sz,n);
        }
        if(num==i)cout<<i<<' ',yes=1;
    }
    if(!yes)cout<<"none\n";
}
//O(nlongn)枚舉，水題
