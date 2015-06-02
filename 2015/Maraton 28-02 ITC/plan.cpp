#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
#define LIM 2005
using namespace std;

int main(void){
	int t, nt, n, a[LIM],i,c1,c2;
	scanf("%d", &nt);
	loop(t, 0, nt){
		scanf("%d", &n);
		SET(a,0);
		loop(i, 0, n) scanf("%d", &a[i]);
		c1=c2=0;
    loop(i, 0, n){
    	c1+=(a[i]/30+1)*10;
    	c2+=(a[i]/60+1)*15;
    }
    if(c1<c2) printf("Case %d: Mile %d\n",t+1,c1);
    else if(c1>c2) printf("Case %d: Juice %d\n",t+1,c2);
    else printf("Case %d: Mile Juice %d\n",t+1,c1);
	}

	return 0;
}
