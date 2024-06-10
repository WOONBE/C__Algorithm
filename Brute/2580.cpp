#include <iostream>
#include <vector>


using namespace std;
int board[9][9];
vector<pair<int,int>> v;
int zero_cnt=0;
bool isOver = false;

bool check(int x, int y, int value){
    for(int i=0; i<9; i++){
        if(board[x][i] == value) return false;
        if(board[i][y] == value) return false;

    }
    int start_x = x/3;
    int start_y = y/3;
    start_x *= 3;
    start_y *= 3;
    for(int i=start_x; i<start_x+3; i++){
        for(int j=start_y; j<start_y+3; j++){
            if(board[i][j] == value) return false;

        }
    }
    return true;
}
void dfs(int num){
    if(isOver){
        return;
    }
    if(num == zero_cnt){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << ' ';
            }cout << "\n";
        }
        isOver = true;
        return;
    }
    else{
        int nx = v[num].first;
        int ny = v[num].second;
        for(int i=1; i<=9; i++){
            if(check(nx,ny,i)){
                board[nx][ny] = i;
                dfs(num+1);
                board[nx][ny] = 0;
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                v.push_back({i,j});
            }
        }
    }
    zero_cnt = v.size();
    dfs(0);
    return 0;


}
