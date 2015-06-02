#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LEN 1000
using namespace std;
typedef long long int large;

char hexa[20][150][150];

void colocar(int f, int c, int tam){
	int i;
	loop(i,0,c) if(hexa[tam][f][i]==0) hexa[tam][f][i]=' ';
	loop(i,0,c) if(hexa[tam][f+1][i]==0) hexa[tam][f+1][i]=' ';
	loop(i,0,c) if(hexa[tam][f+2][i]==0) hexa[tam][f+2][i]=' ';
	hexa[tam][f][c]='_';
	hexa[tam][f+1][c]=' ';
	hexa[tam][f+1][c+1]='\\';
	hexa[tam][f+1][c-1]='/';
	hexa[tam][f+2][c-1]='\\';
	hexa[tam][f+2][c+1]='/';
	hexa[tam][f+2][c]='_';
}

void prec(){
	int i,j,mid,h,fil,pos,dif;
	memset(hexa,0,sizeof hexa);
	loop(i,0,20){
		h=2*(i+1)-1;
		//printf("tam=%d mid=%d\n",i+1,h);
		mid=h;
		pos=0;
		loop(j,0,h){ colocar(pos,mid,i); pos+=2; }
		dif=1; pos=0; h--;
		while(h>i){
			//printf("cant=%d\n",h);
      pos++; fil=pos;
      loop(j,0,h){
				colocar(fil,mid-2*dif,i);
				colocar(fil,mid+2*dif,i);
				fil+=2;
      }
      dif++; h--;
		}
	}
	//puts("OK");
}

int main(){
  int n,i;
  prec();
  while(scanf("%d",&n)==1 && n!=-1){
		loop(i,0,4*n-1) puts(hexa[n-1][i]);
		printf("***\n");
  }
  return 0;
}
