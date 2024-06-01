#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool broke_btn[10];

int n, btn_cnt;

bool isPossible(int num) { //누르는 버튼에 고장난 숫자가 있는지 여부 확인
    if (num == 0) {
        return !broke_btn[0]; //0부분 처리 해줘야함
    }
    while (num > 0) {
        if (broke_btn[num % 10]) return false;
        num /= 10;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> btn_cnt;

    for(int i=0; i<btn_cnt; i++){
        int btn_num;
        cin >> btn_num;
        broke_btn[btn_num] = true;
    }

    if(n == 100){
        cout << 0 << "\n";
        return 0;
    }

    int cnt = abs(100-n); //기본 cnt 설정

    for (int i = 0; i <= 1000000; i++) {
        if (isPossible(i)) {
            int pressCount = to_string(i).length() + abs(i - n);
            cnt = min(cnt, pressCount);
        }
    }

    cout << cnt << "\n";
    return 0;
}
