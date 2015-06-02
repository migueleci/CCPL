#include <bits/stdc++.h>
#define LIM	1100
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;

int main(){
	int n, i, j, k, l, m, a[100], b[100], p;
	bool t=false;
	while(scanf("%d", &n)==1 && n>0){
		if (t) puts("");
		t=true;
		SET(a, 0);
		loop(i, 0, n) scanf("%d", &b[i]);
		k=1;
		a[0]=b[0];
		loop(i, 1, n) if (b[i]!=b[i-1]) a[k++]=b[i];
		n=k;
		loop(i, 0, n-5)
			loop(j, i+1, n-4)
				loop(k, j+1, n-3)
					loop(l, k+1, n-2)
						loop(m, l+1, n-1)
							loop(p, m+1, n)
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k], a[l], a[m], a[p]);
	}
	return 0;
}

