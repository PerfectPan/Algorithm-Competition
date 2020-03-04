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
const int N=2000+10;
int i,j,k,len;
char s[N];
int col[N],num[N];
int main(){
    scanf("%s",s+1);len=strlen(s+1);
    for (i=1;;++i){
        bool flag=0;
        int cnt=0;
        for (j=1,k=len;j<k;j++,k--){
            while ((col[j]||s[j]==')') && j<=len) j++;
            while ((col[k]||s[k]=='(') && k>=1) k--;
            if (j>=k) break;
            col[j]=col[k]=i;
            cnt+=2;
            flag=1;
        }
        if (!flag){
            i--;
            break;
        }
        num[i]=cnt;
    }
    printf("%d\n",i);
    for (j=1;j<=i;++j){
        printf("%d\n",num[j]);
        for (k=1;k<=len;++k)if(col[k]==j) printf("%d ",k);
        puts("");
    }
    return 0;
}