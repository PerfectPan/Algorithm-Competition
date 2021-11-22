// 处理一些树上大量询问关键点相关信息，但总的关键点数量又控制在与树大小同阶的问题，大致思想就是把关键点提出来建一棵树，但为了保证树的形态还要加入两两关键点之间的 LCA，假设关键点数量为 k，可以保证不同的 LCA 数量的上界是 k-1，建完树以后大致要跑个树形 DP 之类的
// 建树的过程大致是维护树上的一条链，具体去看 sengxian 的博客即可
// 可以观察到叶子节点一定是关键点
// 有时候可以不用显示的建出一棵树，因为建树的过程其实就是 dfs 的过程，可以隐式的进行信息更新等
void build(int points[],int k){
	static int stk[N];
	sort(points,points+k,cmp);

	cnt=k,sz=0,stk[sz++]=0;
	for (int i=0;i<k;i++){
		int u=points[i],f=lca(u,stk[sz-1]);
		if (f==stk[sz-1]) stk[sz++]=u;
		else{
			while (sz-2>=0 && dep[stk[sz-2]]>=dep[f]){
				addEdge(stk[sz-2],stk[sz-1]);
				sz--;
			}
			if (stk[sz-1]!=f){
				addEdge(f,stk[--sz]);
				stk[sz++]=f,points[cnt++]=f;
			}
			stk[sz++]=u;
		}
	}

	for (int i=0;i<sz-1;i++) addEdge(stk[i],stk[i+1]);
}
