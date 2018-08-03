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
struct Point{
    ll x,y;
    Point(ll x=0,ll y=0):x(x),y(y){}
    int read(){
        return scanf("%lld%lld",&x,&y);
    }
};
typedef Point Vector;
Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator -(Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator *(Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator /(Vector A,double p){return Vector(A.x/p,A.y/p);}
bool operator<(const Point&a,const Point&b){
    return a.x<b.x||(a.x-b.x==0&&a.y-b.y<0);
}
bool operator==(const Point&a,const Point&b){
    return a.x-b.x==0&&a.y-b.y==0;
}
ll Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
int ConvexHull(Point* p,Point* ch,int n){
    sort(p,p+n);//先比较x坐标再比较y坐标
    n=unique(p,p+n)-p;
    int m=0;
     for (int i=0;i<n;i++){
        while (m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for (int i=n-2;i>=0;i--){
        while (m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if (n>1) m--;
    return m;
}
const int N=500000+10;
int n,m,i,j,cnt,sz1,sz2;
ll res=0;
Point A[N],B[N],ch1[N],ch2[N],t[N];
int main(){
	read(n),read(m);
	for (i=0;i<n;i++) A[i].read();
	for (i=0;i<m;i++) B[i].read();
	n=ConvexHull(A,ch1,n);
	m=ConvexHull(B,ch2,m);
	for (i=j=0,t[++cnt]=ch1[i]+ch2[j];i<n||j<m;){
		Point x=ch1[i%n]+ch2[(j+1)%m];
		Point y=ch1[(i+1)%n]+ch2[j%m];
		if (Cross(x-t[cnt],y-t[cnt])>=0) t[++cnt]=x,j++;
		else t[++cnt]=y,i++;
	}
	for (i=2;i<cnt;i++) res+=Cross(t[i]-t[1],t[i+1]-t[1]);
	printf("%lld\n",res);
	return 0;
}