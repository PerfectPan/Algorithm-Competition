const int G=10;
const int P=1000000007;
struct matrix{
    #define MS(x,y) memset(x,y,sizeof(x))
    #define MC(x,y) memcpy(x,y,sizeof(x))
    int v[G][G];
    void O(){MS(v,0);}
    void E(){MS(v,0);for(int i = 0; i < G; ++i)v[i][i] = 1; }
    void print(){
        for (int i=0;i<G;i++){
            for (int j=0;j<G;j++){
                printf("%d ",v[i][j]);
            }
            puts("");
        }
    }
    matrix operator*(const matrix &b)const{
        matrix c;c.O();
        for (int k=0;k<G;k++){
            for (int i=0;i<G;i++)if(v[i][k]){
                for (int j=0;j<G;j++){
                    c.v[i][j]=(c.v[i][j]+(ll)v[i][k]*b.v[k][j])%P;
                }
            }
        }
        return c;
    }
    matrix operator+(const matrix &b)const{
        matrix c;c.O();
        for (int i=0;i<G;i++){
            for (int j=0;j<G;j++){
                c.v[i][j]=(v[i][j]+b.v[i][j])%P;
            }
        }
        return c;
    }
    matrix operator^(ll p)const{
        matrix y; y.E();
        matrix x; memcpy(x.v,v,sizeof(v));
        while (p){
            if (p&1) y=y*x;
            x=x*x;
            p>>=1;
        }
        return y;
    }
};
