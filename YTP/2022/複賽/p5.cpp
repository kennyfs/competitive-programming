#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a=0,b=0;
    //cin>>t;
    char c;
    //while(t--){
    while(cin>>c){
        //cin>>c;
        switch(c){
        case 'A':
            a++;
            break;
        case 'B':
            b++;
            break;
        case 'C':
            a--;b++;
            break;
        case 'D':
            a--;
            break;
        case 'E':
            b--;
            break;
        case 'F':
            a++;b--;
            break;
        }
    }
    if(a*b<0){
        cout<<max(abs(a),abs(b));
    }else{
        cout<<abs(a+b);
    }
}
//AC
