#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x; 
}
const int N=10000+10;
int i,a,b,x;
int main(){
	read(a),read(b),read(x);
	bool flag=0;
	if (a>=b) flag=1;
	for (i=1;i<x;i++){
		if (i&1){
			if (flag) putchar('0'),a--;
			else putchar('1'),b--;
		}
		else{
			if (!flag) putchar('0'),a--;
			else putchar('1'),b--;
		}
	}
	if (i&1){
		if (flag){
			for (;a;a--) putchar('0');
			for (;b;b--) putchar('1');
		}
		else{
			for (;b;b--) putchar('1');
			for (;a;a--) putchar('0');
		}
	}
	else{
		if (flag){
			for (;b;b--) putchar('1');
			for (;a;a--) putchar('0');
		}
		else{
			for (;a;a--) putchar('0');
			for (;b;b--) putchar('1');
		}
	}
	puts("");
	return 0;
}