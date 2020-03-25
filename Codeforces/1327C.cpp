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
int n,m,k,i,j,len,sx[N],sy[N],fx[N],fy[N];
char s[N*N*4];
int main(){
    read(n),read(m),read(k);
    int a=0,b=0;
    for (i=1;i<=k;++i){
        read(sx[i]),read(sy[i]);
        a=max(a,sx[i]),b=max(b,sy[i]);
    }
    for (i=1;i<=k;++i){
        read(fx[i]),read(fy[i]);
    }
    len=0;
    for (i=1;i<a;++i) s[++len]='U';
    for (i=1;i<b;++i) s[++len]='L';
    int x=1,y=1;
    for (i=1;i<=n;++i){
        if (i&1){
            while (y<m){
                y++;
                s[++len]='R';
            }
            s[++len]='D';
            y=m;
        }
        else{
            while (y>1){
                y--;
                s[++len]='L';
            }
            s[++len]='D';
            y=1;
        }
    }
    s[len+1]='\0';
    printf("%d\n",len);
    puts(s+1);
    return 0;
}