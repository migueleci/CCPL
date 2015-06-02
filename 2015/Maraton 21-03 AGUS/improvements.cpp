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
#define SZ	200050
#define READ(f) freopen(f, "r", stdin)
#define mp make_pair
#define pb push_back
#define x first
#define y second


using namespace std;
typedef pair<int,int> ii;
int a[SZ], tree[SZ];
int N, sz;
void increase(int i, int delta){
  for(;i<sz; i|=i+1) tree[i]+=delta;
}
int sum(int ind){
  int s=0;
  while (ind>=0){
    s+=tree[ind];
    ind&=ind+1;
    ind--;
  }
  return s;
}
int getsum(int lo, int hi){
  return sum(hi)-sum(lo-1);
}

int main(void){
	int i, j, k, b, c, ct;
	freopen("i.txt","r",stdin);
	while(scanf("%d ",&N)==1){
    loop(i, 0, N){
			scanf("%d", &a[i]);
		}
		j=ct=k=0;
		sz=N;
		SET(tree, 0);
		loop(i, 0, N) increase(i, 1);
    loop(i, 0, N){
      if (j==1){
        if (getsum(0, a[i]-1)>0) ct++;
        increase(a[i]-1, -1);
      }else{
        if (getsum(a[i], N-1)>0) ct++;
        increase(a[i]-1, -1);
      }
      j=1-j;
    }
    SET(tree, 0);
    j=0;
		loop(i, 0, N) increase(i, 1);
    loop(i, 0, N){
      if (j==1){
        if (getsum(0, a[i]-1)>0) k++;
        increase(a[i]-1, -1);
      }else{
        if (getsum(a[i], N-1)>0) k++;
        increase(a[i]-1, -1);
      }
      j=1-j;
    }
    printf("%d %d\n", ct, k);
    printf("%d\n", max(ct, k));
    /*






		sort(a, a+N);
		//sort(a, a+N, cmp);
		ct=0;
		loop(i, 0, N && j<N){
			printf("-------> %d-%d\n", a[i].x, a[i].y);
			i=lower_bound(a, a+N, ii(a[i].y,0))-a-1;
			ct++;
		}
		printf("ct=%d\n", ct);
		//kasjhdkajshdkajhsdkj
		t.clear();
		t.pb(a[0]);
		loop(i, 1, N){
			if (t[t.size()-1].x!=a[i].x ) t.pb(a[i]);
		}
		//loop(i, 0, N) printf("%d %d\n", a[i].x, a[i].y);
		ct=N;
		loop(i, 0, (int)t.size()){
			loop(j, i+1, (int)t.size() && t[j].x<t[i].y){
				if (t[i].y>t[j].x && t[i].y<t[j].y)
					{ct--; break;}
			}
		}
		printf("%d\n", ct);*/
	}
	return 0;
}
