#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 -1
#define LIM                 50005
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

large p;

int main(){
	large n,ans;
	//freopen("champion.txt", "r", stdin);
	while(scanf("%lld", &n)==1){
		ans=0;
		while(n>1){
			ans+=n/2;
			n = (n/2)+n%2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
