#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LEN 1000
#define M 1000500000LL
#define setmem(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long int large;
typedef pair<int,int> ii;

large len;
large v[LEN*LEN];
large ans[LEN*LEN];
map<large,int> mapa;
map<large,int>::iterator it;
map<ii,large> b;

large binom(int n, int k){
  if(k==n-1 || k==1) return n;
	if(b.count(ii(n,k))) return b[ii(n,k)];
  b[ii(n,k)] = binom(n-1,k-1)+binom(n-1,k);
  return b[ii(n,k)];
}

void pre(){
  int n,k,breaking,i;
  large bnum;
  loop(n,4,200000){
		loop(k,2,n/2+1){
      if((bnum=binom(n,k))<M){
				//printf("%lld\n",bnum);
				if(mapa.count(bnum)) mapa[bnum]+= 1+(2*k!=n);
				else mapa[bnum] = 1+(2*k!=n);
			} else break;
		}
	}
	len=0;
  for(it=mapa.begin(); it!=mapa.end(); ++it)
		v[len++] = it->first;
  sort(v,v+len);
  //loop(i,0,10) printf("%lld ... ",v[i]);
  //printf("%lld ",v[len-1]);
  ans[0] = mapa[v[0]];
  loop(i,1,len) ans[i] = ans[i-1]+mapa[v[i]];
}

int main(){
  large n; int j;
	pre();
	//freopen("count.txt","r",stdin);
  while(scanf("%lld",&n)==1 && n>0){
    j = upper_bound(v,v+len,n)-v-1;
    printf("%lld\n",2*n-3 + (j==-1? 0 : ans[j]));
  }
  return 0;
}
