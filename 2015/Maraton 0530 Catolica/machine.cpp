#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define LEN 2015
#define setmem(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll;

int w[10],l[5];

void solve(){
	int i,s=0;
	loop(i,0,10) s+=w[i];
	s/=4;
	l[1]=s-w[1]-w[9];
	l[2]=s-w[0]-w[9];
	l[3]=s-w[0]-w[8];
	l[0]=w[0]-l[1];
	l[4]=w[9]-l[3];
}

int main(){
	int ntc,tc,i;
	//freopen("machine.txt","r",stdin);
	scanf("%d",&ntc);
	loop(tc,1,ntc+1){
		loop(i,0,10) scanf("%d",&w[i]);
		solve();
		printf("Case %d:",tc);
		loop(i,0,5) printf(" %d",l[i]);
		printf("\n");
	}
	return 0;
}
