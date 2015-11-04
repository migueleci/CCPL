#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define SET(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM
#define INF
#define LEN 10005
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int> ii;
typedef deque<int> di;

char s[LEN][45];
char sr[LEN][45];
int slen[LEN];
char pre[LEN*45];
char suf[LEN*45];

int 

int main(){
	freopen("dict.txt","r",stdin);
	while(scanf("%d",&len)==1){
		loop(i,0,len){
			scanf("%s",&s[i])
			slen[i]=strlen(s[i]);
			reverse_copy(s[i],s[i]+slen[i],sr[i]);
		}
		
	}
	return 0;
}
