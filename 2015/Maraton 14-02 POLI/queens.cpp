#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define SZ   5050
#define EPS   1e-8

using namespace std;
typedef long long int large;

int chess[10],sol,f,c;

void printChess(){
  printf("%2d      ",++sol);
  printf("%d %d %d %d %d %d %d %d\n",chess[0]+1,chess[1]+1,chess[2]+1,chess[3]+1,chess[4]+1,chess[5]+1,chess[6]+1,chess[7]+1);
}

bool safe(int column){
  int i;
  loop(i,0,8){
    if(i==column || chess[i]==-1) continue;
    if(chess[i]==chess[column]) return false;
    if(chess[column]==chess[i]+(column-i)) return false;
    if(chess[column]==chess[i]-(column-i)) return false;
  }
  return true;
}

void position(int column){
  int i;
  if(chess[column]==-1){
    loop(i,0,8){
      chess[column]=i;
      if(safe(column)){
        if(column==7) printChess();
        else if (column < 7) position(column+1);
      }
      chess[column]=-1;
    }
  }else{
    if (column==7 && c==8){
      printChess();
    } else if (column < 7){
      position(column+1);
    }
  }
}

int main(void){
  int n,i;
  //READ("e.txt");
  scanf("%d",&n);
  loop(i,0,n){
    SET(chess,-1);
    sol=0;
    scanf("%d %d",&f,&c);
    chess[c-1]=f-1;
    if (i>0) puts("");
    printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    position(0);
  }
  return 0;
}
