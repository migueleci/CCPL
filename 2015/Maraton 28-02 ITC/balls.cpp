#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
using namespace std;
typedef long long int large;

int main(void){
	int casos,d,i;
	int ans[1000];
	large a,b;
	//freopen("b.txt","r",stdin);
	while(scanf("%d",&casos)==1 && casos>=0){
		while(casos--){
			scanf("%d %lld", &d, &a); a--; d--;
			loop(i,0,d) ans[i]=(a>>i)&1;
			//loop(i,0,d) printf("%d",ans[i]); puts("");
			b=0;
			loop(i,0,d) b=2*b+ans[i];
			b+=((1LL)<<(d));
			printf("%lld\n",b);
		}
	}
	return 0;
}
