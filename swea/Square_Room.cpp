#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stack>
#define X first
#define Y second
 
using namespace std;
 
int n, x, y, ans_num;
int arr[1010][1010];
int move_cnt[1010][1010]; //move_cnt[x][y] = 이동 횟수
 
int ans; 
 
 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };
 
void init()
{
 
    ans = 0;
    memset(move_cnt, -1, sizeof(move_cnt));
 
}
 
 
 
void input() {
    cin >> n;
     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}
 
int dfs(int x, int y) {
 
    if (move_cnt[x][y] != -1)
        return move_cnt[x][y];
 
    move_cnt[x][y] = 1;
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (arr[nx][ny] == arr[x][y] + 1) {
                move_cnt[x][y] = move_cnt[x][y] + dfs(nx, ny); //기존 값에 dfs다 돌린 값을 추가해야 답이 나온다
            }
        }
    }
    return move_cnt[x][y];
 
 
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
 
    for (int tc = 1; tc <= t; tc++) {
 
        init();
        input();
        for (int i = 0; i < n; i++) { //모든 항목에 대하여 bfs 돌려서 인덱스 find
            for (int j = 0; j < n; j++) {
                int result = dfs(i, j);
 
                if (ans < result) {
                    ans = result;
                    ans_num = arr[i][j];
                }
                else if (ans == result) {
                    ans_num = min(ans_num, arr[i][j]);
                }
            }
        }
 
        cout << '#' << tc << ' ' <<ans_num << ' ' << ans << "\n";
 
 
    }  return 0;
}
