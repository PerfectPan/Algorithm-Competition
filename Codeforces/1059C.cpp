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
int n,i;
int main(){
	read(n);
	if (n==1) puts("1");
	else if (n==2) puts("1 2");
	else if (n==3) puts("1 1 3");
	else{
		int odd=(n+1)/2;
		for (i=1;i<=odd;++i){
			printf("1 ");
		}
		n-=odd;
		int g=2;
		for (;;){
			if (n==0) break;
			if (n<=3){
				if (n==1) printf("%d\n",g);
				else if (n==2) printf("%d %d\n",g,2*g);
				else printf("%d %d %d\n",g,g,3*g);
				break;
			}
			int num=(n+1)/2;
			for (i=1;i<=num;++i){
				printf("%d ",g);
			}
			g<<=1;
			n-=num;
		}
	}
	return 0;
}