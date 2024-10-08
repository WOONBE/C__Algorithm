////
//// Created by 김헌우 on 2024/09/05.
////
////공사 메우기
////입력값
////구멍 개수, 판자 갯수
////구멍들 위치 오름차순으로
////가장 길이가 적은 판자를 사용해서 메우기
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//
//int hole;
//int pan;
//vector<int> v;
//
//int main(){
//
//    First
//    cin >> hole >> pan;
//
//    for(int i=0; i<hole; i++){
//        int place;
//        cin >> place;
//        v.push_back(place);
//    }
//
//    if(pan == 1){
//        cout << v[hole-1]- v[0] + 1;
//    }
//    if(pan >= 2){
//        int last_idx = v[hole-1];
//        int arr[last_idx];
//        for(int i=0; i<hole; i++){
//            arr[v[i]] = 1;
//        }
//        int cnt = 0;
//        for(int i = 0; i<=last_idx; i++){
//            if(arr[i] == 1){
//                cnt ++;
//
//            }
//        }
//        if(cnt % pan == 0){
//            cout << cnt / pan;
//        }
//        else{
//            cout << cnt / pan + 1;
//        }
//
//
//    }
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//
//int hole;
//int pan;
//vector<int> v;
//
//int main() {
//    First
//    cin >> hole >> pan;
//
//    for (int i = 0; i < hole; i++) {
//        int place;
//        cin >> place;
//        v.push_back(place);
//    }
//
//    // 구멍 위치 오름차순으로 정렬
//    sort(v.begin(), v.end());
//
//    // 구멍 사이의 간격을 계산
//    vector<int> gaps;
//    for (int i = 1; i < hole; i++) {
//        gaps.push_back(v[i] - v[i - 1]);
//    }
//
//    // 간격 내림차순 정렬
//    sort(gaps.begin(), gaps.end(), greater<int>());
//
//    for(auto i : gaps){
//        cout << i << ' ';
//    }
//
//    // 판자가 1개면 모든 구멍을 덮을 길이를 출력
//    if (pan == 1) {
//        cout << v[hole - 1] - v[0] + 1;
//        return 0;
//    }
//
//    // 판자 수가 여러 개일 경우
//    int totalLength = v[hole - 1] - v[0] + 1; // 모든 구멍을 덮는 길이
//    for (int i = 0; i < pan - 1 && i < gaps.size(); i++) {
//        // 큰 간격들을 덮어야 할 판자 수만큼 제외
//        totalLength -= (gaps[i] - 1); // 간격에 1을 빼는 이유는 간격 사이를 메우는 것이기 때문
//    }
//
//    cout << totalLength;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int hole, pan;
vector<int> v;

// 주어진 판자 길이로 구멍들을 덮을 수 있는지 확인하는 함수
bool canCoverWithBoards(int length) {
    int count = 1; // 최소한 1개의 판자는 필요
    int lastCovered = v[0]; // 첫 번째 구멍에서 시작

    for (int i = 1; i < hole; i++) {
        // 현재 판자로 덮을 수 없는 경우 새로운 판자를 사용
        if (v[i] - lastCovered + 1 > length) {
            count++;
            lastCovered = v[i]; // 새로운 판자가 덮을 시작점
        }
    }

    // 판자의 개수가 pan개 이하인지 확인
    return count <= pan;
}

int main() {
    First
    cin >> hole >> pan;

    for (int i = 0; i < hole; i++) {
        int place;
        cin >> place;
        v.push_back(place);
    }

    // 구멍 위치 오름차순 정렬
    sort(v.begin(), v.end());

    // 이분 탐색 범위 설정
    int low = 1;
    int high = v[hole - 1] - v[0] + 1;
    int ans = high;

    // 이분 탐색 시작
    while (low <= high) {
        int mid = (low + high) / 2;

        // 현재 판자 길이로 구멍들을 덮을 수 있는지 확인
        if (canCoverWithBoards(mid)) {
            ans = mid; // 덮을 수 있다면 현재 길이가 가능한 답
            high = mid - 1; // 더 짧은 길이로도 덮을 수 있는지 확인
        } else {
            low = mid + 1; // 덮을 수 없다면 더 긴 길이로 탐색
        }
    }

    cout << ans << "\n"; // 판자의 최소 길이 출력
    return 0;
}

