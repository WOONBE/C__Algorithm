#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int K,N;
int num[101];
priority_queue<long long ,vector<long long >, greater<>> pq;
int main(){
    First
    cin >> K >> N;

    for(int i=0; i<K; i++){
        cin >> num[i];
        pq.push(num[i]);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = pq.top(); // 현재 가장 작은 수
        pq.pop(); // 사용했으므로 제거

        for (int j = 0; j < K; j++)
        {
            long long value = ans * num[j]; // 현재 수에 소수를 곱해 새로운 수 생성
            pq.push(value);

            if (ans % num[j] == 0) {
                break;
            }
        }
    }

    cout << ans;

}