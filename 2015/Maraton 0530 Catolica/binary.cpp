#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define LEN 105
#define setmem(m,v) memset(m,v,sizeof(m))
#define SET(m,v) memset(m,v,sizeof(m))
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

double memo[LEN][LEN][LEN];
double p[LEN];

double f(int lo, int hi, int k){
	double ans = INFINITY;
	int i;
	if(memo[lo][hi][k]>-0.5) ans=memo[lo][hi][k];
	else if(lo==hi) ans=0.0;
	else{ loop(i,lo,hi) ans = min(ans,f(lo,i,k+1)+f(i+1,hi,k+1)+k*p[i]); }
	return memo[lo][hi][k]=ans;
}

int main(){
	int i,j,k,len;
	double ans;
	//freopen("binary.txt","r",stdin);
	while(scanf("%d",&len)==1){
		loop(i,0,len) scanf("%lf", &p[i]);
		loop(i,0,len+2) loop(j,0,len+2) loop(k,0,len+2) memo[i][j][k]=-1.0;
		ans = f(0,len,1);
		printf("%.5lf\n",ans);
	}
	return 0;
}
