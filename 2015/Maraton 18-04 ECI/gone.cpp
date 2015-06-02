#include <bits/stdc++.h>
#define LEN 30
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;

typedef pair<int,int> ii;

ii memo[LEN+2][200];
int f[LEN],d[LEN],t[LEN],h0,len,nexttime[LEN+2][200],btime[LEN+2];

ii q(int lo, int h){
	if(lo==len || h<=0) return ii(0,0);
	if(memo[lo][h].x!=-1) return memo[lo][h];
	int ans=0, ans2=0, ftime=0 , nextf=f[lo] ,fished=0, aux=0,besttime=0;
	ii p;
	while(ftime<=h){
		p = q(lo+1,h-t[lo]-ftime);
		ans2 = fished+p.x;
		if(ans2 >= ans) ans=ans2, besttime=ftime, nexttime[lo][h]=p.y;
		fished += nextf;
		nextf -= d[lo];
		if(nextf <= 0) nextf=0,++aux;
		ftime += 1;
	}
	return memo[lo][h]=ii(ans,besttime);
}

void compute_btime(int lo,int h){
	if(lo==len) return;
	btime[lo] = q(lo,h).y;
	compute_btime(lo+1,h-btime[lo]-t[lo]);
}

int main(){
	int i,first=1;
	ii p;
	//freopen("gone.in","r",stdin);
	while(scanf("%d",&len)==1 && len>0){
		scanf("%d",&h0); h0*=12;
		loop(i,0,len) scanf("%d",&f[i]);
		loop(i,0,len) scanf("%d",&d[i]);
		loop(i,0,len-1) scanf("%d",&t[i]);
		t[len-1]=100000;
		SET(memo,-1);
		SET(nexttime,0);
		p = q(0,h0);
		compute_btime(0,h0);
		if(!first) printf("\n"); first=0;
		printf("%d",btime[0]*5);
		loop(i,1,len) printf(", %d",btime[i]*5);
		printf("\nNumber of fish expected: %d\n",p.x);
	}
	return 0;
}

