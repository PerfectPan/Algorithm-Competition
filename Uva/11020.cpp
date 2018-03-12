#include <cstdio>
#include <set>
using namespace std;
struct Point{
	int a,b;
	bool operator<(const Point&rhs)const{
		return a<rhs.a || (a==rhs.a && b<rhs.b);
	}
};
multiset<Point>S;
multiset<Point>::iterator it;
int T,n,a,b,cas=1;
int main(){
	for (scanf("%d",&T);T--;){
		if (cas>1) puts("");
		printf("Case #%d:\n",cas++);
		S.clear();
		for (scanf("%d",&n);n--;){
			scanf("%d%d",&a,&b);
			Point P=(Point){a,b};
			it=S.lower_bound(P);
			if (it==S.begin() || (--it)->b>b){
				S.insert(P);
				it=S.upper_bound(P);
				while (it!=S.end() && it->b>=b) S.erase(it++);
			}
			printf("%d\n",S.size());
		}
	}
	return 0;
}