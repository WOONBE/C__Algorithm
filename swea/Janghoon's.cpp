//
// Created by 김헌우 on 2024/03/07.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans, n, height;
int num_lst[21];
int visited[21];

void init(){
    ans = 987654321; //가장 근접한 탑을 저장할 곳
    for(int i=0; i<21; i++){
        num_lst[i] = 0;
        visited[i] = 0;
    }

}

bool compare(int a, int b) {
    return a > b; // 내림차순 정렬을 위해 '>' 연산자 사용
}

void input(){
    cin >> n >> height;
    for(int i=0; i<n; i++){
        cin >> num_lst[i];
    }
    sort(num_lst,num_lst+n,compare);

}


void solve(int cnt, int tot){ //합친 점원, 합계


    if(tot >= height){
        int diff = tot - height;
        ans = min(ans, diff);
        return; //할때마다 값 갱신
    }
    for(int i=cnt; i<n; i++){//여기도 i는 cnt부터임
        if(visited[i] == 0){
            visited[i] = 1;
            solve(i, tot + num_lst[i]); //이부분에서 i+1하는 바람에 쓸데없이 터짐
            visited[i] = 0;
        }
    }
}
int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++) {
        init();
        input();
        solve(0, 0);
        cout << '#' << tc << ' ' << ans << "\n";
    }
}
