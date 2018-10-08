#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
int n,A,B,C,D,E,F;
int get(int x,int y){
	if (x<A && y<B) return 1;
	if (x<A && y>B) return 2;
	if (x>A && y<B) return 3;
	if (x>A && y>B) return 4;
}
int main(){
	read(n);
	read(A),read(B),read(C),read(D),read(E),read(F);
	int pos1=get(C,D),pos2=get(E,F);
	puts(pos1==pos2?"YES":"NO");
	return 0;
}