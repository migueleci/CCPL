#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define rev(i, a, b) for(i=a; i>=b; i--)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
#define SZ 	1000002
#define READ(file) freopen(file, "r", stdin)
using namespace std;
typedef long long int large;
int isp[SZ],a[SZ],b[SZ];
vector<int> primes;

large sumpf(int n){
	large N=n;
  large idx=0;
  large pf=primes[idx],ans=0;
  while(pf*pf<=N){
    while(N%pf==0){ N/=pf; ans+=pf;}
    pf=primes[++idx];
  }
  if(N!=1) ans+=N;
  return ans;
}

int main(void){
	int i,nn,mm,casos,caso,ans;
	//READ("f.txt");
  SET(isp,0);
  isp[0]=isp[1]=1;
  large n,m;
  loop(n,2,SZ) if(isp[n]==0){
		for(m=n*n;m<=SZ;m+=n) isp[m]=1;
		primes.push_back((int)n);
  }
	loop(i,0,SZ) a[i]=sumpf(i);
	loop(i,0,SZ) b[i]=b[a[i]]+1;
	scanf("%d",&casos);
	loop(caso,1,casos+1){
		scanf("%d %d", &nn, &mm);
		if(nn>mm) swap(nn,mm);
    ans=0;
    loop(i,nn,mm+1) ans=max(ans,b[i]);
		printf("Case #%d:\n%d\n",caso,ans);
	}
	return 0;
}
