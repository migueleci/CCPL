#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LIM 10005
using namespace std;
typedef long long int large;

int main(){
  large n, i, ans[LIM];
  ans[0]=ans[1]=1;
  loop(i, 2, LIM){
    ans[i]=ans[i-1]*i;
    while(ans[i]%10==0) ans[i]/=10;
    ans[i]%=1000000000;
  }
  while(scanf("%lld",&n)==1){
    printf("%5lld -> %lld\n",n,ans[n]%10);
  }
  return 0;
}
