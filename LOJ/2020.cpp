#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=3e5+10;
const double PI=acos(-1.0);
struct cd{
    double x,y;
    cd(double a=0,double b=0):x(a),y(b){}
};
inline cd operator +(cd a,cd b){return cd(a.x+b.x,a.y+b.y);}
inline cd operator -(cd a,cd b){return cd(a.x-b.x,a.y-b.y);}
inline cd operator *(cd a,cd b){return cd(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
inline cd conj(cd a){return cd(a.x,-a.y);}
struct FastFourierTransform{
    int n,rev[N];
    cd w[2][N];
    void init(int lim){
        n=1;int k=0;
        while (n<lim) n<<=1,k++;
        for (int k=0;k<n;k++){
            w[0][k]=cd(cos(2*PI/n*k),sin(2*PI/n*k));
            w[1][k]=conj(w[0][k]);
        }
    }
    void fft(cd *a,int v){
        for (int i=0,j=0;i<n;i++){
            if(i<j) swap(a[i],a[j]);
            for (int l=n>>1;(j^=l)<l;l>>=1);
        }
        for (int l=2;l<=n;l<<=1){
            int m=l>>1;
            for (int i=0;i<n;i+=l){ 
                for (int k=0;k<m;k++){
                    cd t=w[v][n/l*k]*a[i+k+m];
                    a[i+k+m]=a[i+k]-t;
                    a[i+k]=a[i+k]+t;
                }
            }
        }
        if (!v) return;
        for (int i=0;i<n;i++) a[i].x/=n;
    }
    void mul(cd *a,cd *b,int m){
        init(m);
        fft(a,0),fft(b,0);
        for(int i=0;i<n;i++) a[i]=a[i]*b[i];
        fft(a,1);
    }
}f;
int n,m,i,sumx,sumy,sqrx,sqry,x[N],y[N];
cd a[N],b[N];
ll ans;
int main(){
	read(n),read(m);
	for (i=0;i<n;i++){
		read(x[i]);
		sumx+=x[i];
		sqrx+=x[i]*x[i];
	}
	for (i=0;i<n;i++){
		read(y[i]);
		sumy+=y[i];
		sqry+=y[i]*y[i];
	}
	int v1=floor((double)(sumx-sumy)/-n);
	int v2=ceil((double)(sumx-sumy)/-n);
	ans=min(n*v1*v1+2*(sumx-sumy)*v1,n*v2*v2+2*(sumx-sumy)*v2)+sqrx+sqry;
	for (i=0;i<n;i++) a[i].x=x[n-i-1];
	for (i=0;i<n*2;i++) b[i].x=y[i%n];
	f.mul(a,b,3*n);
	ll mx=0;
	for (i=n-1;i<n*2-1;i++) mx=max(mx,(ll)(a[i].x+0.5));
	ans-=2LL*mx;
	printf("%lld\n",ans); 
	return 0;
}