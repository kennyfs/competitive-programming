#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,num;
string a;
unsigned ran(){
    static unsigned x=19;
    return ++(x*=0xdefaced);
}
struct node{
    node *left=NULL,*right=NULL;
    int key;
    unsigned pri;
    int sz;
    node(int key):key(key),pri(ran()){}
    node():pri(ran()){}
};
typedef node* pnode;
int sz(pnode t){
	return (t)?t->sz:0;
}
void update(pnode t){
	if(t)t->sz=1+sz(t->left)+sz(t->right);
	else t->sz=0;
}
void merge(pnode &t,pnode a,pnode b){//a<b, t is target
    if(!a||!b){
		if(a)t=a;
		else if(b)t=b;
		else return;
	}else{
		if(a->pri < b->pri){//a goes up
			merge(a->right,a->right,b);
			t=a;
		}else{
			merge(b->left,a,b->left);
			t=b;
		}
	}
    update(t);
}
void split(pnode now,int key,pnode &a,pnode &b){
    if(!now){
        a=b=NULL;
        return;
    }
    if(now->key < key){//now and now->left are less than key
        a=now;
        split(now->right,key,a->right,b);//the order of these two operates is ok
    }else{
        b=now;
        split(now->left,key,a,b->left);
    }
    update(now);
}
void insert(pnode &t,pnode it){
	pnode t1,t2;
	split(t,it->key,t1,t2);//t1 is less than it->key
	merge(t1,t1,it);
	merge(t,t1,t2);
}
void erase(pnode &t,int key){
    if(!t)return;
	if(key < t->key){//should be in left subtree
		erase(t->left,num);
	}else if(key > t->key){
		erase(t->right,num);
	}else{
		pnode it=t;
		merge(t,t->left,t->right);
		delete it;
	}
}
int query(pnode t,int num){
	if(!t)return -2000000000;
	if(sz(t->left)+1>num)return query(t->left,num);
	if(sz(t->left)+1==num)return t->key;
	if(!t->right)return -2000000000;
	return query(t->right,num-1-sz(t->left));
}
void dump(pnode t,int depth){
	if(!t)return;
	cout<<depth<<' '<<t->key<<' '<<sz(t)<<'\n';
	dump(t->left,depth+1);
	dump(t->right,depth+1);
}
bool exist(pnode t,int key){
	if(!t)return false;
	if(t->key==key)return true;
	if(key < t->key)return exist(t->left,key);
	return exist(t->right,key);
}
int main(){
	Hirasawa_Yui_My_Wife
    cin>>n;n--;
    cin>>a>>num;
    node *root=new node(num);
    root->sz=1;
    //dump(root,1);
    while(n--){
        cin>>a>>num;
        if(a=="add"&&!exist(root,num)){
			insert(root,new node(num));
		}else if(a=="erase"){
			erase(root,num);
		}else if(a=="query"){
			cout<<query(root,num)<<'\n';
		}
        //dump(root,1);
    }
}
