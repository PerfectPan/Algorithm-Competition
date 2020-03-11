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
const int N=1e6+10;
int T,len,i;
char s[N];
int main(){
    for (read(T);T--;){
        scanf("%s",s+1);len=strlen(s+1);
        if (len>=2){
            if (s[len-1]=='p' && s[len]=='o') puts("FILIPINO");
        }
        if (len>=4){
            if ((s[len-3]=='d' && s[len-2]=='e' && s[len-1]=='s' && s[len]=='u')
                ||  (s[len-3]=='m' && s[len-2]=='a' && s[len-1]=='s' && s[len]=='u'))
            puts("JAPANESE");
        }
        if (len>=4){
            if (s[len-4]=='m' && s[len-3]=='n' && s[len-2]=='i' && s[len-1]=='d' && s[len]=='a')
            puts("KOREAN");
        }
    }
    return 0;
}