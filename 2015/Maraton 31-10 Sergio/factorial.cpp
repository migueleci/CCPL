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

large mcm[7];
int len[7];

large fmcm(large a, large b){
	large m=__gcd(a,b);
	return (a/m)*b;
}

large f(large p){
	int i; large ans=0;
	if(p==0) return 1;
	loop(i,0,7) if(mcm[i]<=p) ans+=(p/mcm[i])*len[i]*f(p%mcm[i]);
	return ans;
}

int main(){
	int tc,ntc,i;
	large a,b,c,p;
	loop(i,0,3) len[i]=1;
	loop(i,3,6) len[i]=2;
	loop(i,6,7) len[i]=3;
	//freopen("G.txt","r",stdin);
	scanf("%d",&ntc);
	loop(tc,1,ntc+1){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&p);
		mcm[0] = a;
		mcm[1] = b;
		mcm[2] = c;
		mcm[3] = fmcm(a,b);
		mcm[4] = fmcm(a,c);
		mcm[5] = fmcm(b,c);
		mcm[6] = fmcm(a,mcm[5]);
		printf("Case %d: %lld",tc,f(p));
	}
	return 0;
}
