#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LEN 10010
#define pb push_back
#define SET(mat, a) memset(mat, a, sizeof(mat))
using namespace std;
typedef long long int large;
typedef deque<int> di;

int x[LEN],y[LEN],N,dx[LEN];

large f(int i, int hi, int waslo){
  if(i==N) return 0;
  large ans;
  int lo = N-(hi-i);
  ans =         (x[i]-x[i+1])*(y[waslo?lo:hi-1]+y[hi])+f(i+1,hi-1,1);
  ans = max(ans,(x[i]-x[i+1])*(y[waslo?lo:hi-1]+y[hi])+f(i+1,hi,0));
  return ans;
}

int main(){
	large ans;
	int i;
	freopen("integral.txt","r",stdin);
	while (scanf("%d%", &N)==1 && N>0){
		loop(i,0,N) scanf("%d",&x[i]);
		loop(i,0,N) scanf("%d",&y[i]);
		sort(y,y+N);
		reverse(y,y+N);
    ans = f(0,N,0);
    ans = max(ans,f(0,N,1));
    printf("%.1lf\n",ans/2.0);
	}
  return 0;
}

