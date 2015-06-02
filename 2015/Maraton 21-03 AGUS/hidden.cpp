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
#define pb push_back
#define x first
#define y second


using namespace std;

int N;
int j[200050];

int main(void){
	int i, k, b, c, ct,dist;
	freopen("i.txt","r",stdin);
	while(scanf("%d ",&N)==1){
		b=0;
		SET(j,0);
		loop(i, 0, N){
			scanf("%d", &c);
			dist=max(b, c)-min(b, c);
			j[min(b,c)]=max(dist,j[i]);
			b=c;
		}
		//loop(i,0,N) printf("%d ",j[i]); puts("");
		ct=N;
		loop(i,0,N-1){
			if(j[i]>1 && j[i+1]>=j[i]) ct--;
			else if(j[i]>1 && j[i+1]<j[i]){
				b=j[i]-1; c=i+1;
				while(b>1 && c<N-1){
					if(j[c+1]>=b){
							ct--;
							break;
					}
					c++; b--;
				}
			}
		}
		printf("%d\n", ct);
	}
	return 0;
}
