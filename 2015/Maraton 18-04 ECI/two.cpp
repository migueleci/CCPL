#include <bits/stdc++.h>
#define LIM	1100
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;
int n, deg, sum, i, j;
char cad[LIM];

int main(){
	scanf("%s", cad);
	while (cad[0]!='0'){
		n=strlen(cad);
		sum=deg=0;
		loop(i, 0, n){
			sum+=cad[i]-'0';
		}
		++deg;
		printf("%s", cad);
		if (sum%9==0){
			while (sum>9){
				deg++;
				sprintf(cad, "%d", sum);
				n=strlen(cad);
				sum=0;
				loop(i, 0, n) sum+=cad[i]-'0';
			}
		printf(" is a multiple of 9 and has 9-degree %d.\n", deg);
		}else{
			printf(" is not a multiple of 9.\n");	
		}
		scanf("%s", cad);
	}
	return 0;
}

