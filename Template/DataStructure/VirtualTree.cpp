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