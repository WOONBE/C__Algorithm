#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[21][21];
int N;
int max_val = 0;


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


void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
}

void find_max(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            max_val = max(max_val,arr[i][j]);
        }
    }
}
void down(){
    for(int i=0; i<N; i++){
        int temp[21] = {0,};
        int idx = N-1;
        for(int j=N-1; j>=0; j--){
            if(arr[j][i] == 0) continue;
            if(temp[idx] == 0){
                temp[idx] = arr[j][i];
//                idx--;
            }else if(temp[idx] == arr[j][i]){
                temp[idx] *=2;
                idx--;
            }else{
                idx--;
                temp[idx] = arr[j][i];
            }
        }
        for(int j=N-1; j>=0; j--){
            arr[j][i] = temp[j];
        }
    }
}
void go(int dir){
    while(dir--){
        rotate();
    }
    down();
}


void play(int cnt){
    if(cnt == 5){
        find_max();
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout << arr[i][j] << ' ';
//            }cout << "\n";
//        }
        return;
    }
    int temp[21][21];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = arr[i][j];
        }
    }

    for(int dir=1; dir<5; dir++){
        go(dir);
        play(cnt+1);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = temp[i][j];
            }
        }
    }
}


int main(){
    First
    input();

    play(0);

    cout << max_val << "\n";

}