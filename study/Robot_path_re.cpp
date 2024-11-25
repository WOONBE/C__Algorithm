#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int H,W;
char arr[25][25];
bool visited[25][25];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<pair<int,int>> v;

string short_path = "-1";
int result_dir, result_x, result_y,start_x,start_y,start_dir;

void dfs(int x, int y, int direction, int visit_cnt, string commands){

    if(visit_cnt == v.size()){
        if(short_path == "-1" || commands.size() < short_path.size()){
            short_path = commands;
            result_x = start_x;
            result_y = start_y;
            result_dir = start_dir;
        }
        return;
    }
    for(int dir=0; dir<4; dir++){
        int nxt_dir = (direction + dir) % 4;
        string cmd = "A";
        if(dir == 1) cmd = "LA"; //실수
        else if(dir == 2) cmd = "LLA";
        else if(dir == 3) cmd = "RA";

        int nx1 = x + dx[nxt_dir];
        int ny1 = y + dy[nxt_dir];
        int nx2 = x + 2 * dx[nxt_dir];
        int ny2 = y + 2 * dy[nxt_dir];
        if(nx2 >= H || ny2 >= W || nx2 < 0 || ny2 <0) continue;
        if(arr[nx1][ny1] != '#' || arr[nx2][ny2] != '#' ||visited[nx1][ny1] || visited[nx2][ny2]) continue;

        visited[nx1][ny1] = visited[nx2][ny2] = true;
        dfs(nx2,ny2,nxt_dir,visit_cnt + 2, commands + cmd);
        visited[nx1][ny1] = visited[nx2][ny2] = false;
    }
}

int main(){
    First

    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '#'){
                v.push_back({i,j});
            }
        }
    }

    for(auto [x,y] : v){
        start_x = x;
        start_y = y;
        for(int dir=0; dir<4; dir++){
            start_dir = dir;
            memset(visited,false,sizeof(visited));
            visited[x][y] = true;
            dfs(x,y,dir,1,"");
        }
    }

    char startChar = 'v';
    if (result_dir == 1) startChar = '>';
    else if (result_dir == 2) startChar = '^';
    else if (result_dir == 3) startChar = '<';


    cout << result_x +1<< " " << result_y+1 << endl;
    cout << startChar << endl;
    cout << short_path << endl;

    return 0;
}