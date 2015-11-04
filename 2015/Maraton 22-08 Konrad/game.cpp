#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 105
#define INF                 1e9
#define EPS                 1e-9
#define x                   first
#define y                   second
#define pb                  pushback
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;

double memo[LEN][LEN][LEN];

double f(int n, int m, int k){
	printf("f(%d,%d,%d) = ?\n",n,m,k);
	/* 0<=n*/
	/* 0<=k*/
	/* 0<=m*/
	if(memo[n][m][k]>-.5) printf("f(%d,%d,%d) = %.9lf\n",n,m,k,memo[n][m][k]);
	if(memo[n][m][k]>-.5) return memo[n][m][k];
	double ans;
	if(m==0 || k==0) ans = (m==0 && k==0);
	else if(k>m || k>n) ans = 0;
	else if(n==1 && m==1) ans = (k==1);
	else ans = f(n,m-1,k)/n + (f(n-1,m-1,k-1)*pow(n-1,m-1))/pow(n,m-1);
	printf("f(%d,%d,%d) = %.9lf\n",n,m,k,ans);
	return memo[n][m][k]=ans;
}

int main(){
	int n,m,k;
	loop(n,0,LEN) loop(m,0,LEN) loop(k,0,LEN) memo[n][m][k]=-1;
	freopen("game.txt", "r", stdin);
	while(scanf("%d %d %d", &n,&m,&k)==3 && n+m+k>0){
		printf("%lf\n",f(n,m,k));
	}
	return 0;
}
