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
const int N=6e5+10;
const double PI=acos(-1.0);
struct cd{
    double x,y;
    cd(double a=0,double b=0):x(a),y(b){}
}A[N],B[N],C[N];
inline cd operator +(cd a,cd b){return cd(a.x+b.x,a.y+b.y);}
inline cd operator -(cd a,cd b){return cd(a.x-b.x,a.y-b.y);}
inline cd operator *(cd a,cd b){return cd(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
inline cd conj(cd a){return cd(a.x,-a.y);}
cd w[2][N];
void init(int n){
    for (int k=0;k<n;k++){
        w[0][k]=cd(cos(2*PI/n*k),sin(2*PI/n*k));
        w[1][k]=conj(w[0][k]);
    }
}
void fft(cd *a,int n,int v){
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
int n,m,i,j,len,cnt,res[N];
char a[N],b[N];
int main(){
	read(m),read(n);
	scanf("%s%s",a,b);
	for (i=0,j=m-1;i<j;i++,j--) swap(a[i],a[j]);
	for (len=1;len<n+m;len<<=1);
	init(len);
	//part1
	for (i=0;i<len;i++){
		A[i].x=i<m?(a[i]-'a'+1)*(a[i]-'a'+1)*(a[i]!='*'):0;
		A[i].y=0;
	}
	for (i=0;i<len;i++){
		B[i].x=i<n?(b[i]!='*'):0;
		B[i].y=0;
	}
	fft(A,len,0),fft(B,len,0);
	for (i=0;i<len;i++) C[i]=C[i]+A[i]*B[i];
	//part2
	for (i=0;i<len;i++){
		A[i].x=i<m?(a[i]-'a'+1)*(a[i]!='*'):0;
		A[i].y=0;
	}
	for (i=0;i<len;i++){
		B[i].x=i<n?(b[i]-'a'+1)*(b[i]!='*'):0;
		B[i].y=0;
	}
	fft(A,len,0),fft(B,len,0);
	for (i=0;i<len;i++) C[i]=C[i]-cd(2.0,0)*A[i]*B[i];
	//part3
	for (i=0;i<len;i++){
		A[i].x=i<m?(a[i]!='*'):0;
		A[i].y=0;
	}
	for (i=0;i<len;i++){
		B[i].x=i<n?(b[i]-'a'+1)*(b[i]-'a'+1)*(b[i]!='*'):0;
		B[i].y=0;
	}
	fft(A,len,0),fft(B,len,0);
	for (i=0;i<len;i++) C[i]=C[i]+A[i]*B[i];

	fft(C,len,1);
	
	for (i=m-1;i<n;i++) if(fabs(C[i].x)<0.5) res[++cnt]=i-m+1;
	printf("%d\n",cnt);
	for (i=1;i<=cnt;i++) printf("%d%c",res[i]+1,i==cnt?'\n':' ');
	return 0;
}