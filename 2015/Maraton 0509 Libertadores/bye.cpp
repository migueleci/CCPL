#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LEN 1000
using namespace std;
typedef long long int large;

int main(){
  int e,f,s,m,ep,fp,sp,mp,ec,fc,sc,mc,mmax;
  while(scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&ep,&fp,&sp,&mp)==8 && e>-1){
    mmax=-1;
    mmax=max(e%ep==0? e/ep:e/ep+1,mmax);
    fc=f%fp==0? f/fp:f/fp+1; mmax=max(mmax,fc);
    sc=s%sp==0? s/sp:s/sp+1; mmax=max(mmax,sc);
    mc=m%mp==0? m/mp:m/mp+1; mmax=max(mmax,mc);
    printf("%d %d %d %d\n",mmax*ep-e,mmax*fp-f,mmax*sp-s,mmax*mp-m);
  }
  return 0;
}
