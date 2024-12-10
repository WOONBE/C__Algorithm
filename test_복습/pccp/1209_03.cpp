#include <iostream>
#include <vector>
using namespace std;

int calculateTotalWeight(vector<int>& boxes) {
    int totalWeight = 0;
    int n = boxes.size();

    // 상자의 이동 가능한 위치를 찾기 위한 반복문
    for (int i = 0; i < n; i++) {
        // 상자 i를 오른쪽으로 밀 수 있는지 확인
        for (int j = i + 1; j < n; j++) {
            if (boxes[i] != 0 && boxes[j] == 0 && abs(boxes[i] - boxes[j]) < 2) {
                boxes[j] = boxes[i];  // 상자를 오른쪽으로 밀기
                boxes[i] = 0;  // 원래 위치는 비우기
                break;  // 한번 밀었으면 그 상자는 더 이상 움직이지 않음
            }
        }
    }

    // 밀어넣은 후 창고에 들어있는 상자들의 총합 구하기
    for (int i = 0; i < n; i++) {
        totalWeight += boxes[i];
    }

    return totalWeight;
}

int main() {
    int n;
    cin >> n;
    vector<int> boxes(n);

    // 상자 배열 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }

    // 총합을 계산하고 출력
    cout << calculateTotalWeight(boxes) << endl;

    return 0;
}
