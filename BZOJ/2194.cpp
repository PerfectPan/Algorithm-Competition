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
const int N=3e5+10,INF=1e9;
const double PI=acos(-1);
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
int n,m,i,c[N];
cd a[N],b[N];
int main() {
    read(n);
    for (i=0;i<n;i++) scanf("%lf%lf",&a[n-i-1].x,&b[i].x);
    m=n+n;
    f.mul(a,b,m);
    for(int i=n-1;i>=0;i--) printf("%d\n",(int)(a[i].x+0.5));
    return 0;
}
