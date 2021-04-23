#include <iostream>
#define infinity 1<<29;
using namespace std;
int n,list[50000];
struct tree{
	struct node{
		int val;
		node *left=NULL, *right=NULL;
		node(int v):val{v} {}
		node(node* l,node* r){left=l;right=r;update();}
		void update(){val=max(left->val,right->val);}
	};
	node *root;
	node* init(int l,int r,int *v){
		if(l==r)return new node(v[l]);
		int m=l+r >>1;
		return new node(init(l,m,v),init(m+1,r,v));//will initialize the current node.
	}
	void modify(int index,int nv,node *now,int l=1,int r=n){//n is global variable that means the size of the list.
		if(l==r)now->val=nv,return;
		if(index>r||index<l)return;
		int m=l+r<<1;
		if(index>m){//in the left([m+1~r])
			modify(index,nv,now->left,m+1,r)
		}else{//in the right([l~m])
			modify(index,nv,now->right,l,m)
		}
		now->update();
	}
	//for practicing setting a segment tree
	int query(int ql,int qr,node *now,int l=1,int r=n){
		if(ql>r||qr<l)return -infinity;// l---r  ql---qr [OR] ql---qr l---r
		if(ql<=l&&qr>=r){//ql---l---r---qr
			return now->val;//no need for further query
		}
		//l--ql-r--qr [OR] ql--l--qr--r
		int m=l+r >>1;
		return max(query(ql,qr,now->left,l,m),
				   query(ql,qr,now->right,m+1,r));
	}
	void dump(node *now,int l=1,int r=n){
		cout<<"l:"<<l<<",r:"<<r<<",val:"<<now->val<<'\n';
		if(l==r)return;
		int m=l+r>>1;
		dump(now->left,l,m);
		dump(now->right,m+1,r);
	}
};
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//n is size of whole list
	cin>>n;
	
	for(int i=1;i<=n;++i)cin>>list[i];
	//debug:for(int i:list)cout<<i<<',';
	//init segment tree:
	struct tree t;
	t.root=t.init(1,n,list);
	t.dump(t.root);
	cout<<"\n\n";
	return 0;
	int qn;//number of queries
	cin>>qn;
	
	int ql,qr;
	for(int i=0;i<qn;++i){
		cin>>ql>>qr;
		int result=t.query(ql,qr,t.root);
		cout<<result<<'\n';//l=1,r=n as default
	}
}
