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
const long double eps=1e-8;
const int N=1e5+10;
struct Point{long double x,y;}p[N];
int n,i,flag1,flag2;
bool check(long double r){
	long double mn=2000000000000,mx=-2000000000000;
	for (int i=1;i<=n;++i){
		long double h=fabs(p[i].y-r);
		if (r<h) return 0;
		long double x=sqrt(r*r-h*h);
		mx=max(mx,p[i].x-x);
		mn=min(mn,p[i].x+x);
	}
	return mx<=mn;
}
int main(){
	read(n);
	for (i=1;i<=n;++i){
		scanf("%Lf%Lf",&p[i].x,&p[i].y);
		if (p[i].y>0) flag1=1;
		if (p[i].y<0) flag2=1;
		p[i].y=fabs(p[i].y);
	}
	if (flag1 && flag2) puts("-1");
	else{
		long double l=0,r=10000000000000000;
		for (i=1;i<=100;++i){
			long double mid=(l+r)/2.0;
			if (check(mid)) r=mid;
			else l=mid;
		}
		printf("%.10Lf\n",(l+r)/2.0);
	}
	return 0;
}