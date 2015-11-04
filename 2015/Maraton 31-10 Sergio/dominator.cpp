#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define SET(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM 105
#define INF
#define LEN
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<int> di;

di AL[LIM];
int re, s, vis[LIM], dom[LIM][LIM], tr[LIM];

void dfs(int x){
	if (vis[x] || s==x) return;
	vis[x]=true;
	int i;
	loop(i, 0, (int)AL[x].size()) dfs(AL[x][i]);
}

int main(){
	int t, nt, a, b, c, n, m, i ,j;
	//freopen("dominator.txt","r",stdin);
	scanf("%d", &nt);
	loop(t, 0, nt){
    scanf("%d", &n);
    printf("Case %d:\n", t+1);
		loop(i, 0, n){
			AL[i].clear();
			loop(j, 0, n){
				scanf("%d", &a);
				if (a && j!=i) AL[i].pb(j);
			}
		}
		SET(dom, false);
		SET(vis, false);
		s=-1;
		dfs(0);
		loop(i, 0, n) tr[i]=vis[i];
		loop(s, 0, n){
			SET(vis, false);
			dfs(0);
			loop(i, 0, n) if (!vis[i] && tr[i]) dom[s][i]=1;
		}
		printf("+");
		loop(a, 0, 2*n-1) putchar('-');
		putchar('+');
		puts("");
		loop(i, 0, n){
			putchar('|');
			loop(j, 0, n) printf("%c|", (dom[i][j] )?'Y':'N');
			puts("");
			printf("+");
			loop(a, 0, 2*n-1) putchar('-');
			putchar('+');
			puts("");
		}
	}
	return 0;
}
