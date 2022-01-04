#include<unistd.h>
#define int long long
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline int RI(){static char c;int a;while(((c=RC())<'0'||c>'9')&&c!='-'&&c!=-1);if(c=='-'){a=0;while((c=RC())>='0'&&c<='9')a*=10,a-=c^'0';}else{a=c^'0';while((c=RC())>='0'&&c<='9')a*=10,a+=c^'0';}return a;}
struct pt{
    int x,y;
    bool operator==(pt b){
        if(x==b.x&&y==b.y)return 1;
        return 0;
    }
    pt operator-(pt o){return {x-o.x,y-o.y};}
    int operator^(pt o){return x*o.x+y*o.y;}
    int operator*(pt o){return x*o.y-y*o.x;}
};
bool onseg(pt a,pt b,pt o){//o on ab
    return ((a-o)*(b-o)==0)&&(((a-o)^(b-o))<=0);
}
int dir(pt a,pt b,pt o){
    int cross=(a-o)*(b-o);
    if(cross==0)return 0;
    if(cross>0)return 1;
    return -1;
}
bool intersect(pt &a,pt &b,pt &c,pt &d){//ab intersects cd
    if(onseg(c,d,a)||onseg(c,d,b)||onseg(a,b,c)||onseg(a,b,d))return 1;
    if(dir(a,b,c)*dir(a,b,d)<0&&dir(c,d,a)*dir(c,d,b)<0)return 1;
    return 0;
}
signed main(){
    int n;
    n=R();
    pt a,b,c,d;
    while(n--){
        a.x=RI();
        a.y=RI();
        b.x=RI();
        b.y=RI();
        c.x=RI();
        c.y=RI();
        d.x=RI();
        d.y=RI();
        if(intersect(a,b,c,d)){
            OB[OP++]='Y';
            OB[OP++]='E';
            OB[OP++]='S';
            OB[OP++]='\n';
        }else{
            OB[OP++]='N';
            OB[OP++]='O';
            OB[OP++]='\n';
        }
        if(OP>65516)write(1,OB,OP),OP=0;
    }
    write(1,OB,OP);
}
