#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define rev(i, a, b) for(i=a; i>=b; i--)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
#define LIM 	20002
#define READ(file) freopen(file, "r", stdin)
using namespace std;
int n, m, p[105], f[105], tab[LIM];

int main(void){
	int i, j, der;
	//READ("d.txt");
	while (scanf("%d %d", &m, &n)==2){
		loop(i, 0, n){
      scanf("%d %d", &p[i], &f[i]);
		}
		SET(tab, -1);
		der=0;
		tab[0]=0;
		loop(i, 0, n){
      rev(j,LIM-1,0){
				if (tab[j]>=0 && j+p[i]<LIM){
					if(tab[j+p[i]]<tab[j]+f[i]) tab[j+p[i]]=tab[j]+f[i];
					//printf("-->i %d j%d tabj%d tabj+pi%d fi %d pi %d\n", i, j, tab[j],tab[j+p[i]], f[i], p[i]);
					//der=max(der, j+p[i]);
				}
      }
		}
		i=0, der=0;
		if(m>1800) m+=200;
		rev(j, m, 0) i=max(i,tab[j]);
		printf("%d\n", i);
	}
	return 0;
}
