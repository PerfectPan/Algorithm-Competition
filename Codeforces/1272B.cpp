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
int T,i,len;
char s[N];
int main(){
    for (read(T);T--;){
        scanf("%s",s+1);len=strlen(s+1);
        int a=0,b=0,c=0,d=0;
        for (i=1;i<=len;++i){
            if (s[i]=='L') a++;
            if (s[i]=='R') b++;
            if (s[i]=='U') c++;
            if (s[i]=='D') d++;
        }
        int x=min(a,b),y=min(c,d);
        if (x>0 && y>0){
            a=b=x,c=d=y;
            int ans=a+b+c+d;
            printf("%d\n",ans);
            for (i=1;i<=a;++i) putchar('L');
            for (i=1;i<=c;++i) putchar('U');
            for (i=1;i<=b;++i) putchar('R');
            for (i=1;i<=d;++i) putchar('D');
            puts("");
        }
        else if (x==0 && y==0) puts("0\n");
        else if (x==0 && y>0) printf("2\nUD\n");
        else printf("2\nLR\n");
    }
    return 0;
}