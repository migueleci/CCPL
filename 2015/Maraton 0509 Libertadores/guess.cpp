#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LEN 1000
using namespace std;
typedef long long int large;

char line[LEN];
int len;

large solve(){
  large ans=1,i;
  loop(i,0,len){
    if(line[i]=='Y') ans = (ans/__gcd(ans,i+1))*(i+1);
    else if(line[i]=='N') ;
    else break;
  }
  loop(i,0,len) if(line[i]=='N' && ans%(i+1)==0) return -1;
	return ans;
}

int main(){
  int e,f,s,m,ep,fp,sp,mp,ans,ec,fc,sc,mc,mmax;
  while(gets(line)){
    if(line[0]=='*') break;
    len = strlen(line);
    printf("%lld\n",solve());
  }
  return 0;
}
