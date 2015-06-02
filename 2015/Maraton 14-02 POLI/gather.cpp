#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define SZ   100005

using namespace std;
typedef long long int large;

int psz;
large xv[SZ],yv[SZ],D;

int main(){
  large acumx,acumy,ans,bestans,d,avx,avy,avxm,avym;
  int i,r,c;
  //READ("g.txt");
  while(scanf("%d",&psz)==1){
    loop(i,0,psz) scanf("%lld %lld",&xv[i],&yv[i]);
    scanf("%lld",&D);
    acumx = acumy = 0;
    loop(i,0,psz) acumx+=xv[i],acumy+=yv[i];
    avx = acumx/psz;
    avy = acumy/psz;
    bestans = -1;
    loop(r,-30,31)loop(c,-30,31){
      ans=0;
      avxm=avx+r;
      avym=avy+c;
      loop(i,0,psz&&ans!=-1){
        d = abs(xv[i]-avxm) + abs(yv[i]-avym);
        //printf("%lld\n",d);
        if(d>D) ans=-1;
        else ans+=d;
        //if(bestans!=-1 && ans>bestans) break;
      }
      if(bestans==-1) bestans=ans;
      else if(ans!=-1) bestans = min(bestans,ans);
      //printf("ans found: %d\n",ans);
    }
    if(bestans!=-1) printf("%lld\n",bestans);
    else printf("impossible\n");
  }
  return 0;
}
