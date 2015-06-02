#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int a,b,nk;
  int i;
  while(scanf("%lld %lld",&a,&b)==2){
    printf("["); i=0;
    while(b>0){
      nk = a/b;
      printf("%lld",nk);
      a = a-b*nk;
      swap(a,b);
      printf("%c",(b==0)? ']' : (i==0? ';':','));
      i++;
    }
    printf("\n");
  }
  return 0;
}
