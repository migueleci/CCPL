#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define setmem(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll;

ll num[45];
ll acum,x;
int z;

ll potencia(ll ba, int exp){
	if(exp==0) return 1;
	ll x=potencia(ba,exp-1);
	if(x>5000000) z=1;
	return ba*x;
}

char line[100000];

int main(void){
	int i,t,j;
	//freopen("land.txt","r",stdin);
	gets(line);
	sscanf(line,"%d", &t);
	while(t--){
		z=0;
		loop(i,0,100000){
			gets(line);
			z = z || (strlen(line)>7);
			if(strlen(line)<=7) sscanf(line,"%lld",&x);
			else x=1;
			if(x<=0) break;
			num[i]=x;
		}
		if(!z){
			sort(num,num+i);
			acum=0LL;
			rev(j,i-1,0){
				if(num[j]>5000000) break;
				acum+=potencia(num[j],i-j);
				if(acum>5000000) break;
			}
			acum*=2;
		}
		if(!z && j==-1 && acum<=5000000) printf("%lld\n",acum);
		else puts("Too expensive");
	}
	return 0;
}
