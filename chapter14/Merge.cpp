//
// Created by 김헌우 on 2023/07/11.
//11728 merge sort 구현, 이미 sort된 게 전제임


#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005], b[1000005], c[2000005]; //c는 합한 배열

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int aidx = 0, bidx = 0;
    for(int i = 0; i < n+m; i++){
        if(bidx == m) c[i] = a[aidx++]; //b 끝났으면 a값만 in
        else if(aidx == n) c[i] = b[bidx++];//위와 반대
        else if(a[aidx] <= b[bidx]) c[i] = a[aidx++]; //더 작은값을 in
        else c[i] = b[bidx++];// 위와 반대
    }
    for(int i = 0; i < n+m; i++) cout << c[i] << ' ';
}


