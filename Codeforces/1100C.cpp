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
const double PI=acos(-1.0);
int n,r;
int main(){
	//cout<<cos(PI)<<endl;
	read(n),read(r);
	double ang=(n-2)*PI/(2.0*n);
	printf("%.10f\n",r*cos(ang)/(1-cos(ang)));
	return 0;
}