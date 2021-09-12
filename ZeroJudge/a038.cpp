#include <iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a;
  cin>>a;
  bool firstnonzero=false;
  if(a==0){
    cout<<'0';
    return 0;
  }
  while(a>0){
    if((a%10)==0){
      if(!firstnonzero){
        a/=10;
        continue;
      }
    }else
      firstnonzero=true;
    cout<<a%10;
    a/=10;
  }
  return 0;
}
//實作，數學
