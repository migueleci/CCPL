#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 -1
#define LIM                 100050
#define INF                 1e9
#define EPS                 1e-9
#define x                   first
#define y                   second
#define pb                  push_back
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef deque<int> di;
int n, m, p[LIM], lo[LIM], num[LIM], dfscount, SCC;
int indeg[LIM];
bool vis[LIM];
di s, AL[LIM], AL2[LIM];
set<int> tm1[LIM];

void tarjan(int u){
	int v, j;
	lo[u]=num[u]= dfscount++;
	s.pb(u);
	vis[u]=true;
	loop(j, 0, (int)AL[u].size()){
		v=AL[u][j];
		if (num[v]==0) tarjan(v);
		if (vis[v]) lo[u]=min(lo[u], lo[v]);
	}
	if (lo[u]==num[u]){
		//printf("SCC=%d\n", SCC);
		do{
			v=s.back(); s.pop_back();
			//printf("%d\n", v+1);
			vis[v]=0;
			p[v]=SCC;
		}while (u!=v);
		SCC++;
		//puts("");
	}
}

int main(){
	int nc, a, b, c, d, i, j, caso, v, ans;
	//freopen("all.txt", "r", stdin);
	scanf("%d", &nc);
	loop(caso, 0, nc){
		scanf("%d %d", &n, &m);
		loop(i, 0, n) AL[i].clear(), AL2[i].clear(), tm1[i].clear(), indeg[i]=0;
		s.clear();
		loop(i, 0, m){
			scanf("%d %d", &a, &b);
			a--; b--;
			indeg[b]+=1;
			AL[a].pb(b);
			//printf("%d -> %d\n", a+1, b+1);
		}
		loop(i, 0, n) num[i]=lo[i]=0, vis[i]=false;
		dfscount=1; SCC=0;
		loop(i, 0, n){
			if (num[i]==0) tarjan(i);//,printf("i %d\n",i);
		}
		//contraction
		//puts("P:");loop(i, 0, n) printf("%d ", p[i]); puts("");
		loop(i, 0, n){
			loop(j, 0, (int)AL[i].size()){
				v=AL[i][j];
				if (p[i]!=p[v]) tm1[p[i]].insert(p[v]);
			}
		}
		loop(i, 0, n) indeg[i]=0;
		loop(i, 0, SCC){
			for (set<int>::iterator it=tm1[i].begin(); it!=tm1[i].end(); it++){
				v=(*it);
				//printf("%d -> %d\n", i+1, v+1);
				AL2[i].pb(v); indeg[v]+=1;
			}
		}
		ans=0;
		loop(i, 0, SCC) if (indeg[i]==0) ans++;
		printf("Case %d: %d\n", caso+1, ans);
	}
	return 0;
}
