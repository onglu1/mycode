#include <bits/stdc++.h>
using namespace std;
const int N=4e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return num*f;
}
int n,m,fa[N],dep[N],siz[N],top[N],son[N];
set<int>S[N];
set<int>::iterator it;
void Add_Son(int u,int v){S[u].insert(u);fa[v]=u;}
void Delete_Son(int u,int v){
	set<int>::iterator itt;
	itt=S[u].find(v);
	if(itt!=S[u].end())S[u].erase(itt);
	fa[v]=0;
}
void dfs1(int x,int deep){
	dep[x]=deep;siz[x]=1;
	for(it=S[x].begin();it!=S[x].end();it++){
		int y=*it;
		dfs1(y,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>=siz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int ltp){
	top[x]=ltp;
	if(son[x])dfs2(son[x],ltp);
	for(it=S[x].begin();it!=S[x].end();it++){
		int y=*it;
		if(y==son[x])continue;
		dfs2(y,y);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		Add_Son((i+x>n)?(n+1):(i+x),i);
	}
	
	//dfs1(n+1,0);dfs2(n+1,n+1);
	//m=read();
	return 0;
}
/*
很容易想到可以理解成一棵多叉树
然后问题就变成了给定一棵树，每次指定一个节点
询问它到根节点的距离。
同时这棵树带修。
静态的树很好实现（直接dp都可以）
带修怎么搞。。
如果我们把一棵子树换了父亲，那么我们要修改整棵树的距离
好麻烦啊。。
树剖维护吗？
有点麻烦，因为一旦修改了树的结构，树剖的结构就要打破了
一次修改可能是O(n)的。
Splay？
换爹还是难啊。。。
一个不错的思路是可以把要修改的节点旋转到根节点
标记节点编号之后删除父亲关系
然后再连接到新的父亲上
不过是多叉树啊
左兄弟右儿子转二叉树还是不现实
发现很多的平衡树都是二叉结构的。。
或许不能用平衡树写。。

继续用树剖想想看。。
静态的话直接找重链跳根然后深度求和就可以了
动态的话。。
换爹会带来什么影响呢。。
首先一条重链可能被拆开
重链前半段的top不变，后半段要变成修改的节点了。
发现其实好像可以搞
修改一条链的父亲的操作是O(logn)的，但是频繁修改父亲可能导致树剖退化
这个我们先不提
具体搞法呢？
开n+1个点，最后一个点是弹飞的点
然后每个节点指向的节点向这个节点连边，跑一遍树剖。
每次询问输出深度
修改的话，在每个点开一个set存它的儿子集合
修改就挺简单了。
 
*/ 





