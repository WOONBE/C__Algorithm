//
// Created by 김헌우 on 2024/09/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
int cal,a,b;
vector<int> parent;
vector<int> Rank;

//경로 단축 추가
int Find(int x){
    if (parent[x] == x) return x; //부모가 같아질때까지 찾음
    return parent[x] = Find(parent[x]);
}
//최대 높이 확인해서 합침
void Union(int x, int y){
    x = Find(x);
    y = Find(y);

//    if(x > y) parent[x] = y;
//    else parent[y] = x;

    if (x != y) parent[y] = x;
    if(x == y) return;

    if(Rank[x] < Rank[y]){ //작은 랭크의 부모를 큰 랭크로 설정
        parent[x] = y;
    }
    else if(Rank[x] > Rank[y]) {
        parent[y] = x;
    }
    else {
        if (Rank[x] == Rank[y]) {
            Rank[y]++; // 랭크가 같다면 합친 후에 랭크 증가
        }
    }
}

bool SameParent(int x, int y){
    return Find(x) == Find(y);
}

int main(){
    First

    cin >> N >> M;
    parent.resize(N+1,0);
    Rank.resize(N+1,0); //초기화
    for(int i=1; i<=N; i++){ //1부터 시작 안해서 터짐
        parent[i] = i;
    }


    for(int i=0; i<M; i++){
        cin >> cal >> a >> b;

        if(cal == 0){
            //union
            Union(a,b);
        }
        if(cal == 1){
            //find
            if(SameParent(a,b)){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
}
