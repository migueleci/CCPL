#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 -1
#define LIM                 1010
#define INF                 1e9
#define EPS                 1e-9
#define x                   first
#define y                   second
#define pb                  push_back
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;
typedef map<int,int> mii;

int L,s,f,m,v;
char road[LIM][LIM];
mii val[2];
mii::iterator it;

int main(){
	int n, i, curr, prev, j, a;
	freopen("incredibus.txt", "r", stdin);
	while(scanf("%d", &L)==1 && L>0){
		scanf("%d %d %d %d",&s,&f,&m,&v);
		loop(i,0,m) scanf("%s",road[i]);
		val[0].clear(); val[1].clear();
		val[0][s]=0; 
		curr = 0; prev = 1;
		loop(i,0,m){
			//printf("i=%d\n",i);
			for(it = val[curr].begin();it!=val[curr].end();it++) {
				a=(*it).x;
				//printf(" %d",a);
				loop(j,0,v+1){
					if(a+j<=L && road[i][a+j]!='X'){ 
						if(val[prev].count(a+j)==0 || val[prev][a+j]>val[curr][a]+j)
							val[prev][a+j]=val[curr][a]+j;
						else break;
					} else break;
				}
				loop(j,1,v+1){
					if(a-j>=0 && road[i][a-j]!='X'){ 
						if(val[prev].count(a-j)==0 || val[prev][a-j]>val[curr][a]+j){
							val[prev][a-j]=val[curr][a]+j;
						}
						else break;
					} else break;
				}
			}
			//puts("");
			val[curr].clear();
			for(it = val[prev].begin();it!=val[prev].end();it++) {
				a=(*it).x;
				//printf("# %d",a);
				if(i==m-1 || road[i+1][a]=='.') val[curr][a]=val[prev][a];
			}//puts("");
			val[prev].clear();
		}
		if(val[curr].count(f)!=0) printf("%d\n",val[curr][f]);
		else puts("-1");
	}
	return 0;
}
