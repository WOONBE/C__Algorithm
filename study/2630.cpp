#include <bits/stdc++.h>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0);

int N,white_cnt,blue_cnt; //하얀색 0, 파란색 1
int arr[128][128];
void bfs(int x, int y,int n){
    int start_color = arr[x][y];
    bool is_same_color = true;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[i][j] != start_color){
                is_same_color = false;
                break;
            }
        }
    }
    if(is_same_color == true){
        if(start_color == 0){
            white_cnt++;
        }else{
            blue_cnt++;
        }
        return;
    }else{
        bfs(x,y,n/2);
        bfs(x+n/2,y,n/2);
        bfs(x,y+n/2,n/2);
        bfs(x+n/2,y+n/2,n/2);
    }
}
int main(){
    First
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    bfs(0,0,N);

    cout << white_cnt << "\n";
    cout << blue_cnt << "\n";
}