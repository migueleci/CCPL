#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define setmem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM
#define INF
#define LEN 200005
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<ii> dii;

int vlen,elen;
int vis[LEN];
int dis[LEN];
int ans[LEN],anslen;
dii al[LEN];
map<int,int> aal[LEN];

int main(){
	int i,u,v,c,z,w,j;
	//freopen("I.txt","r",stdin);
	while(scanf("%d %d",&vlen,&elen)==2){
		loop(u,0,vlen) al[u].clear(), aal[u].clear();
		loop(i,0,elen){
			scanf("%d %d %d",&u,&v,&c);
			--u,--v;
			if(u==v) continue;
			if(aal[u].count(v)==0)aal[u][v]=c;
			else aal[u][v]=min(aal[u][v],c);
			swap(u,v);
			if(aal[u].count(v)==0)aal[u][v]=c;
			else aal[u][v]=min(aal[u][v],c);
		}
		map<int,int> :: iterator it;
		loop(u,0,vlen) if(aal[u].size()){
			for(it=aal[u].begin(); it!=aal[u].end(); ++it)
				al[u].push_back(*it);
		}
		deque<int> d;
		setmem(vis,0);
		d.push_back(vlen-1);
		vis[vlen-1]=1;
		dis[vlen-1]=0;
		while(d.size()){
			u = d[0], d.pop_front();
			if(u==0) break;
			loop(i,0,(int)al[u].size()) if(!vis[v=al[u][i].x]){
				vis[v]=1;
				dis[v]=dis[u]+1;
				d.push_back(v);
			}
		}
		//printf("dis:%d\n",dis[0]);
		deque<int> q[2];
		setmem(vis,0);
		w=0;
		q[0].push_back(0);
		vis[0]=1;
		anslen=0;
		while(!vis[vlen-1]){
			// nuevo nivel (todos mismo color)
			q[1-w].clear();
			z = 1000420000;
			loop(j,0,(int)q[w].size()){
				u = q[w][j];
				loop(i,0,(int)al[u].size()) if(dis[v=al[u][i].x]==dis[u]-1)
					z=min(z,al[u][i].y);
			}
			ans[anslen++] = z;
			loop(j,0,(int)q[w].size()){
				u = q[w][j];
				loop(i,0,(int)al[u].size()) if(dis[v=al[u][i].x]==dis[u]-1 && !vis[v=al[u][i].x] && z==al[u][i].y){
					vis[v]=1;
					q[1-w].push_back(v);
				}
			}
			w=1-w;
		}
		printf("%d\n%d",anslen,ans[0]);
		loop(i,1,anslen) printf(" %d",ans[i]); puts("");
	}
	return 0;
}
