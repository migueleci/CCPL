#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define SZ   1000100
#define EPS   1e-8

using namespace std;
typedef long long int large;

int main(void){
    char cad[20];
  int vec[SZ], p, y, i, mx, nx, lo;
  //READ("i.txt");
  while(gets(cad)){
    y=atoi(cad);
    gets(cad);
    p=atoi(cad);
    loop(i,0,p) gets(cad), vec[i]=atoi(cad);
    //printf("p %d y %d\n", p, y);
    mx=0,nx=0,lo=0;
    loop(i,0,p){
      lo=upper_bound(vec,vec+p,vec[i]+y-1)-vec-i;
      //printf("i %d lo %d mx %d nx %d\n", i, lo, mx, nx);
      if(mx<lo){
        mx=lo; nx=i;
      }
    }
    lo=upper_bound(vec,vec+p,vec[nx]+y-1)-vec-1;
    printf("%d %d %d\n", mx, vec[nx], vec[lo]);
    gets(cad);
  }
  return 0;
}
