#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define LEN 1000000000LL
using namespace std;
typedef long long ll;

ll d;

ll f(int a){ return ((2*a+d)*(d+1))/2 ;}

int bs(ll n){
	ll lo=1, hi=LEN,mid;
	while(lo+1<hi){ // inv: f(lo)<=n<f(hi)
		mid = (lo+hi)/2;
		if(n<f(mid)) hi=mid;
		else lo=mid;
	}
	return lo;
}

int solve(ll n){
	int i;
	loop(d,1,LEN){
		 i=bs(n);
		 if(f(i)==n) return i;
		 if(i<=1) return -1;
	}
}

int main(){
	int i,ans;
	//freopen("sums.txt","r",stdin);
	//printf("%lld = %d",n,ans);
	int ntc;
	ll n;
	scanf("%d",&ntc);
	while(ntc--){
		scanf("%lld",&n);
		ans = solve(n);
		if(ans>0){
			printf("%lld = %d",n,ans);
			loop(i,0,d) printf(" + %d",ans+1+i);
			printf("\n");
		}	else puts("IMPOSSIBLE");
	}
	return 0;
}
