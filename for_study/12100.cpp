#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int arr[21][21];
int N;
int answer;

//시계방향으로  회전
void rotate(){
    int temp[21][21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = arr[N-j-1][i];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = temp[i][j];
        }
    }
}

void up(){
    for(int i=0; i<N; i++){
        int temp[21] = {}; //여기 초기화 안해줘서 문제
        int idx = 0;
        for(int j=0; j<N; j++){
            if(arr[j][i] == 0) continue;
            if(temp[idx] == 0) temp[idx] = arr[j][i];
            //합하는 수가 같은 경우
            else if(temp[idx] == arr[j][i]){
                temp[idx] *= 2;
                idx++;
            }
            //합하는 수가 다른경우
            else{
                idx ++;
                temp[idx] = arr[j][i];
            }

        }
        for(int j=0; j<N; j++){
            arr[j][i] = temp[j];
        }
    }
}
void move(int dir){
    while(dir--){
        rotate();
    }
    up();
}

int findMax() {
    int maxVal = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxVal = max(maxVal, arr[i][j]);
        }
    }
    return maxVal;
}

// 백트래킹
void dfs(int cnt) {
    if (cnt == 5) {
        answer = max(answer, findMax());
        return;
    }

    int backup[21][21];
    // 현재 상태를 백업
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            backup[i][j] = arr[i][j];
        }
    }

    // 4방향으로 이동
    for (int dir = 1; dir < 5; dir++) {
        move(dir);  // 이동
        dfs(cnt + 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = backup[i][j];
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

    cout << answer << "\n";


}
