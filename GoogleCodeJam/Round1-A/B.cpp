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
int T,n,i,j,k,cas=1;
vector<int>vec;
void pr(int r,int c){printf("%d %d\n",r,c);}
int main(){
    for (read(T);T--;){
        read(n);
        printf("Case #%d:\n",cas++);
        int r=0,c=1;
        vec.clear();
        vec.PB(0);
        for (int i=0;i<31;++i)if(n&(1<<i)){
            vec.PB(i+1);
        }
        for (int i=1;i<(int)vec.size();++i){
            int delta=vec[i]-vec[i-1];
            if (delta==1){
                if (c==1){
                    r++;
                    pr(r,c);
                    for (int j=1;j<vec[i];++j){
                        c++;
                        pr(r,c);
                    }
                }
                else{
                    r++,c++;
                    pr(r,c);
                    for (int j=1;j<vec[i];++j){
                        c--;
                        pr(r,c);
                    }
                }
            }
            else{
                delta-=1;
                if (delta&1){
                    if (c==1){
                        r++;
                        pr(r,c);
                        for (int j=1;j<delta;++j){
                            if (j&1){
                                r++,c++;
                                pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c--;
                                    pr(r,c);
                                }
                            }
                            else{
                                r++;
                                pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c++;
                                    pr(r,c);
                                }
                            }
                        }
                        r++,c++;
                        pr(r,c);
                        for (int j=c+1;j<=vec[i];++j){
                            c++;
                            pr(r,c);
                        }
                    }
                    else{
                        r++,c++;
                        pr(r,c);
                        for (int j=1;j<delta;++j){
                            if (j&1){
                                r++;pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c++;
                                    pr(r,c);
                                }
                            }
                            else{
                                r++,c++;
                                pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c--;
                                    pr(r,c);
                                }
                            }
                        }
                        r++;
                        pr(r,c);
                        for (int j=c-1;j>=1;--j){
                            c--;
                            pr(r,c);
                        }
                    }
                }
                else{
                    if (c==1){
                        r++;
                        pr(r,c);
                        for (int j=1;j<delta;++j){
                            if (j%2==0){
                                r++,c++;
                                pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c--;
                                    pr(r,c);
                                }
                            }
                            else{
                                r++;
                                pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c++;
                                    pr(r,c);
                                }
                            }
                        }
                        r++,c++;
                        pr(r,c);
                        for (int j=c+1;j<=vec[i];++j){
                            c++;
                            pr(r,c);
                        }
                    }
                    else{
                        r++,c++;
                        pr(r,c);
                        for (int j=1;j<delta;++j){
                            if (j%2==0){
                                r++;pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c++;
                                    pr(r,c);
                                }
                            }
                            else{
                                r++,c++;
                                pr(r,c);
                                for (int k=1;k<=j;++k){
                                    c--;
                                    pr(r,c);
                                }
                            }
                        }
                        r++;
                        pr(r,c);
                        for (int j=c-1;j>=1;--j){
                            c--;
                            pr(r,c);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
