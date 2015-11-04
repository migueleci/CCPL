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

int len;
int a[LEN];
large s;

bool works(int m){
	if(s%m!=0) return 0;
	int i;
	large acum,n;
	i=0;
	n = s/m;
	printf("%lld %d %lld\n",s,m,n);
	while(i<len){
		acum=0;
		while(i<len && acum+a[i]<n) acum+=a[i], i++;
		if(acum!=n) return false;
	}
	return true;
}

int main(){
	int i,ans;
	freopen("baking.txt", "r", stdin);
	while(scanf("%d", &len)==1){
		s=0;
		loop(i,0,len) scanf("%d",&a[i]), s+=a[i];
		ans = 10001;
		while(ans>1 && !works(ans)) --ans;
		printf("%d\n",ans);
		if(ans<=1) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
