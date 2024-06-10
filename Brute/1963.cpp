#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int T;
string startNum, endNum;
bool visited[10001];
bool check[10001];

void Erato(){
    for(int i=2; i<10000; i++){
        if(check[i] == false){
            for(int j= i*i; j<10000; j+=i){
                check[j] = true;
            }
        }
    }
}
void dfs(){
    queue<pair<string ,int>> q;
    visited[stoi(startNum)] = true;
    q.push({startNum,0});
    while(!q.empty()){  // ! 안붙여서 헤맴
        auto cur = q.front(); q.pop();
        string s = cur.first;
        int cnt = cur.second;
        if(s == endNum){
            cout << cnt << "\n";
            return;
        }
        for(int i=0; i<4; i++){ //4자리 확인
            for(int j=0; j<=9; j++){ //10개 수중에 확인
                string num = s;
                num[i] = j + '0'; //그 자리에 수 in
                if(check[stoi(num)] == true) continue; //소수 아니면 패스
                if(visited[stoi(num)] == true) continue; //이미 방문했으면 패스
                if(stoi(num) < 1000) continue; //1000보다 작으면 패스
                visited[stoi(num)] = true;
                q.push({num, cnt+1});
            }
        }
    }
    cout << "Impossible" << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    Erato(); //일단 소수들은 다 체크

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> startNum >> endNum;
        dfs();
        memset(visited, false, sizeof(visited));
    }
}
