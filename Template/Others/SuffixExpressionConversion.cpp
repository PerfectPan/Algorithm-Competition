//中缀表达式转后缀表达式,同时求值,O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int>nums;
vector<char>ops;
int grade(char op){
	switch (op){
		case '(':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 3;
	}
	return 0;
}
void calc(char op){
	int y=*nums.rbegin();
	nums.pop_back();
	int x=*nums.rbegin();
	nums.pop_back();
	int z;
	switch (op){
		case '+':z=x+y;
				 break;
		case '-':z=x-y;
				 break;
		case '*':z=x*y;
				 break;
		case '/':z=x/y;
				 break;
	}
	nums.push_back(z);
}
int solve(string s){ 
	int top=0,val=0;
	for (int i=0;i<(int)s.length();i++){
		if (s[i]>='0'&&s[i]<='9'){
			val=val*10+s[i]-'0';
			if (s[i+1]>='0'&&s[i+1]<='9') continue;
			nums.push_back(val);
			printf("%d",val);
			val=0;
		}
		else if (s[i]=='(') ops.push_back(s[i]);
		else if (s[i]==')'){
			while (*ops.rbegin()!='('){
				calc(*ops.rbegin());
				printf("%c",*ops.rbegin());
				ops.pop_back();
			}
			ops.pop_back();
		}
		else{
			while (ops.size()&&grade(*ops.rbegin())>=grade(s[i])){
				calc(*ops.rbegin());
				printf("%c",*ops.rbegin());
				ops.pop_back();
			}
			ops.push_back(s[i]);
		}
	}
	while (ops.size()){
		calc(*ops.rbegin());
		printf("%c",*ops.rbegin());
		ops.pop_back();
	}
	puts("");
	return *nums.begin();
}
string s;
int main(){
	cin>>s;
	printf("%d\n",solve(s));
	return 0;
}