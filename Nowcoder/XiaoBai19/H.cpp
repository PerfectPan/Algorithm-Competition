#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
struct Node{
    int a,b,c;
}a[N];
int T,n,m,i,idx;
inline bool cmp1(const Node&A,const Node&B){return A.c>B.c;}
inline bool cmp2(const Node&A,const Node&B){return A.a<B.a;}
inline bool cmp3(const Node&A,const Node&B){return A.b>B.b;}
int main(){
    for (read(T);T--;){
        read(n),read(m);
        for (idx=0,i=1;i<=n;++i){
            read(a[i].a),read(a[i].b);
            a[i].c=a[i].b-a[i].a;
            idx+=a[i].c>0;
        }
        if (idx==n){
            puts("Yes");
            continue;
        }
        sort(a+1,a+1+n,cmp1);
        sort(a+1,a+1+idx,cmp2);
        sort(a+1+idx,a+1+n,cmp3);
        bool flag=0;
        for (i=1;i<=n;++i){
            if (m<a[i].a){
                flag=1;
                break;
            }
            m+=a[i].c;
        }
        puts(flag?"No":"Yes");
    }
    return 0;
}