#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define setmem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM
#define INF
#define LEN 105
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<int> di;

int a[LEN],n;
int memo[LEN][LEN][LEN];

int f(int lo, int hi, int k){
	if(memo[lo][hi][k]!=-1) return memo[lo][hi][k];
	int ans;
	if(lo==hi) ans=0;
	else if(lo==hi-1) ans=(k!=a[lo]);
	//else if(a[lo]==a[hi-1]) ans=f(lo+1,hi-1,a[lo])+(k!=a[lo]);
	else ans = min(f(lo+1,hi,a[lo])+(k!=a[lo]),f(lo,hi-1,a[hi-1])+(k!=a[hi-1]));
	return memo[lo][hi][k]=ans;
}

int main(){
	int tc, ntc,ans,i,n,len;
	//freopen("H.txt","r",stdin);
	scanf("%d",&ntc);
	loop(tc,1,ntc+1){
		scanf("%d %d",&len,&n);
		loop(i,0,len) scanf("%d",&a[i]);
		setmem(memo,-1);
		ans = f(0,len,n+1);
		printf("%d\n",ans);
	}
	return 0;
}
