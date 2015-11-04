#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define SET(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM
#define INF
#define LEN
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<int> di;

large N,u,d;

large f(large n){ return n*(u+d)-N*d; }

int main(){
	large M,lo,hi,mid,k,ans;
	//freopen("B.txt","r",stdin);
	while(scanf("%lld %lld",&N,&M)==2){
		ans=INFINITY;
		while(M--){
			scanf("%lld %lld",&u,&d);
			lo=0, hi=N,k=100;
			while(k--){
				mid = (lo+hi)/2;
				if(f(mid)>0) hi=mid;
				else lo=mid;
			}
			ans = min(ans,f(hi));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
