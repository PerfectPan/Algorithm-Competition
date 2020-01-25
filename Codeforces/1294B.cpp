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
const int N=1000+10;
int T,n,i,j;
pair<int,int>a[N];
char s[N*N];
int main(){
    for (read(T);T--;){
        read(n);
        for (i=1;i<=n;++i) read(a[i].first),read(a[i].second);
        sort(a+1,a+1+n);
        int len=0,sx=0,sy=0;
        for (i=1;i<=n;++i){
            if (sy>a[i].second){
                len=-1;
                break;
            }
            for (j=sx+1;j<=a[i].first;++j) s[len++]='R';
            for (j=sy+1;j<=a[i].second;++j) s[len++]='U';
            sx=a[i].first,sy=a[i].second;
        }
        if (~len){
            s[len]='\0';
            puts("YES");
            puts(s);
        }
        else puts("NO");
    }   
    return 0;
}