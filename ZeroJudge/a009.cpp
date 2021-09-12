#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(char x:s){
        cout<<char(int(x)-7);
    }
    cout<<endl;
}
//水題
