//
// Created by 김헌우 on 2023/07/07.
//
#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];
int num[10];

void func(int k){ // 현재 k개까지 수를 택했음.
    if(k == m){ // m개를 모두 택했으면
        for(int i = 0; i < m; i++)
            cout << num[arr[i]] << ' '; // arr에 기록해둔 수를 출력
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){ // 1부터 n까지의 수에 대해
        if(!isused[i]){ // 아직 i가 사용되지 않았으면(isused가 false일때 실행)
            arr[k] = i; // k번째 수를 i로 정함
            isused[i] = 1; // i를 사용되었다고 표시, isused가 true
            func(k+1); // 다음 수를 정하러 한 단계 더 들어감
            isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 명시함, isused가 false
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i <n; i++){
        cin >> num[i];
    }
    sort(num,num+n);
    func(0);
}