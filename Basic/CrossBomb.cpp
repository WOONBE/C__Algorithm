#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int,int>> q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,startX,startY;
int arr[201][201];

//폭탄 터뜨려서 0으로 만드는 함수
void bomb(){
    int x = startX;
    int y = startY;

    int length = arr[x][y];
    arr[x][y] = 0;
    for(int i = 1; i<length; i++){
        for(int j=0; j<4; j++){
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];
            if(nx<1 || ny <1 || nx >n || ny > n) continue;
            arr[nx][ny] = 0;
        }
    }
}
//0인 부분을 제외하고 떨어지게 하는 함수
void fall() {
    for (int j = 1; j <= n; j++) {
        queue<int> q;
        for (int i = n; i >= 1; i--) {
            if (arr[i][j] != 0) {
                q.push(arr[i][j]);
            }
        }
        int idx = n;
        while (!q.empty()) {
            arr[idx][j] = q.front();
            q.pop();
            idx--;
        }
        while (idx > 0) {
            arr[idx][j] = 0;
            idx--;
        }
    }
}
//입력
void input(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    cin >> startX >> startY;
}
//출력
void output(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << "\n";
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    bomb();
    fall();
    output();
    return 0;
}