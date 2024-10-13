#include <iostream>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int parent[100001];
int  G,P;
int Rank[100001];

int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    //현재 게이트보다 작은 게이트에 연결해줘야함
    if (x != y) {
        parent[y] = x;
    }

//    if(x == y){
//        return;
//    }
//    if (x != y) {
//        if (Rank[x] > Rank[y]) { // x 트리의 높이가 더 크면 y를 x에 병합
//            parent[y] = x;
//        } else if (Rank[x] < Rank[y]) { // y 트리의 높이가 더 크면 x를 y에 병합
//            parent[x] = y;
//        } else { // 높이가 같으면 y를 x에 병합하고, x의 트리 높이를 증가
//            parent[y] = x;
//            Rank[x]++;
//        }
//    }

}


int main(){
    First


    cin >> G;
    cin >> P;

    for(int i=1; i<=G; i++){
        parent[i] = i;
//        Rank[i] = 0;
    }
    int cnt=0;
    int plane;
    for(int i=0; i<P; i++){
        cin >> plane;

        int canDock = Find(plane);

        if(canDock == 0){
            break;
        }else{
            cnt++;
        }


        //자기보다 작은 번호의 게이트로 도킹하도록 설정
        Union(canDock -1, canDock);

    }

    //비행기 넣을때마다 cnt++
    cout << cnt << "\n";
    return 0;



}