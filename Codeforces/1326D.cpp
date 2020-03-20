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
int T,n,i,j,Mp[N*2];
char s[N],t[N],Ma[N*2];
int main(){
    for (read(T);T--;){
        scanf("%s",s+1);
        n=strlen(s+1);
        for (i=1,j=n;i<j;++i,--j){
            if (s[i]!=s[j]) break; 
        }
        int len=0;
        for (int k=i;k<=j;++k) t[k-i]=s[k],len++;
        // cout<<len<<endl;
        // for (int k=0;k<len;++k) putchar(t[k]);
        // puts("");
        if (!len){
            for (int k=1;k<i;++k) putchar(s[k]);
            for (int k=j+1;k<=n;++k) putchar(s[k]);
            puts("");
        }
        else{
            int l=0;
            Ma[l++]='$';
            Ma[l++]='#';
            for (int k=0;k<len;k++){
                Ma[l++]=t[k];
                Ma[l++]='#';
            }
            Ma[l]=0;
            int mx=0,id=0;
            int L=1,R=1,ans=-1;
            for (int k=0;k<l;k++){
                Mp[k]=mx>k?min(Mp[2*id-k],mx-k):1;
                while (Ma[k+Mp[k]]==Ma[k-Mp[k]]) Mp[k]++;
                if (k+Mp[k]>mx){
                    mx=k+Mp[k];
                    id=k;
                }
                if (k>1){
                    if (!(k&1)){
                        int ll=(Mp[k]-1)/2;
                        int rpos=k/2;
                        if (rpos-ll<=1 || rpos+ll>=len){
                            int LLL=max(rpos-ll,1);
                            int RRR=min(rpos+ll,len);
                            int lenn=RRR-LLL+1;
                            if (ans==-1 || ans<lenn){
                                ans=lenn;
                                L=LLL;
                                R=RRR;
                            }
                        }
                    }
                    else{
                        int ll=(Mp[k]-1)/2;
                        int rpos=k/2;
                        if (rpos-ll<=0 || rpos+ll>=len){
                            int LLL=max(rpos-ll+1,1);
                            int RRR=min(rpos+ll,len);
                            int lenn=RRR-LLL+1;
                            if (ans==-1 || ans<lenn){
                                ans=lenn;
                                L=LLL;
                                R=RRR;
                            }
                        }
                    }
                }
            }
            if (L!=0) L--,R--;
            for (int k=1;k<i;++k) putchar(s[k]);
            for (int k=L;k<=R;++k) putchar(t[k]);
            for (int k=j+1;k<=n;++k) putchar(s[k]);
            puts("");
        }
    }
    return 0;
}