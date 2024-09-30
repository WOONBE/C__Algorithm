//
// Created by 김헌우 on 2024/09/26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
long long N,H;
vector<long long> height;
vector<long long> line; // 각 구간의 장애물 갯수를 기록

void input(){
    cin >> N >> H;
    height.resize(N,0);
    line.resize(H+1, 0); // H+1 크기로 초기화 (0으로)
    for(long long i=0; i<N; i++){
        cin >> height[i];
    }
}

int main(){
    First
    input();

    // 1차원 배열로 구간별 장애물 수를 기록
    for(long long i=0; i<N; i++){
        if(i % 2 == 0){
            // 짝수 인덱스 (밑에서부터 깎아 나가는 장애물)
            line[0] += 1; // 시작 지점에 +1
            if(height[i] < H) line[height[i]] -= 1; // 끝 지점에 -1
        } else {
            // 홀수 인덱스 (위에서부터 깎아 나가는 장애물)
            line[H - height[i]] += 1; // 시작 지점에 +1
        }
    }

    // 누적합 계산
    for(long long i=1; i<H; i++){
        line[i] += line[i-1];
    }

    // 최소값과 그 개수를 계산
    long long min_value = *min_element(line.begin(), line.begin() + H);
    long long min_cnt = count(line.begin(), line.begin() + H, min_value);

    cout << min_value << ' ' << min_cnt << "\n";
}

