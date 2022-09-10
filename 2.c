#include<stdio.h>
#include<stdlib.h>

int arr[100][100];
int visited[100][100];
int n,m;

int xdir[4] = {0, 1, -1,  0};
int ydir[4] = {1, 0,  0, -1};

int canwalk(int row, int col){
    if(row < 0 || row >= n || col < 0 || col >= m)
        return 0;
    if(visited[row][col])
        return 0;
    if(arr[row][col])
        return 0;
    return 1;
}

int dfs(int row, int col){
    visited[row][col] = 1;
    if(row == n-1 && col == m-1){
        printf("Yes");
        exit(0);
    }
    for(int i=0;i<4;++i){
        int nextx = row + xdir[i];
        int nexty = col + ydir[i];
        if(canwalk(nextx, nexty)){
            dfs(nextx, nexty);
        }
    }
    visited[row][col] = 0;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&arr[i][j]);
        }
    }
    dfs(0,0);
    printf("No");
}