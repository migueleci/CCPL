#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define LEN 2015
#define setmem(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll;

char line[LEN];
int len,p[LEN];
ll memo[LEN][LEN];

ll f(int i, int av){
	if(av<0) return 10000000000LL;
	if(memo[i][av]!=-1) return memo[i][av];
	ll best=10000000000LL;
	if(i==len) best = 0;
	else{
		int j;
		ll sum=0,off;
		loop(j,i,len+1){
			sum += p[j];
			off = 10*(sum/10) + 10*((sum%10)>=5);
			best = min(best,off+f(j+1,av-1));
		}
	}
	return memo[i][av]=best;
}

int main(){
	int i,d;
	ll ans;
	//freopen("cent.txt","r",stdin);
	while(scanf("%d %d",&len,&d)==2){
		loop(i,0,len) scanf("%d",&p[i]);
		setmem(memo,-1);
		ans = f(0,d+1);
		printf("%lld\n",ans);
	}
	return 0;
}
