#include<stdio.h>

int arr[100][100];
int visited[100][100];
int n,m;

int canwalk(int row, int col){
    if(row < 0 || row >= n || col < 0 || col >= m)
        return 0;
    if(visited[row][col])
        return 0;
    if(arr[row][col])
        return 0;
    return 1;
}

int q[1000][2];
int qlidx,qridx;
int xdir[4] = {0, 1, -1,  0};
int ydir[4] = {1, 0,  0, -1};

int main(){
    int cnt = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 1)
                ++cnt;
        }
    }
    int numcw = n * m - cnt; 
    int curx = 0, cury = 0;
    cnt = 0;
    while(curx != n-1 && cury != m-1){
        visited[curx][cury] = 1;
        ++cnt;
        if(cnt >= numcw){
            printf("No");
            return 0;
        }
        for(int i=0;i<4;++i){
            int nextx = curx + xdir[i];
            int nexty = cury + ydir[i];
            if(canwalk(nextx, nexty)){
                q[qridx][0] = nextx;
                q[qridx][1] = nexty;
                ++qridx;
            }
        }
        curx = q[qlidx][0];
        cury = q[qlidx][1];
        ++qlidx;
    }
    printf("Yes");
}