#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define LIM 100010
#define EPS   1e-8

using namespace std;
typedef long long int large;

int rk[LIM], p[LIM];

int ffind(int x){
  if (p[x]<0) return x;
  return p[x]=ffind(p[x]);
}
bool funion(int a, int b){
  a=ffind(a), b=ffind(b);
  if (a!=b){
    if (rk[a]>rk[b]) swap(a, b);
    if (rk[a]==rk[b]) rk[b]+=1;
    p[a]=b;
  }
  return a!=b;
}


int main(void){
  int a, b, sol;
  //READ("h.txt");
  while(scanf("%d", &a)==1){
    sol=0;
    SET(rk, 0);
    SET(p, -1);
    while(a>-1){
      scanf("%d", &b);
      if (!funion(a, b)) sol++;
      scanf("%d", &a);
    }
    printf("%d\n", sol);
  }

  return 0;
}
