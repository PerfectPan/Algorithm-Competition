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
int n,i;
char s[N],t[N];
int main(){
    read(n);
    scanf("%s",s+1);
    int a=0,b=0;
    for (i=1;i<=n;++i){
        if (s[i]=='B') a++;
        else b++;
        t[i]=s[i];
    }
    if ((a&1)&&(b&1)) puts("-1");
    else if ((a&1)&&(!(b&1))){
        vector<int>vec;vec.clear();
        for (i=1;i<n;++i){
            if (s[i]=='W'){
                s[i]='B';
                if (s[i+1]=='W') s[i+1]='B';
                else s[i+1]='W';
                vec.push_back(i);
            }
        }
        if (s[n]=='W') puts("-1");
        else{
            printf("%d\n",(int)vec.size());
            for (i=0;i<(int)vec.size();++i){
                printf("%d%c",vec[i],i==(int)vec.size()-1?'\n':' ');
            }
        }
    }
    else if ((!(a&1))&&(b&1)){
        vector<int>vec;vec.clear();
        for (i=1;i<n;++i){
            if (s[i]=='B'){
                s[i]='W';
                if (s[i+1]=='W') s[i+1]='B';
                else s[i+1]='W';
                vec.push_back(i);
            }
        }
        if (s[n]=='B') puts("-1");
        else{
            printf("%d\n",(int)vec.size());
            for (i=0;i<(int)vec.size();++i){
                printf("%d%c",vec[i],i==(int)vec.size()-1?'\n':' ');
            }
        }
    }
    else{
        vector<int>vec;vec.clear();
        for (i=1;i<n;++i){
            if (s[i]=='B'){
                s[i]='W';
                if (s[i+1]=='W') s[i+1]='B';
                else s[i+1]='W';
                vec.push_back(i);
            }
        }
        if (s[n]=='B'){
            vec.clear();
            for (i=1;i<n;++i){
                if (t[i]=='W'){
                    t[i]='B';
                    if (t[i+1]=='W') t[i+1]='B';
                    else t[i+1]='W';
                    vec.push_back(i);
                }
            }
            if (t[n]=='W') puts("-1");
            else{
                printf("%d\n",(int)vec.size());
                for (i=0;i<(int)vec.size();++i){
                    printf("%d%c",vec[i],i==(int)vec.size()-1?'\n':' ');
                }
            }
        }
        else{
            printf("%d\n",(int)vec.size());
            for (i=0;i<(int)vec.size();++i){
                printf("%d%c",vec[i],i==(int)vec.size()-1?'\n':' ');
            }
        }
    }
    return 0;
}