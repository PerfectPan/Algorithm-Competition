// fail 指针指向当前节点所表示回文串的最长回文后缀
// cnt[x] 表示第 x 个节点所代表的回文串出现的次数（需建完树后 count 一遍才可以）
const int maxn=300000+5;
const int SIGMA_SIZE=26;
struct PalindromicTree{
    int ch[maxn][SIGMA_SIZE],fail[maxn],text[maxn],cnt[maxn],len[maxn],last,tot,all;
    int newnode(int l){
        for (int i=0;i<SIGMA_SIZE;i++) ch[tot][i]=0;
        cnt[tot]=0,len[tot]=l;
        return tot++;
    }
    void init(){
        last=tot=all=0;
        newnode(0),newnode(-1);
        text[0]=-1,fail[0]=1;
    }
    int getfail(int x){
        while (text[all-len[x]-1]!=text[all]) x=fail[x];
        return x;
    }
    void add(int w){
        text[++all]=w;
        int x=getfail(last);
        if (!ch[x][w]){
            int y=newnode(len[x]+2);
            fail[y]=ch[getfail(fail[x])][w];
            ch[x][w]=y;
        }
        cnt[last=ch[x][w]]++;
    }
    void count(){for (int i=tot-1;i>=2;i--)cnt[fail[i]]+=cnt[i];}//根节点cnt无意义，i>=2即可 
};

