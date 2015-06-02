#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define READ(file)  freopen(file, "r", stdin)
#define INF 2000000000
#define SZ   105
#define EPS   1e-8


using namespace std;
typedef long long int large;

int dest[SZ][SZ],w[SZ][SZ],RR,CC,R,C;

int main(){
  int r,c,ans,i,j;
  //READ("a.txt");
  while(scanf("%d %d %d %d",&RR,&CC,&R,&C)==4 && R+C+RR+CC>0){
    loop(r,0,RR)loop(c,0,CC)scanf("%1d",&dest[r][c]);
    //loop(r,0,RR){loop(c,0,CC)printf("%1d ",dest[r][c]); puts("");}
    SET(w,0);
    ans=0;
    loop(r,0,RR-R+1){
      loop(c,0,CC-C+1)
        if(dest[r][c]!=w[r][c]){ans++; loop(i,r,R+r)loop(j,c,C+c) w[i][j]=1-w[i][j]; }
    }
    loop(r,0,RR&&ans!=-1){
      loop(c,0,CC&&ans!=-1)
        if(dest[r][c]!=w[r][c]) ans=-1;
    }
    //loop(r,0,RR){loop(c,0,CC)printf("%1d ",w[r][c]); puts("");}
    printf("%d\n",ans);
  }
  return 0;
}
