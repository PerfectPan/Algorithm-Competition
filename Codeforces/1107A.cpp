#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int T,n,i;
char s[N];
int main(){
	for (read(T);T--;){
		read(n);
		scanf("%s",s+1);
		if (n==2){
			if (s[1]<s[2]){
				puts("YES");
			puts("2");
			printf("%c %c\n",s[1],s[2]);
			}
			else{
				puts("NO");
			}
		}
		else{
			puts("YES");
			puts("2");
			printf("%c %s\n",s[1],s+2);
		}
	}
	return 0;
}