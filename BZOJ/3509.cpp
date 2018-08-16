#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const double PI=acos(-1.0);
struct cd{
    double x,y;
    cd(double a=0,double b=0):x(a),y(b){}
};
inline cd operator +(cd a,cd b){return cd(a.x+b.x,a.y+b.y);}
inline cd operator -(cd a,cd b){return cd(a.x-b.x,a.y-b.y);}
inline cd operator *(cd a,cd b){return cd(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
inline cd conj(cd a){return cd(a.x,-a.y);}
int n,i,mx,MAXLEN,len,blocksz,a[N];
ll L[N],R[N],ans=0;
cd w[2][N],A[N],B[N];
void init(){
    for (int k=0;k<MAXLEN;k++){
        w[0][k]=cd(cos(2*PI/MAXLEN*k),sin(2*PI/MAXLEN*k));
        w[1][k]=conj(w[0][k]);
    }
}
void fft(cd *a,int v,int n){
    for (int i=0,j=0;i<n;i++){
        if(i<j) swap(a[i],a[j]);
        for (int l=n>>1;(j^=l)<l;l>>=1);
    }
    for (int l=2;l<=n;l<<=1){
        int m=l>>1;
        for (int i=0;i<n;i+=l){ 
            for (int k=0;k<m;k++){
                cd t=w[v][MAXLEN/l*k]*a[i+k+m];
                a[i+k+m]=a[i+k]-t;
                a[i+k]=a[i+k]+t;
            }
        }
    }
    if (!v) return;
    for (int i=0;i<n;i++) a[i].x/=n;
}
ll bruteForce(){
    int i,j,k;
    ll res=0;
    for (i=1;i<=n;i+=blocksz){
        int r=min(i+blocksz-1,n);
        for (j=i;j<=r;++j) R[a[j]]--;
        for (j=i;j<=r;++j){
            for (k=j+1;k<=r;k++){
                int tar=2*a[j]-a[k];
                if (tar>=0) ans+=L[tar];
                tar=2*a[k]-a[j];
                if (tar>=0) ans+=R[tar];
            }
            L[a[j]]++;
        }
    }
    return res;
}
ll solve(){
    int i,j;
    ll res=0;
    for (i=1;i<=n;i+=blocksz){
        int r=min(i+blocksz-1,n),mx=0;
        for (j=1;j<i;++j) A[a[j]].x++,mx=max(mx,a[j]);
        for (j=r+1;j<=n;++j) B[a[j]].x++,mx=max(mx,a[j]);
        for (len=1;len<=mx;len<<=1);len<<=1;
        fft(A,0,len);fft(B,0,len);
        for (j=0;j<len;++j) A[j]=A[j]*B[j];
        fft(A,1,len);
        for(j=i;j<=r;++j) res+=(ll)(A[a[j]<<1].x+0.5);
        memset(A,0,sizeof(cd)*len);
        memset(B,0,sizeof(cd)*len);
    }
    return res;
}
int main(){
    scanf("%d",&n);
    blocksz=min(n,6*(int)sqrt(n));
    for (i=1;i<=n;++i) scanf("%d",&a[i]),mx=max(mx,a[i]),++R[a[i]];
    for (MAXLEN=1;MAXLEN<=mx;MAXLEN<<=1);MAXLEN<<=1;
    init();
    ans+=bruteForce();
    ans+=solve();
    printf("%lld\n",ans);
    return 0;
}