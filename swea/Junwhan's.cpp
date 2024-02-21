#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define mx 9

using namespace std;


int arr[mx];
int selected[mx] = { 0, };
int t, n;
int sum;
int answer;
int Exp[] = {1,2,4,8,16,32,64,128,256,512 };
int Factorial[] = {0,1,2,6,24,120,720,5040,40320,362880 };



void dfs(int cnt, int left, int right) {

    if (cnt == n) {
        answer++;
        return;
    }
    if (left >= sum - left) { //왼쪽 저울의 무게가 나머지 남은 무게의 합보다 크면 그냥 재귀 필요없이 바로 값 계산
        answer = answer + Exp[n - cnt] *  Factorial[n - cnt]; //n-cnt = 남은 갯수
        return;
    }
    for (int i = 0; i < n; i++) {
        if (selected[i] == 1)continue;
        selected[i] = 1;
        dfs(cnt + 1, left + arr[i], right);

        if (right + arr[i] <= left) {
            dfs(cnt + 1, left, right + arr[i]);
        }
        selected[i] = 0; //백트래킹

    }
    

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        answer = 0;
        sum = 0;
        // selected 배열 초기화
        memset(selected, 0, sizeof(selected));
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum = sum +  arr[i];
        }
        
        dfs(0, 0, 0);

        cout << '#' << tc+1 <<' '<< answer << "\n";

    }
    
}
