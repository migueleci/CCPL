#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define SZ   30000
#define EPS   1e-8

using namespace std;
typedef long long int large;

large A[SZ],asz;
char Achar[SZ];
large memo[SZ];
large LIMIT=pow(2,31)-1;

large f(int lo){
  if(memo[lo]!=-1) return memo[lo];
  large best=0LL;
  if(lo!=asz){
    large n=A[lo]; int hi=lo+1;
    while(hi<=asz && n<=LIMIT && n>=0){
      best=max(best,n+f(hi));
      n=10LL*n+A[hi];
      hi++;
    }
  }
  return memo[lo]=best;
}

int main(void){
  int i,casos;
  //READ("j.txt");
  gets(Achar);
  sscanf(Achar,"%d", &casos);
  while(casos--){
    SET(Achar,0);
    gets(Achar);
    loop(asz,0,SZ){
      if(isdigit(Achar[asz])) A[asz]=Achar[asz]-'0';
      else break;
    }
    SET(memo,-1);
    printf("%lld\n",f(0));
  }
  return 0;
}
