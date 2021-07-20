#include <iostream>
using namespace std;
const int N=300010;
int q,num;
int root,last;
string a;
unsigned ran(){
    static unsigned x=19;
    return ++(x*=0xdefaced);
}
struct node{
    int left=0,right=0;
    int key;
    unsigned pri;
    int sz;
    bool used=0;
    node(int key):key(key),pri(ran()){}
    node():pri(ran()){}
};
node treap[N];
int sz(int d)const{
	return (data[d].used)?data[d].sz:0;
}
void updatesz(int d){
	data[d].sz=(data[d].used)?sz(data[d].left)+sz(data[d].right)+1:0;
}
void merge(int& toedit,int a,int b){
	if(!data[a].used||!data[b].used)   toedit=(a)?a:b;
	if(data[a].pri>data[b].pri){
		toedit=a;
		merge(data[a].right,data[a].right,b);
	}else{
		toedit=b;
		merge(data[b].left,a,data[b].left);
	}
	updatesz(toedit);
}
bool exist(int now,int key){
	if(data[now].key==key)return 1;
	if(key>data[now].key&&data[now].right)return exist(data[now].right,key);//right is bigger
	else if(key<=data[now].key&&data[now].left)return exist(data[now].left,key);
	return 0;
}//if i delete a node, then i have to clean its father's right or left
int main(){
	cin>>q;
	cin>>a>>num;
	--q;
	node[1].key=num;
	root=1;last=2;
	while(q--){
		cin>>a>>num;
		if(a=="add"&&!exist(root,num)){
			
		}
	}
}
