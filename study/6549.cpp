#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<long long> n;
vector<int> segTree;
int N;

// 세그먼트 트리 초기화: 최소 높이의 인덱스를 저장
int init(int node, int st, int ed){
    if(st == ed) return segTree[node] = st;

    int mid = (st + ed) / 2;
    int lIdx = init(node*2, st, mid);
    int rIdx = init(node*2+1, mid+1, ed);

    return segTree[node] = (n[lIdx] < n[rIdx] ? lIdx : rIdx);
}

// 주어진 구간에서 최소 높이의 인덱스를 반환
int query(int node, int st, int ed, int left, int right){
    if(ed < left || right < st) return -1;
    if(left <= st && ed <= right) return segTree[node];

    int mid = (st + ed) / 2;
    int lIdx = query(node*2, st, mid, left, right);
    int rIdx = query(node*2+1, mid+1, ed, left, right);

    if(lIdx == -1) return rIdx;
    if(rIdx == -1) return lIdx;
    return n[lIdx] < n[rIdx] ? lIdx : rIdx;
}

// Divide and Conquer로 최대 직사각형 넓이 계산
long long getMaxArea(int left, int right){
    if(left > right) return 0;

    int minIdx = query(1, 0, N-1, left, right);
    long long area = (long long)(right - left + 1) * n[minIdx];

    long long leftArea = getMaxArea(left, minIdx - 1);
    long long rightArea = getMaxArea(minIdx + 1, right);

    return max({area, leftArea, rightArea});
}

int main(){
    First

    while(true){
        cin >> N;
        if(N == 0) break;

        n.resize(N);
        segTree.assign(4*N, 0);

        for(int i=0; i<N; i++){
            cin >> n[i];
        }

        init(1, 0, N-1);

        cout << getMaxArea(0, N-1) << "\n";

        n.clear();
        segTree.clear();
    }
}
