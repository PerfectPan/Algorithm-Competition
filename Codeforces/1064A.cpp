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
int a[3];
int main(){
	for (int i=0;i<3;++i) read(a[i]);
	sort(a,a+3);
	int num=a[2]-a[1]-a[0];
	if (num<0) puts("0");
	else printf("%d\n",abs(num)+1);
	return 0;
}