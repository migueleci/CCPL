//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#include <map>

#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define rev(i, a, b) for(i=a; i>=b; i--)
#define SZ	2000000
#define READ(f) freopen(f, "r", stdin)
#define mp make_pair
#define x first
#define y second


using namespace std;
typedef pair<int,int> ii;
typedef long long large;

char inp[500];
int permlen[60],len,N;

large mask;
int a[55];
bool bck(int id, int x, int r){
	int i;
	large te;
	if (id==N && r==0) {
		printf("%d", a[0]);
		loop(i, 1, N) printf(" %d", a[i]);
		puts("");
		return true;
	}
	if (r==0) return false;
	a[id]=inp[x]-'0';
	if(a[id]>0 || x+1<len){
		a[id]=a[id]*10+inp[x+1]-'0';
		//printf("-->%d %d %d -->%d\n", id, x, r, a[id]);
		if (a[id]>0 && a[id]<=N){
			te=1LL;
			te<<=(a[id]);
			if (a[id]>0 && a[id]<=N  && (mask&te)==0){
				mask^=te;
				if (bck(id+1, x+2, r-1)) return true;
				mask^=te;
			}
		}
	}
	a[id]=inp[x]-'0';
	//printf("-->%d %d %d -->%d\n", id, x, r, a[id]);
	te=1LL;
	te<<=(a[id]);
	if (a[id]>0 && a[id]<=N && (mask&te)==0){
		mask^=te;
		if (bck(id+1, x+1, r-1)) return true;
		mask^=te;
	}
	return false;
}

void pre(){
	int i;
	permlen[0]=0;
	loop(i,1,10) permlen[i]=permlen[i-1]+1;
	loop(i,10,60) permlen[i]=permlen[i-1]+2;
}

int main(void){
	int i;
	pre();
	//freopen("j.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%s",inp)==1){
		len=strlen(inp);
		N = lower_bound(permlen,permlen+60,len)-permlen;
		mask=0;
		//puts(inp);
		bck(0,0,N);
		//printf("%d\n",N);
	}
	return 0;
}
