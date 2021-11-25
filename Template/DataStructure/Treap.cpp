const int N=100000+10;
struct Treap{
	int l,r,val,dat,cnt,size;
}a[N];
int n,op,x,tot,root,INF=0x7fffffff;
int New(int val){
	a[++tot].val=val;
	a[tot].dat=rand();
	a[tot].cnt=a[tot].size=1;
	return tot;
}
void update(int p){
	a[p].size=a[a[p].l].size+a[a[p].r].size+a[p].cnt;
}
void build(){
	New(-INF),New(INF);
	root=1,a[1].r=2;
	update(root);
}
void zig(int&p){
	int q=a[p].l;
	a[p].l=a[q].r,a[q].r=p,p=q;
	update(a[p].r),update(p);
}
void zag(int&p){
	int q=a[p].r;
	a[p].r=a[q].l,a[q].l=p,p=q;
	update(a[p].l),update(p);
}
void Insert(int&p,int val){
	if (p==0){
		p=New(val);
		return;
	}
	if (val==a[p].val){
		a[p].cnt++,update(p);
		return;
	}
	if (val<a[p].val){
		Insert(a[p].l,val);
		if (a[p].dat<a[a[p].l].dat) zig(p);
	}
	else{
		Insert(a[p].r,val);
		if (a[p].dat<a[a[p].r].dat) zag(p);
	}
	update(p);
}
void Remove(int&p,int val){
	if (p==0) return;
	if (val==a[p].val){
		if (a[p].cnt>1){
			a[p].cnt--,update(p);
			return;
		}
		if (a[p].l||a[p].r){
			if (a[p].r==0||a[a[p].l].dat>a[a[p].r].dat){
				zig(p),Remove(a[p].r,val);
			}
			else{
				zag(p),Remove(a[p].l,val);
			}
			update(p);
		}
		else p=0;
		return;
	}
	val<a[p].val?Remove(a[p].l,val):Remove(a[p].r,val);
	update(p);
}
int GetPre(int val){
	int ans=1;
	int p=root;
	while (p){
		if (val==a[p].val){
			if (a[p].l>0){
				p=a[p].l;
				while (a[p].r>0) p=a[p].r;
				ans=p;
			}
			break;
		}
		if (a[p].val<val&&a[p].val>a[ans].val) ans=p;
		p=val<a[p].val?a[p].l:a[p].r;
	}
	return a[ans].val;
}
int GetNext(int val){
	int ans=2;
	int p=root;
	while (p){
		if (val==a[p].val){
			if (a[p].r>0){
				p=a[p].r;
				while (a[p].l>0) p=a[p].l;
				ans=p;
			}
			break;
		}
		if (a[p].val>val&&a[p].val<a[ans].val) ans=p;
		p=val<a[p].val?a[p].l:a[p].r;
	}
	return a[ans].val;
}
int GetRankByVal(int p,int val){
	if (p==0) return 0;
	if (val==a[p].val) return a[a[p].l].size+1;
	if (val<a[p].val) return GetRankByVal(a[p].l,val);
	return GetRankByVal(a[p].r,val)+a[a[p].l].size+a[p].cnt;
}
int GetValByRank(int p,int Rank){
	if (p==0) return INF;
	if (a[a[p].l].size>=Rank) return GetValByRank(a[p].l,Rank);
	if (a[a[p].l].size+a[p].cnt>=Rank) return a[p].val;
	return GetValByRank(a[p].r,Rank-a[a[p].l].size-a[p].cnt);
}
int main(){
	build();
	for (read(n);n--;){
		read(op),read(x);
		switch(op){
			case 1:Insert(root,x);break;
			case 2:Remove(root,x);break;
			case 3:printf("%d\n",GetRankByVal(root,x)-1);break;
			case 4:printf("%d\n",GetValByRank(root,x+1));break;
			case 5:printf("%d\n",GetPre(x));break;
			case 6:printf("%d\n",GetNext(x));break;
		}
	}
	return 0;
}
