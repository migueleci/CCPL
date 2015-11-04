#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define SET(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM
#define INF
#define LEN 100005
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<int> di;

int R,C;
large a[LEN], h[LEN], f[LEN];

large ff(large* z, int len){
	int i;
	f[len]=f[len+1]=0;
	rev(i,len-1,0) f[i] = max(z[i]+f[i+2],f[i+1]);
	return f[0];
}

int main(){
	int r,c;
	//freopen("C.txt","r",stdin);
	while(scanf("%d %d",&R,&C)==2 && R+C){
		loop(r,0,R){
			loop(c,0,C) scanf("%lld",&a[c]);
			h[r] = ff(a,C);
		}
		printf("%lld\n",ff(h,R));
	}
	return 0;
}

