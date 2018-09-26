#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    int read(){
        return scanf("%d%d",&x,&y);
    }
};
typedef Point Vector;
Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator -(Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator *(Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator /(Vector A,double p){return Vector(A.x/p,A.y/p);}
bool operator<(const Point&a,const Point&b){
    return a.x-b.x<0||(a.x-b.x==0&&a.y-b.y<0);
}
bool operator==(const Point&a,const Point&b){
    return a.x-b.x==0&&a.y-b.y==0;
}
//点积
int Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
int Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
bool isPointOnSegment(Point P,Point A,Point B){//判断点是否在线段上
    return Cross(A-P,B-P)==0 && Dot(A-P,B-P)<=0;
}
bool isPointInPolygon(Point p,Vector poly[]){//点在多边形内判定射线法
    int wn=0,cnt=0;
    for (int i=0;i<4;i++){
        if (isPointOnSegment(p,poly[i],poly[(i+1)%4])) return true;
        int k=Cross(poly[(i+1)%4]-poly[i],p-poly[i]);
        int d1=poly[i].y-p.y;
        int d2=poly[(i+1)%4].y-p.y;
        if (k>0 && d1<=0 && d2>0) wn++;
        if (k<0 && d2<=0 && d1>0) wn--;
    }
    if (wn!=0) return true;
    return false;
}
Point p[4];
int n,d,x,y,m;
int main(){
	read(n),read(d);
	p[0].x=0,p[0].y=d;
	p[1].x=d,p[1].y=0;
	p[2].x=n,p[2].y=n-d;
	p[3].x=n-d,p[3].y=n;
	for (read(m);m--;){
		read(x),read(y);
		puts(isPointInPolygon(Point(x,y),p)?"YES":"NO");
	}
	return 0;
}