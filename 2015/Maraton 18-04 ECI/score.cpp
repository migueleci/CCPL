#include <bits/stdc++.h>
#define LIM	1100
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;
int n, deg, sum, i, j;
char cad[100];

int main(){
	scanf("%d", &n);
	
	while (n--){
		scanf("%s", cad);
		j=strlen(cad);
		sum=deg=0;
		loop(i, 0, j){
			if (cad[i]=='O'){
				sum+=++deg;
			}else{
				deg=0;
			}
		}
	
		printf("%d\n", sum);	
	}
	return 0;
}

