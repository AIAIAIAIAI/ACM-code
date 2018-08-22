#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
#define ms(a,x) memset(a,x,sizeof(a))
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int head[maxn];
struct Edge{
	int to,cap,next;
}edge[maxn<<3];
int k;
int level[maxn];//顶点到源点的距离标号
//int iter[maxn];//当前弧，在其之前的边没有用了
void add_edge(int from,int to,int cap){
	k++;
	edge[k].to=to;
	edge[k].cap=cap;
	edge[k].next=head[from];
	head[from]=k;
}
void bfs(int s){
	ms(level,-1);
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=head[v];i;i=edge[i].next){
			Edge &e=edge[i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}

}
int dfs(int v,int t,int f){
	if(v==t) return f;
	int used=0;
	for(int i=head[v];i&&f>used;i=edge[i].next){
		Edge &e=edge[i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f-used,e.cap));//多路增广
			if(d>0){
				e.cap-=d;
				//edge[i^1].cap+=d;
				used+=d;
			}
		}
	}
	if(!used) level[v]=-1;//炸点
	return used;
}
int max_flow(int s,int t){
	//dinic
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0) return flow;
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}
int main()
{
	int n,m;
	n=read(),m=read();
	int c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			c=read();
			add_edge(i*m+j,i*m+j+1,c);
			add_edge(i*m+j+1,i*m+j,c);
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			c=read();
			add_edge(i*m+j,(i+1)*m+j,c);
			add_edge((i+1)*m+j,i*m+j,c);
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			c=read();
			add_edge(i*m+j,(i+1)*m+j+1,c);
			add_edge((i+1)*m+j+1,i*m+j,c);
		}
	}
	printf("%d\n",max_flow(0,n*m-1));
	return 0;
}