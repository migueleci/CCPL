#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define SET(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM
#define INF
#define LEN 50005
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<int> di;

char msg[200], *pt, *pt2;
map<string, int> id, habla;
int idlen, mejor;
int ans[LEN], prev[LEN];

void recurs(int x){
	if (prev[x]==-1) printf("%d", x+1);
	else{
		recurs(prev[x]);
		printf(" %d", x+1);
	}
}

int buscar(int x, int c){
	while (msg[x]!=0 && msg[x] !=c) x++;
	return x;
}

int main(){
	int x,len, i, j;
	//freopen("J.txt","r",stdin);
	while(scanf("%d",&len)==1){
		id.clear(); idlen=mejor=0;
		habla.clear();
		SET(prev, -1);
		loop(x,0,len){
			ans[x]=0;
			scanf(" %[^\n]",msg);
			//printf("%s\n",msg);
			pt=strtok(msg, ":");
			//printf("%s at %d\n", pt, x);
			if (id.count(pt+1)==0) id[pt+1]=idlen++, habla[pt+1]=x;
			pt2=strtok(NULL, "@");
			if ((pt2=strtok(NULL, "@"))==NULL) continue;
			while(pt2!=NULL){
				loop(i, 1, LEN) if (pt2[i]==0 || pt2[i]==' ') break;
				pt2[i]=0;
				//printf("%s (%d) vs %s (%d)\n", pt+1, habla[pt+1], pt2, habla[pt2]);
				if (strcmp(pt+1, pt2)!=0){
					//puts("OJO");
					//printf("--    >%s at %d\n", pt2, x);
					if (id.count(pt2)==1){
						if (ans[habla[pt2]]+1>ans[x]){
							ans[x]=ans[habla[pt2]]+1;
							prev[x]=habla[pt2];
						}
					}
				}
				pt2=strtok(NULL, "@");
			}
			if (ans[x]>ans[habla[pt+1]]) habla[pt+1]=x;
			if (ans[x]>ans[mejor]) mejor=x;
		}
		printf("%d\n", ans[mejor]+1);
		recurs(mejor); puts("");
	}
	return 0;
}
