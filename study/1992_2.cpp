#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N;
string arr[64];

void bfs(int x, int y, int n){

    char start = arr[x][y];
    bool is_same = true;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[i][j] != start){
                is_same = false;
                break;
            }
        }
    }
    if(is_same == true){
        cout << start;
    }else{
        cout << '(';
        bfs(x,y,n/2);
        bfs(x,y+n/2,n/2);
        bfs(x+n/2,y,n/2);
        bfs(x+n/2,y+n/2,n/2);
        cout << ')';
    }
}
int main(){
    First
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    bfs(0,0,N);
}