// 输入长度为 n 的模式串 a 以及长度为 m 的匹配串 b,下标从 0 开始,依次输出每个匹配成功的位置。
// nxt[i] 数组可以考虑成一个本来记录以这个位置为结尾能和前缀匹配的最大长度，然后这个数组集体往后移一格，第一位赋值为 -1，因为匹配的失败的时候肯定是要考虑前一位的能匹配的最大长度去最大化的利用已有的信息。
int nxt[N];
int kmp(int a[],int n,int b[],int m){
	int i,j,res=0;
	for (nxt[0]=j=-1,i=1;i<n;nxt[i++]=j){
		while (~j&&a[j+1]!=a[i]) j=nxt[j];
		j+=(a[j+1]==a[i]);
	}
	for (j=-1,i=0;i<m;i++){
		while (~j&&a[j+1]!=b[i]) j=nxt[j];//匹配不成功就往前回溯
		j+=(a[j+1]==b[i]);
		if (j==n−1) printf("%d ",i),j=nxt[j];
		//下面一个是找出所有不重叠的从前往后匹配到的子串
		if (j==n-1) res++,j=-1;
	}
	return res;
}
