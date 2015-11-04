#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define SET(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
#define LIM 110
#define INF -1
#define LEN -1
#define pb push_back
using namespace std;
typedef long long large;
typedef pair<int, int > ii;
typedef deque<int> di;

int main(){
	//freopen("ascii.txt","r",stdin);
	int n,m,i,j,op,ar;
	char cad[LIM];
	while(scanf("%d %d",&n,&m)==2){
        ar=0;
        loop(i,0,n) {
            scanf("%s",cad);
            op=0;
            loop(j,0,m){
                if(!op && (cad[j]=='/' || cad[j]=='\\' )) op=1;
                else if(op && (cad[j]=='\\' || cad[j]=='/' )) op=0, ar++;
                else if(cad[j]=='.' && op) ar++;
            }
        }
        printf("%d\n",ar);
	}
	return 0;
}
