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
const int N=200+10;
int T,len,i;
char a[N],b[N],c[N];
int main(){
    for (read(T);T--;){
        scanf("%s%s%s",a,b,c);
        len=strlen(a);
        bool flag=1;
        for (i=0;i<len;++i){
            if (a[i]==c[i] || b[i]==c[i]) continue;
            flag=0;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}