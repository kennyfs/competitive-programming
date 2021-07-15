寫一點zj水題壓壓驚，練了一下DFS、STL等等。  
另我最驚訝的是，竟然有要壓常才過得了的題目：c782  
主要是cin太慢  
要用：  
```cpp
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
```
或  
```cpp
char c;
int s;
int read(){
	s=c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
```
之類的  
[放一下pragma壓常連結](https://www.mina.moe/archives/3766)，不知道效果有沒有很明顯。
