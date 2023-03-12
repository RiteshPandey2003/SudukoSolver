#include<iostream>
using namespace std;
 int grid[9][9]={{0,6,0,1,0,4,0,5,0},{0,0,8,3,0,5,6,0,0},{2,0,0,0,0,0,0,0,0},{8,0,0,4,0,7,0,0,6},{0,0,6,0,0,0,3,0,0},{7,0,0,9,0,1,0,0,4},{5,0,0,0,0,0,0,0,2},{0,0,7,2,0,6,9,0,0},{0,4,0,5,0,8,0,7,0}};

bool possible(int x,int y,int n){
     for(int i=0;i<9;i++){
         if(grid[x][i]==n){
            return false;
         }
     }
     for(int i=0;i<9;i++){
          if(grid[i][y]==n){
             return false;
          }
     }
     int x1=(x/3)*3;
     int y1=(y/3)*3;
     
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[x1+i][y1+j]==n){
                  return false;         
            }
        }
     }
     return true;
}

void solve(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                for(int k=0;k<10;k++){
                    if(possible(i,j,k)){
                        grid[i][j]=k;
                        solve();
                        grid[i][j]=-1;
                    } 
                }
            }
        }
    }
     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             cout<<grid[i][j];
        }
     cout<<"\n";
   }
   printf("\n----------------");
}

int main(){
    solve();;
     return 0;
}
