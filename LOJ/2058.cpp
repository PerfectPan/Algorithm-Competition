#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int P=998244353;
const int N=800000+10;
int fexp(int a,int n){
    int res=1;
    for (;n;n>>=1,a=(ll)a*a%P) if(n&1)res=(ll)res*a%P;
    return res;
}
struct NumberTheoreticTransform{
    int n,w[2][N];
    void init(int lim){
        for (n=1;n<lim;n<<=1);
        w[0][0]=w[0][n]=1;
        int g=fexp(3,(P-1)/n);
        for (int i=1;i<n;i++) w[0][i]=(ll)w[0][i-1]*g%P;
        for (int i=0;i<=n;i++) w[1][i]=w[0][n-i];
    }
    void ntt(int* a,int v){
        for (int i=0,j=0;i<n;i++){
            if(i>j) swap(a[i],a[j]);
            for (int l=n>>1;(j^=l)<l;l>>=1);
        }
        for (int l=2;l<=n;l<<=1){
            int m=l>>1;
            for (int i=0;i<n;i+=l){
                for (int k=0;k<m;k++){
                    int t=(ll)w[v][n/l*k]*a[i+k+m]%P;
                    a[i+k+m]=(a[i+k]-t>=0)?(a[i+k]-t):(a[i+k]-t+P);
                    a[i+k]=(a[i+k]+t<P)?(a[i+k]+t):(a[i+k]+t-P);
                }
            }
        }
        if (!v) return;
        int rv=fexp(n,P-2);
        for (int i=0;i<n;i++) a[i]=(ll)a[i]*rv%P;
    }
    void work(int* a,int* b,int m){
        init(m);
        ntt(a,0),ntt(b,0);
        for (int i=0;i<n;i++) a[i]=(ll)a[i]*b[i]%P;
        ntt(a,1);
    }
}NTT;
void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int n,k,i,res,f[N],inv[N],a[N],b[N];
int main(){
	read(n);
	for (f[0]=i=1;i<=n;i++) f[i]=(ll)f[i-1]*i%P;
	for (inv[i=n]=fexp(f[n],P-2);i;i--) inv[i-1]=(ll)inv[i]*i%P;
	for (i=0;i<=n;i++) a[i]=(i&1?P-inv[i]:inv[i]);
    b[0]=1,b[1]=n+1;
	for (i=2;i<=n;i++) b[i]=(ll)((fexp(i,n+1)-1)%P+P)%P*fexp(i-1,P-2)%P*inv[i]%P;
    k=1;
    NTT.work(a,b,(n<<1)+1);
	for (res=i=k++;i<=n;i++,up(k,k)) up(res,(ll)a[i]*k%P*f[i]%P);
	printf("%d\n",res);
    return 0;
} 