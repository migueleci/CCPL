//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 -1
#define LIM                 100000010
#define INF                 1e9
#define EPS                 1e-9
#define x                   first
#define y                   second
#define pb                  push_back
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<large> vl;
typedef vector<ii > vii;

int notp[LIM];
vl primes;

void sieve(){
	large i,j,bound=LIM;
	SET(notp,0);
	notp[0]=notp[1]=1; 
	loop(i,2,bound) if(!notp[i]){
		for(j=i*i;j<bound;j+=i) notp[j]=1;
		primes.pb(i);
	}
}

int main(){
	//freopen("kebab.txt", "r", stdin);
	large ans,n,i,num=21446377;
	sieve();
	printf("%lld %d\n",num, notp[num]);
	/*
	while(scanf("%lld", &n)==1 && n>1){
		ans=i=0;
		while(n>0 && i<primes.size()){
			while(n%primes[i]==0 && n>0){
				n/=primes[i];
				ans++;
			}
			i++;
		}
		if(n>1) ans+=1;
		printf("%lld\n", ans);
	}*/
	return 0;
}
