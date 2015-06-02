#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define LIM   1000
#define EPS   1e-8

using namespace std;
int i, j, n, m, cas=1;
double izq, der, mid, suma, obj, vec[LIM];
double eval(double lev){
  suma=0;
     loop(i, 0, n*m) if (vec[i]<=lev) suma+=(lev-vec[i])*100;
    return suma;
}

int main(void){

  //READ("f.txt");
  while(scanf("%d%d", &n, &m)==2 && n+m>0){
    loop(i, 0, n*m){
      scanf("%lf", &vec[i]);
      if (i==0){
        izq=der=vec[0];
      }else{
      if (vec[i]>der) der=vec[i];
      if (vec[i]<izq) izq=vec[i];
      }
    }
    der=der+1;
    //printf("%lf %lf\n", izq, der);
    scanf("%lf", &obj);
    sort(vec, vec+n*m);
    while(eval(der)<obj) der=der+(der-izq);
    //printf("%lf %lf\n", izq, der);
    //loop(i, 0, n*m) printf("%lf\n", vec[i]);
    while(der-izq>1e-8){
      mid=izq+(der-izq)/2;
      suma=0;
      loop(i, 0, n*m) if (vec[i]<=mid) suma+=(mid-vec[i])*100;
      //printf("suma=%lf\n", suma);
      if (suma>=obj) der=mid;
      else izq=mid;
    }
    mid=izq+(der-izq)/2;
    printf("Region %d\nWater level is %.2lf meters.\n", cas++, mid);
    izq=0; loop(i, 0, n*m) izq+=(vec[i]<mid)?1:0;
    printf("%.2lf percent of the region is under water.\n\n",izq*100.0/(n*m));
  }

  return 0;
}
