#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define rev(i, a, b) for(i=a; i>=b; i--)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
#define LIM 	101
#define READ(file) freopen(file, "r", stdin)
using namespace std;
int nt, mat[LIM][LIM], r, n, t, a, b, s, d;
int main(void){
	int i, j, k, m;
	//READ("c.txt");
	scanf("%d", &nt);
	loop(t, 0, nt){
		scanf("%d %d", &n, &r);
		loop(i, 0, n) loop(j, i, n) mat[i][j]=mat[j][i]=200000000;
		loop(i, 0, n) mat[i][i]=0;
		loop(i, 0, r){
			scanf("%d %d", &a, &b);
			mat[a][b]=mat[b][a]=1;
		}
		scanf("%d %d", &s, &d);
		loop(k, 0, n) loop(i, 0, n) loop(j, 0, n) mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		k=0;
		loop(i, 0, n) k=max(k, mat[s][i]+mat[i][d]);
		printf("Case %d: %d\n", t+1, k);
	}
	return 0;
}
