#include <unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>65516)write(1,OB,OP),OP=0;}
signed main(){
    int a;
    a=R();
    while(a--){
        char c;
        do{
            c=RC();
            OB[OP++]=c;
        }while(c!='\n');
        OP--;
        OB[OP++]=',';
        OB[OP++]=' ';
        OB[OP++]='h';
        OB[OP++]='a';
        OB[OP++]='p';
        OB[OP++]='p';
        OB[OP++]='y';
        OB[OP++]=' ';
        OB[OP++]='n';
        OB[OP++]='e';
        OB[OP++]='w';
        OB[OP++]=' ';
        OB[OP++]='y';
        OB[OP++]='e';
        OB[OP++]='a';
        OB[OP++]='r';
        OB[OP++]='!';
        OB[OP++]='!';
        OB[OP++]='!';
        OB[OP++]='\n';
        if(OP>65516)write(1,OB,OP),OP=0;
    }
    write(1,OB,OP);
}
