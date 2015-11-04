#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 2050
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

large ans[LEN][LEN];
large MOD = 9999959999LL;

large f(int l, int s){
	if(ans[l][s]>-1) return ans[l][s];
	large a=1;
	if(s>0) a = (a + f(l,s-1)   ) %MOD;
	if(l>0) a = (a + f(l-1,s+1) ) %MOD;
	return ans[l][s]=a;
}

int main(){
	int l,s;
	SET(ans,-1);
	//freopen("eloi.txt", "r", stdin);
	//printf("%lld\n", MOD);
	while(scanf("%d %d", &l,&s)==2 && l+s>0) printf("%lld\n",f(l,s));
	return 0;
}
