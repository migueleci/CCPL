#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define LEN 2015
#define setmem(m,v) memset(m,v,sizeof(m))
#define SET(m,v) memset(m,v,sizeof(m))
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<large,large> ii;
typedef deque<ii> dii;
typedef deque<int> di;
int n;

int ccw(ii a, ii b, ii c){
	int res=(c.x-b.x)*(a.y-b.y)-(c.y-b.y)*(a.x-b.x);
	if (res<0) return -1;
	if (res>0) return 1;
	return 0;
}

int main(){
	int ntc,tc,i, k, j;
	di ans, st;
	ii pt[100005];
	//freopen("mountain.txt","r",stdin);
	scanf("%d",&ntc);
	loop(tc,1,ntc+1){
		scanf("%d", &n);
		loop(i, 0, n) scanf("%lld%lld", &pt[i].x, &pt[i].y); 
		st.clear(), ans.clear();
		ans.pb(0);
		st.pb(n-1);
		st.pb(n-2);
		rev(i, n-3, 0){
			if (ccw(pt[i], pt[i+1], pt[i+2])>=0) st.pb(i+2);
			rev(k, st.size()-1, 0){
				if (ccw(pt[i], pt[i+1], pt[st[k]])>0){
				/*	printf("found %d %d,%d - %d,%d - %d,%d\n", i, pt[i].x, pt[i].y
																							, pt[i+1].x, pt[i+1].y
																							, pt[st[k]].x, pt[st[k]].y);
				*/
					ans.pb(st[k]); break;
				} 
			}
			if (k<0) ans.pb(0);
		}
		printf("%d", ans[n-2]);
		rev(i, n-3, 0){
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
