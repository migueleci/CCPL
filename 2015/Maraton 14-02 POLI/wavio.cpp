#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define SZ   10005
#define EPS   1e-8

using namespace std;
typedef long long int large;
int baux[SZ],aaux[SZ],A[SZ],B[SZ],b[SZ],tsz,bsz;

void lislog(int* f,int* t){
  int i,j;
  SET(b,0);
  bsz=0;
  loop(i,0,tsz){
    j=lower_bound(b,b+bsz,t[i])-b;
    b[j] = t[i];
    bsz+=j==bsz;
    f[i] = j+1;
  }
}

int main(){
  int i,ans;
  //READ("b.txt");
  while(scanf("%d",&tsz)==1){
    loop(i,0,tsz) scanf("%d",&A[i]);
    loop(i,0,tsz) B[i] = A[tsz-1-i];
    lislog(aaux,A);
    lislog(baux,B);
    ans=0;
    loop(i,0,tsz) ans=max(ans, min(aaux[i],baux[tsz-1-i]));
    printf("%d\n",ans*2-1);
  }
  return 0;
}
