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
const double eps=1e-14;
const double INF=2000000000000000;
int i;
double ansx,ansy,ansz,a,b,c,d,e,f;
double dist(double x,double y,double z){return sqrt(x*x+y*y+z*z);}
double get(double x,double y){
	double A=c;
	double B=d*y+e*x;
	double C=a*x*x+b*y*y+f*x*y-1.0;
	double detla=B*B-4.0*A*C;
	if (detla<0) return INF;
	double x1=(-B+sqrt(detla))/(2.0*A);
	double x2=(-B-sqrt(detla))/(2.0*A);
	return dist(x,y,x1)>dist(x,y,x2)?x2:x1;
}
void SA(){
	double T=10000;
	double cx=ansx,cy=ansy,cz=ansz;
	while (T>eps){
		double nx=cx+(rand()*2-RAND_MAX)*T;
		double ny=cy+(rand()*2-RAND_MAX)*T;
		double nz=get(nx,ny);
		if (nz==INF){
			T=T*0.99;
			continue;
		}
		double detla=dist(nx,ny,nz)-dist(cx,cy,cz);
		if (detla<0) ansx=cx=nx,ansy=cy=ny,ansz=cz=nz;
		else if (exp(-detla/T)*RAND_MAX>rand()) cx=nx,cy=ny,cz=nz;
		T=T*0.99;
	}
}
int main(){
	srand(19260817);
	while (~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)){
		ansx=ansy=0;
		ansz=sqrt(1.0/c);
		SA();
		printf("%.7f\n",dist(ansx,ansy,ansz));
	}
	return 0;
}