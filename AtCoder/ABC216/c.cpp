#include <iostream>
#include <stack>
#define ll long long
using namespace std;
ll n;
stack<char> stk;
int main(){
    cin>>n;
    while(n>>1){
        if(n&1)stk.push('A');
        stk.push('B');
        n>>=1;
    }
    if(n)stk.push('A');
    while(!stk.empty())cout<<stk.top(),stk.pop();
}
