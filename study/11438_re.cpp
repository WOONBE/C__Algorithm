#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M;
vector<int> v[100001]; //트리
bool visited[100001]; //방문여부
int d[100001]; //depth
int p[100001][18]; //부모 저장[i][j] : i노드의 2^^j 부모

//1. bfs 작성
void bfs(int x){
    queue<int> q;
    visited[x] = true;
    q.push(x);

    while(!q.empty()){
        x = q.front(); q.pop();
        for(int nxt : v[x]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            d[nxt] = d[x] + 1;
            p[nxt][0] = x; //이부분 놓침
            q.push(nxt);
        }
    }
}

int lcs(int x, int y){
    //x가 더 깊은곳에 있어야한다
    if(d[x] < d[y]){
        swap(x,y);
    }
    //높이를 동일하게 맞춰줌
    for(int i=16; i>=0; i--){
        if(d[x] - (1<<i) >= d[y]) {
            x = p[x][i];
        }
    }
    //일직선에 있을때
    if(x==y) return x;

    for(int i=16; i>=0; i--){
        if(p[x][i] != p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}
int main(){
    First


    cin >> N;
    for(int i=1; i<N; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);

    //2. sparse 작성
    for(int j=1; (1<<j) < N; j++){
        for(int i=1; i<=N; i++){
            if(p[i][j-1] != 0){
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }

    cin >> M;
    while(M--){
        int a,b;
        cin >> a >> b;
        cout << lcs(a,b) << "\n";
    }

}