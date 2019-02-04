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
const int N=1000+10;
char s[N],t[N];
bool ok(char ch){
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
int main(){
	scanf("%s",s);
	scanf("%s",t);
	int lena=strlen(s),lenb=strlen(t);
	if (lena==lenb){
		for (int i=0;i<lena;++i){
			if ((ok(s[i])&&ok(t[i]))||(!ok(s[i])&&!ok(t[i])));
			else return puts("No");
		}
		puts("Yes");
	}
	else puts("No");
	return 0;
}