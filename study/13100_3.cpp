#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

//회전 함수(미리 회전 시키고 백트래킹 진입)
//옮기는 함수(한쪽 방항으로)
//백트래킹(5번 이동시 마무리)
int arr[21][21];
int N,mx_val;
void rotate(){
    int tmp[21][21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp[i][j] = arr[N-j-1][i];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}
void find_mx_val(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mx_val = max(mx_val,arr[i][j]);
        }
    }
}

void down(){
    for(int i=0; i<N; i++){
        int tmp[21] = {0,};
        int idx = N-1;
        for(int j=N-1; j>=0; j--){
            if(arr[j][i] == 0) continue;
            if(tmp[idx]==0){
                tmp[idx] = arr[j][i];
            }else if(tmp[idx] == arr[j][i]){
                tmp[idx] *= 2;
                idx--;
            }else{
                idx--;
                tmp[idx] = arr[j][i];
            }
        }
        for(int j=N-1; j>=0; j--){
            arr[j][i] = tmp[j];
        }
    }
}
void move(int dir){
    while(dir--){
        rotate();
    }
    down();
}
void dfs(int cnt){
    if(cnt == 5){
        find_mx_val();
        return;
    }

    int tmp[21][21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp[i][j] = arr[i][j];
        }
    }

    for(int dir=1; dir<5; dir++){
        move(dir);//돌릴 방향 지정
        dfs(cnt+1); //백트래킹 진행
        for(int i=0; i<N; i++) { //좌표 원복
            for (int j = 0; j < N; j++) {
                arr[i][j] = tmp[i][j];
            }
        }
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

    dfs(0);

    cout << mx_val << "\n";

}