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
typedef vector<int> vi;
typedef deque<int> di;

int indeg[LIM], outdeg[LIM], n, m;
vi AL[LIM], AL2[LIM];
bool vis[LIM];

void spread(int x){
	int i;
	if (vis[x]) return;
	vis[x]=true;
	loop(i, 0, (int)AL[x].size()) spread(AL[x][i]);
}
void spread2(int x){
	int i;
	if (vis[x]) return;
	vis[x]=true;
	loop(i, 0, (int)AL2[x].size()) spread2(AL2[x][i]);
}

int main(){
	int nc, i, a, b, c, ans,caso;
	freopen("all.txt", "r", stdin);
	scanf("%d", &nc);
	loop(caso, 0, nc){
		ans=0;
		scanf("%d %d", &n, &m);
		loop(i, 0, n) AL[i].clear(), AL2[i].clear(), indeg[i]=0, vis[i]=false;
		loop(i, 0, m){
			scanf("%d %d", &a, &b);
			a--; b--;
			indeg[b]+=1;
			outdeg[a]+=1;
			AL[a].pb(b);
			AL2[a].pb(b);
			AL2[b].pb(a);
		}
		loop(i, 0, n){
			if (indeg[i]==0) spread(i), ans++;
		}
		//printf("%d\n",ans);
		loop(i, 0, n){
			if (!vis[i]) spread2(i), ans++;
		}
		printf("%d\n",ans);
		printf("Case %d: %d\n", caso+1, ans);
	}
	return 0;
}
