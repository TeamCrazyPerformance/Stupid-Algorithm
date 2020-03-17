#include <bits/stdc++.h>
using namespace std;

int m,n,cx,cy;
int arr[1000][1000];
//우하좌상
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

void bfs(){
    queue<pair<int,int>> q;
    q.push({cx,cy});
    arr[cx][cy]=2;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx= x+dx[i];
            int ny= y+dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위나감
            if(arr[nx][ny]==1){//갈수있으면
                q.push({nx,ny});
                arr[nx][ny]=arr[x][y]+1;
            }
        }
    }
}

int main(void){
    cin>>n>>m;
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){cx=i;cy=j;}
        }
    }
    bfs();
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]){
            cout<<arr[i][j]-2<<" ";
            } else cout<<0<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
