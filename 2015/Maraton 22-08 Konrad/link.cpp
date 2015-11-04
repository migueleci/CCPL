#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 -1
#define LIM                 100005
#define INF                 1e9
#define EPS                 1e-9
#define x                   first
#define y                   second
#define pb                  pushback
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;

char s[LIM], temp[LIM];
int len, f[LIM];
int booth(){
	int k=0, i, j;
	strcpy(temp, s);
	strcat(s, temp);
	SET(f, -1);
	loop(j, 1, 2*len){
		i=f[j-k-1];
		while(i!=-1 && s[j]!=s[k+i+1]){
			if (s[j]<s[k+i+1]) k=j-i-1;
			i=f[i];
		}
		if (i==-1 && s[j]!=s[k+i+1]){
			if (s[j]<s[k+i+1]) k=j-i-1;
			f[j-k]=-1;
		}
		else f[j-k]=i+1;
	}
	return k;
}
int main(){
	int n, i;
	//freopen("link.txt", "r", stdin);
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		len=strlen(s);
		i=booth();
		printf("%d\n", i+1);
	}
	return 0;
}
