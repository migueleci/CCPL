#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LIM 100010
#define pb push_back
#define SET(mat, a) memset(mat, a, sizeof(mat))
using namespace std;
typedef long long int large;
typedef deque<int> di;

di AL[LIM];
int door[LIM], key[LIM];
bool isdoor[LIM], vis[LIM], iskey[LIM];
int n, m, k;
di d;
set<int> pending;

void dfs(int ori){
  int i, j;
  vis[ori]=true;
  loop(i, 0, int(AL[ori].size())){
    j=AL[ori][i];
    if (!vis[j]){
			if (isdoor[j]){
				if (vis[key[j]]) d.pb(j);
				else pending.insert(j);
			}else if(iskey[j]){
				if (pending.count(door[j])) d.pb(door[j]);
        dfs(j);
			}	else dfs(j);
    }
  }
}

int main(){
	int i, j, a, b;
	//freopen("escape.txt","r",stdin);
	while (scanf("%d%d%d", &n, &k, &m)==3 && n>0){
		SET(vis, 0); SET(isdoor, false);SET(iskey, false);
		loop(i, 0, k){
			scanf("%d%d", &a, &b);
			a--; b--;
			isdoor[b]=true; iskey[a]=true;
			door[a]=b; key[b]=a;
		}
		loop(i, 0, n) AL[i].clear();
		loop(i, 0, m){
      scanf("%d%d", &a, &b);
			a--; b--;
			AL[a].pb(b);
			AL[b].pb(a);
		}
		d.clear();
		pending.clear();
		dfs(0);
		int ori,  WTF=500000, wtf=0;
		while(d.size()>0 && !vis[n-1]){
			ori=d.front(); d.pop_front();
			if(pending.count(ori)) pending.erase(ori);
			dfs(ori);
		}
		puts((vis[n-1])?"Y":"N");
	}
  return 0;
}
