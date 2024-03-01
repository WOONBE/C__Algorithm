//
// Created by 김헌우 on 2024/03/01.
//
#include <iostream>
#include <cstring>
typedef long long ll;

int n,total_sum;
ll ans;
int num_arr[10];
int exps[9] = { 1, 2, 4, 8, 16, 32, 64, 128, 256 };
int factorial[9] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };
int visited[10];

using namespace std;
void init(){
    ans = 0;
    total_sum = 0;
    memset(visited,0, sizeof(visited));
    for(int i=0; i<n; i++){
        total_sum += num_arr[i];
    }
}
void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num_arr[i];
    }
}

void backTracking(int cnt, int left, int right){

    if(cnt == n){
        ans++;
        return;
    }
    if(left >= total_sum - left){
        ans += exps[n-cnt] * factorial[n-cnt];
        return; //남은 갯수만큼 조합
    }

    for(int i=0; i<n; i++){
        if(visited[i] == 1)
            continue;
        visited[i] = 1;
        backTracking(cnt+1, left+num_arr[i], right); //이부분 right인데 오타

        if(left >= right + num_arr[i])
            backTracking(cnt+1, left, right+num_arr[i]);
        visited[i] = 0;
    }


}

int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        input();
        init(); //반대로 넣으니 해결(input할때 합계 더하는 식이라 안더해졌음)
        backTracking(0,0,0);

        cout << '#' << tc << ' ' << ans << "\n";

    }
    return 0;
}
