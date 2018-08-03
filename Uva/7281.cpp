#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const double eps=1e-10;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    int read(){
        return scanf("%lf%lf",&x,&y);
    }
};
typedef Point Vector;
Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator -(Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator *(Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator /(Vector A,double p){return Vector(A.x/p,A.y/p);}
int dcmp(double x){
    if (fabs(x)<eps) return 0;else return x<0?-1:1;
}
bool operator<(const Point&a,const Point&b){
    return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
bool operator==(const Point&a,const Point&b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
//点积
double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
//叉积
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}
//计算凸包，输入点数组p，函数返回输出点组数
//输入不能有重复点。函数执行完之后输入点的顺序被破坏
//如果不希望在凸包的边上有输入点即三点共线，把两个<改成<=
int ConvexHull(Point* p,Point* ch,int n){
    sort(p,p+n);//先比较x坐标再比较y坐标
    n=unique(p,p+n)-p;
    int m=0;
   	for (int i=0;i<n;i++){
        while (m>1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for (int i=n-2;i>=0;i--){
        while (m>k && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    if (n>1) m--;
    return m;
}
bool check(Point A,Point* p,int n){
	int l=1,r=n-2;
	while (l<=r){
		int mid=l+((r-l)>>1);
		double a1=Cross(p[mid]-p[0],A-p[0]);
		double a2=Cross(p[mid+1]-p[0],A-p[0]);
		if (a1>=0&&a2<=0){
			if (Cross(p[mid+1]-p[mid],A-p[mid])>=0) return 1;
			return 0;
		}
		else if (a1<0) r=mid-1;
		else l=mid+1;
	}
	return 0;
}
const int N=50000+10;
int n,m,i,res,sz;
Point p[N],ch[N];
int main(){
	while (~scanf("%d",&n)){
		for (res=0,i=0;i<n;i++){
			p[i].read();
		}
		sz=ConvexHull(p,ch,n);
		for (read(m);m--;){
			Point a;
			a.read();
			if (check(a,ch,sz)) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}