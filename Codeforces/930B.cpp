#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define MP make_pair
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const int INF=0x3f3f3f3f;
const int P=1000000007;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
string s,t;
int cnt[26][5005][26],len,i,j,k;
int main(){
    cin>>s;
    t=s+s;
    len=s.length();
    for (i=0;i<len;i++){
        for (j=i+1;j<i+len;j++){
            cnt[t[i]-'a'][j-i][t[j]-'a']++;
        }
    }
    double ans=0;
    for (i=0;i<26;i++){
        int mx=0;
        for (j=1;j<len;j++){
            int c=0;
            for (k=0;k<26;k++) c+=(cnt[i][j][k]==1);
            mx=max(mx,c);
        }
        ans+=1.0*mx/len;
    }
    printf("%.7lf\n",ans);
    return 0;
}
