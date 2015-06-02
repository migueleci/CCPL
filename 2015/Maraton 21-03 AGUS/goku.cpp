#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define rev(i, a, b) for(i=a; i>=b; i--)
#define SZ	2000000

using namespace std;
char aux[SZ];

int main(void){
	int i,n, cant,j;
	char tmp[SZ];
	char *tok1, *tok2;
	//freopen("g.txt","r",stdin);
	while(gets(tmp)){
		if(tmp[0]=='\n' || tmp[0]=='\0') gets(tmp);
		SET(aux,0);
		cant=0;
		tok1=strtok(tmp,":");
		n=atoi(tok1);
		tok1=strtok(NULL,":");
		tok2=strtok(tok1," ");
		while(tok2!=NULL){
			j=atoi(tok2);
			aux[j]=1;
			cant++;
			tok2=strtok(NULL," ");
		}
		if(cant==n) printf("Goku already has them all!\n");
		else if (cant==0) printf("Goku needs to find them all!\n");
		else{
			int first=1;
			loop(j,1,n+1) if(aux[j]==0) (first? printf("%d",j),first=0 : printf(" %d",j));
			puts("");
		}
	}
	return 0;
}
