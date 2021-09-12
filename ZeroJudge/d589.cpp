#include <iostream>
using namespace std;
int main(){
    int coin[50],dpw[50],dprun[50],dprush[50];
    while(true){
        int num;
        cin>>num;
        if(!num)return 0;
        for(int i=0;i<num;i++)cin>>coin[i];
        dpw[0]=0;dprun[0]=coin[0];dprush[0]=coin[0]*2;
        for(int i=1;i<num;i++){
            dpw[i]=max(dpw[i-1],max(dprun[i-1],dprush[i-1]));
            dprun[i]=max(dpw[i-1],dprun[i-1])+coin[i];
            dprush[i]=max(dpw[i-1],dprun[i-1])+2*coin[i];
        }
        cout<<max(dpw[num-1],max(dprun[num-1],dprush[num-1]))<<endl;
    }
}
//dp
