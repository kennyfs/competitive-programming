#include <iostream>
#include <algorithm>
using namespace std;
string s;
struct word{
    char c;
    int cnt;
}mydata[26];
int main(){
    cin>>s;
    for(int i=0;i<26;++i){
        mydata[i].c='A'+i;
    }
    for(int i=0;i<s.size();++i){
        mydata[s[i]-'A'].cnt++;
    }
    sort(mydata,mydata+26,[&](word a,word b){return a.cnt==b.cnt?a.c<b.c:a.cnt>b.cnt;});
    for(int i=0;i<26;++i){
        if(mydata[i].cnt==0)break;
        cout<<mydata[i].c;
    }
}
